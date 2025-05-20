//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10
#define MAX_REQUEST_LENGTH 1024
#define RESPONSE_HEADER "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nConnection: close\r\n\r\n"

int main(int argc, char *argv[])
{
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    int opt = TRUE;
    int addrlen = sizeof(cliaddr);
    char buffer[MAX_REQUEST_LENGTH];

    if(argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd == -1) {
        perror("socket");
        exit(1);
    }

    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, sizeof(opt));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(atoi(argv[1]));

    if(bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind");
        exit(1);
    }

    if(listen(listenfd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    while(TRUE) {
        connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &addrlen);
        if(connfd == -1) {
            perror("accept");
            exit(1);
        }

        printf("Connection from %s\n", inet_ntoa(cliaddr.sin_addr));

        send(connfd, RESPONSE_HEADER, strlen(RESPONSE_HEADER), 0);
        close(connfd);
    }

    return 0;
}