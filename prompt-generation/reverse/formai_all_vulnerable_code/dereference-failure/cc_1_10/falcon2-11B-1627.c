//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

void send_request(int sockfd, const char *url, const char *headers) {
    char buffer[1024];
    strcpy(buffer, "GET ");
    strcat(buffer, url);
    strcat(buffer, " HTTP/1.1\r\n");
    strcat(buffer, headers);
    strcat(buffer, "\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
}

void send_response(int sockfd, const char *status_code, const char *reason) {
    char buffer[1024];
    strcpy(buffer, "HTTP/1.1 ");
    strcat(buffer, status_code);
    strcat(buffer, " ");
    strcat(buffer, reason);
    strcat(buffer, "\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, clilen;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[1024];

    if (argc < 3) {
        printf("Usage: %s <proxy-port> <target-url>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);
    strcpy(buffer, argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    memset((char *) &servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(sockfd, 5);
    clilen = sizeof(cliaddr);

    while (1) {
        int cli_sockfd = accept(sockfd, (struct sockaddr *) &cliaddr, &clilen);
        if (cli_sockfd < 0) {
            perror("accept failed");
            exit(1);
        }

        char request[1024];
        recv(cli_sockfd, request, sizeof(request), 0);

        char *request_url = strtok(request, "\r\n");
        char *request_method = strtok(NULL, "\r\n");

        if (strcmp(request_method, "GET") == 0) {
            char headers[1024];
            send_request(sockfd, request_url, headers);
            char response[1024];
            recv(cli_sockfd, response, sizeof(response), 0);
            send_response(sockfd, "200 OK", "OK");
        } else {
            send_response(sockfd, "400 Bad Request", "Invalid request method");
        }

        close(cli_sockfd);
    }

    close(sockfd);
    return 0;
}