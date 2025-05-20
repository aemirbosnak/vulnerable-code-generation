//Falcon-180B DATASET v1.0 Category: Networking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10
#define MAXDATASIZE 1024

int main(int argc, char *argv[]) {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[MAXDATASIZE];
    int n;

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket failed");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(atoi(argv[1]));

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind failed");
        exit(1);
    }

    if (listen(listenfd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Server is listening on port %d\n", atoi(argv[1]));

    while (TRUE) {
        cliaddr.sin_family = AF_INET;
        cliaddr.sin_addr.s_addr = INADDR_ANY;
        cliaddr.sin_port = 0;
        socklen_t addrlen = sizeof(cliaddr);

        connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &addrlen);
        if (connfd == -1) {
            perror("accept");
            exit(1);
        }

        printf("Connection established with client\n");

        while (TRUE) {
            memset(buffer, 0, MAXDATASIZE);
            n = read(connfd, buffer, MAXDATASIZE);

            if (n <= 0) {
                if (n == 0) {
                    printf("Client disconnected\n");
                } else {
                    perror("read");
                }
                break;
            }

            printf("Received message from client: %s\n", buffer);

            write(connfd, buffer, strlen(buffer));
        }

        close(connfd);
    }

    close(listenfd);
    return 0;
}