//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <signal.h>

#define MAX_CONNECTIONS 10

int main(int argc, char** argv) {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    int port = 8080;
    char buffer[1024];

    if (argc == 2) {
        port = atoi(argv[1]);
    }

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    if (bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(listenfd, MAX_CONNECTIONS) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        int addrlen = sizeof(cliaddr);
        if ((connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &addrlen)) < 0) {
            perror("accept");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        int nread;
        while ((nread = read(connfd, buffer, sizeof(buffer))) > 0) {
            if (strstr(buffer, "HTTP/1.1 403") != NULL) {
                printf("Blocked request: %s", buffer);
                break;
            }
            else {
                printf("Allowed request: %s", buffer);
                write(connfd, buffer, nread);
            }
        }

        if (nread == 0) {
            printf("Connection closed by client\n");
        }

        close(connfd);
    }

    close(listenfd);

    return 0;
}