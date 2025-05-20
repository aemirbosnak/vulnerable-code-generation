//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void send_error(int sockfd, char* message) {
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "HTTP/1.1 404 Not Found\r\n\r\n%s", message);
    send(sockfd, buffer, strlen(buffer), 0);
}

void send_html(int sockfd, char* message) {
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "HTTP/1.1 200 OK\r\n\r\n%s", message);
    send(sockfd, buffer, strlen(buffer), 0);
}

void handle_connection(int sockfd) {
    char request[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    int len;

    while ((len = recv(sockfd, request, BUFFER_SIZE, 0)) > 0) {
        char *request_uri = strtok(request, " ");
        char *request_method = strtok(NULL, " ");

        if (strcmp(request_method, "GET") == 0) {
            if (strcmp(request_uri, "/") == 0) {
                strcpy(response, "HTTP/1.1 200 OK\r\n\r\nHello, world!");
            } else if (strcmp(request_uri, "/index.html") == 0) {
                strcpy(response, "HTTP/1.1 200 OK\r\n\r\n<html><body><h1>Welcome to the web server!</h1></body></html>");
            } else {
                send_error(sockfd, "File not found");
            }
        } else {
            send_error(sockfd, "Unsupported method");
        }

        send_html(sockfd, response);
    }
}

int main() {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    if (listen(sockfd, 3) < 0) {
        perror("ERROR on listen");
        exit(1);
    }

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &portno);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        handle_connection(newsockfd);
        close(newsockfd);
    }

    return 0;
}