//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <strings.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }

    int sockfd, portno, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    int addrlen = sizeof(serv_addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    for (;;) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &addrlen);
        if (newsockfd < 0) {
            perror("accept");
            exit(1);
        }

        printf("New connection from %s\n", inet_ntoa(cli_addr.sin_addr));

        while (1) {
            char buf[256];
            int n = read(newsockfd, buf, sizeof(buf));
            if (n < 0) {
                perror("read");
                exit(1);
            }
            else if (n == 0) {
                printf("Connection closed by remote host\n");
                break;
            }
            else {
                printf("%s", buf);
            }
        }

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}