//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int listenfd, clientfd;
    struct sockaddr_in serv_addr, client_addr;
    int n;
    int opt = 1;
    char buffer[1024];

    if (argc < 2) {
        fprintf(stderr, "usage: %s port\n", argv[0]);
        exit(1);
    }

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listenfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(listenfd, 3) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        clientfd = accept(listenfd, (struct sockaddr *) &client_addr, (socklen_t *) &n);
        if (clientfd < 0) {
            perror("accept");
            continue;
        }

        printf("New connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            n = read(clientfd, buffer, 1024);
            if (n <= 0) {
                break;
            }
            buffer[n] = '\0';
            printf("%s", buffer);

            n = write(clientfd, buffer, strlen(buffer));
            if (n < 0) {
                perror("write");
                close(clientfd);
                break;
            }
        }

        close(clientfd);
    }

    close(listenfd);
    return 0;
}