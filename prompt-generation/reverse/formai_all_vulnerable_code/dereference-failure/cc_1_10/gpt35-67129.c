//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

void error(const char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[4096];
    if (argc < 2) {
        fprintf(stderr,"Usage: %s port_number\n", argv[0]);
        exit(1);
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR on binding");
    listen(sockfd,5);
    printf("Proxy server is running on port %d\n", portno);
    while(1) {
        socklen_t clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd,(struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            error("ERROR on accept");
        } else {
            printf("Client connected successfully.\n");
            pid_t pid = fork();
            if (pid < 0) {
                printf("Error forking child process.\n");
            } else if (pid == 0) {
                close(sockfd);
                char request_uri[4096], request_uri_path[4096], request_method[256], request_protocol[256];
                int n = read(newsockfd,buffer,4096);
                if (n < 0) {
                    error("ERROR reading from socket");
                }
                printf("Received %d bytes from client.\n", n);
                sscanf(buffer, "%s %s %s", request_method, request_uri, request_protocol);
                printf("Request: %s %s %s\n", request_method, request_uri, request_protocol);
                char* hostname = strtok(request_uri, "/");
                sprintf(request_uri_path, "/%s", strtok(NULL, ""));
                int port = 80;
                char* pHost = strtok(request_uri, ":");
                if (pHost != NULL) {
                    char* pPort = strtok(NULL, "/");
                    if (pPort != NULL) {
                        port = atoi(pPort);
                    }
                    hostname = pHost + 2;
                }
                struct hostent *server = gethostbyname(hostname);
                if (server == NULL) {
                    error("ERROR, no such host\n");
                }
                struct sockaddr_in serv_addr;
                bzero((char *) &serv_addr, sizeof(serv_addr));
                serv_addr.sin_family = AF_INET;
                bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
                serv_addr.sin_port = htons(port);
                int server_fd = socket(AF_INET, SOCK_STREAM, 0);
                if (server_fd < 0)
                    error("ERROR opening socket\n");
                if (connect(server_fd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
                    error("ERROR connecting");
                printf("Connected to remote server %s on port %d successfully.\n", hostname, port);
                n = write(server_fd, buffer, strlen(buffer));
                if (n < 0)
                    error("ERROR writing to socket");
                printf("Writing %d bytes to remote server.\n", n);
                bzero(buffer, 4096);
                n = read(server_fd, buffer, 4096);
                if (n < 0)
                    error("ERROR reading from socket");
                printf("Received %d bytes from remote server.\n", n);
                n = write(newsockfd, buffer, n);
                if (n < 0)
                    error("ERROR writing to socket");
                printf("Writing %d bytes to client.\n", n);
                close(newsockfd);
                printf("Closing client connection.\n");
                _exit(0);
            } else {
                close(newsockfd);
            }
        }
    }
    return 0;
}