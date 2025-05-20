//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CONNECTIONS 10

int main(int argc, char** argv) {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket");
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(atoi(argv[1]));

    if (bind(listenfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) == -1) {
        perror("bind");
        return 1;
    }

    if (listen(listenfd, MAX_CONNECTIONS) == -1) {
        perror("listen");
        return 1;
    }

    printf("Server listening on port %d\n", atoi(argv[1]));

    while (1) {
        int clilen = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr*) &cliaddr, &clilen);
        if (connfd == -1) {
            perror("accept");
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        char buffer[1024];
        int bytes_read;
        while ((bytes_read = recv(connfd, buffer, sizeof(buffer), 0)) > 0) {
            buffer[bytes_read] = '\0';
            printf("Received: %s", buffer);

            char* response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello, world!</h1></body></html>\n";
            send(connfd, response, strlen(response), 0);
        }

        close(connfd);
    }

    close(listenfd);
    return 0;
}