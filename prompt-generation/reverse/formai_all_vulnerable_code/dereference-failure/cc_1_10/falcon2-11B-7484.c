//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    if (bind(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("bind");
        return 1;
    }

    if (listen(sockfd, 5) == -1) {
        perror("listen");
        return 1;
    }

    char buffer[1024];
    int clientfd, n;

    while (1) {
        clientfd = accept(sockfd, NULL, NULL);
        if (clientfd == -1) {
            perror("accept");
            continue;
        }

        while ((n = recv(clientfd, buffer, sizeof(buffer), 0)) > 0) {
            if (n == 0) {
                close(clientfd);
                break;
            }
            printf("Received: %s\n", buffer);
            send(clientfd, buffer, n, 0);
        }
        close(clientfd);
    }

    close(sockfd);
    return 0;
}