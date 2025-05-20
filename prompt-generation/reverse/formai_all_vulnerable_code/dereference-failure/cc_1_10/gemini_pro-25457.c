//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind");
        return 1;
    }

    if (listen(sockfd, 5) == -1) {
        perror("listen");
        return 1;
    }

    while (1) {
        int connfd = accept(sockfd, (struct sockaddr *)NULL, NULL);
        if (connfd == -1) {
            perror("accept");
            continue;
        }

        char buf[1024];
        while (1) {
            int n = read(connfd, buf, sizeof(buf));
            if (n == -1) {
                perror("read");
                close(connfd);
                break;
            } else if (n == 0) {
                printf("Client disconnected\n");
                close(connfd);
                break;
            }

            write(connfd, buf, n);
        }
    }

    close(sockfd);
    return 0;
}