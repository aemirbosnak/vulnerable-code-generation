//FormAI DATASET v1.0 Category: Simple Web Server ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFFSIZE 2048

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, clientfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char request[BUFFSIZE], response[BUFFSIZE];

    if (argc < 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    memset((char *) &server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1])) ;

    if (bind(sockfd, (struct sockaddr *) &server_addr,
             sizeof(server_addr)) < 0)
        error("ERROR on binding");

    listen(sockfd, 5);

    while (1) {
        clientfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_len);
        if (clientfd < 0)
            error("ERROR on accept");

        memset(request, 0, BUFFSIZE);
        recv(clientfd, request, BUFFSIZE, 0);

        sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>C Simple Web Server Example</h1><p>Request: %s</p>", request);
        send(clientfd, response, strlen(response), 0);

        close(clientfd);
    }

    close(sockfd);
    return 0;
}