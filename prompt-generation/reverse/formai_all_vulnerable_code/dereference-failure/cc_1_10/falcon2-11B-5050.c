//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in servaddr;
    bzero((char *)&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));

    int addrlen = sizeof(servaddr);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address\n");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, addrlen) == -1) {
        perror("connect");
        return 1;
    }

    char buffer[1024];
    while (1) {
        bzero(buffer, sizeof(buffer));
        if (read(sockfd, buffer, sizeof(buffer)) == -1) {
            perror("read");
            return 1;
        }

        printf("%s\n", buffer);
        bzero(buffer, sizeof(buffer));
        if (write(sockfd, buffer, sizeof(buffer)) == -1) {
            perror("write");
            return 1;
        }

        if (strcmp(buffer, "quit") == 0) {
            break;
        }
    }

    close(sockfd);
    return 0;
}