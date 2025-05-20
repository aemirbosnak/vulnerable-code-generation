//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PROXY_PORT 8080
#define BUFFER_SIZE 8192

void handle_client(int);

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, clilen, pid;
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PROXY_PORT);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    listen(sockfd, 5);
    printf("HTTP Proxy listening on port %d...\n", PROXY_PORT);
    clilen = sizeof(cli_addr);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("Error accepting client");
            exit(1);
        }

        pid = fork();
        if (pid < 0) {
            perror("Error forking process");
            exit(1);
        }

        if (pid == 0) {
            close(sockfd);
            handle_client(newsockfd);
            exit(0);
        } else {
            close(newsockfd);
        }
    }

    close(sockfd);
    return 0;
}

void handle_client(int client_sockfd) {
    int remote_sockfd, n;
    char buffer[BUFFER_SIZE];
    char request_buffer[BUFFER_SIZE];
    char *request;

    memset(buffer, 0, BUFFER_SIZE);
    n = recv(client_sockfd, buffer, BUFFER_SIZE-1, 0);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }

    printf("Received request from client:\n\n%s\n\n", buffer);

    // Extract the request line
    char *request_line = strtok(buffer, "\n");
    request = request_line;
    strcat(request, "\r\n");
    strcat(request, "Connection: close\r\n");
    strcat(request, buffer+strlen(request_line)+1);

    // Extract the host
    char *host = strstr(request_line, "Host: ");
    if (host == NULL) {
        perror("Error parsing host");
        exit(1);
    }
    host += 6;
    char *end_host = strchr(host, '\r');
    if (end_host == NULL) {
        perror("Error parsing host");
        exit(1);
    }
    *end_host = '\0';

    // Establish connection to remote server
    struct sockaddr_in remote_addr;
    bzero((char *)&remote_addr,sizeof(remote_addr));
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_port = htons(80);
    remote_addr.sin_addr.s_addr = inet_addr(host);

    remote_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (remote_sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    if (connect(remote_sockfd, (struct sockaddr *)&remote_addr, sizeof(remote_addr)) < 0) {
        perror("Error connecting to remote server");
        exit(1);
    }

    // Send the request to the remote server
    strcat(request_buffer, request);
    n = send(remote_sockfd, request_buffer, strlen(request_buffer), 0);
    if (n < 0) {
        perror("Error sending request to remote server");
        exit(1);
    }

    // Read response from remote server and send to client
    bzero(buffer,sizeof(buffer));
    while ((n = recv(remote_sockfd, buffer, BUFFER_SIZE-1, 0)) > 0) {
        n = send(client_sockfd, buffer, n, 0);
        if (n < 0) {
            perror("Error sending response to client");
            exit(1);
        }
        bzero(buffer,sizeof(buffer));
    }

    if (n < 0) {
        perror("Error reading response from remote server");
        exit(1);
    }

    close(remote_sockfd);
    close(client_sockfd);
}