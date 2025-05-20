//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        sockfd = accept(sockfd, NULL, NULL);
        if (sockfd < 0) {
            perror("accept");
            continue;
        }

        printf("Connection accepted from %s\n", inet_ntoa(serv_addr.sin_addr));

        char buf[256];
        bzero(buf, sizeof(buf));
        n = read(sockfd, buf, sizeof(buf));
        if (n < 0) {
            perror("read");
            continue;
        }

        printf("Received: %s\n", buf);

        bzero(buf, sizeof(buf));
        n = write(sockfd, buf, sizeof(buf));
        if (n < 0) {
            perror("write");
            continue;
        }

        printf("Sent: %s\n", buf);

        close(sockfd);
        break;
    }

    close(sockfd);
    exit(0);
}