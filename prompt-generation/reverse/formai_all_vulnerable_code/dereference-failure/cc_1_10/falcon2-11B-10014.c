//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {

    if (argc!= 3) {
        printf("Usage: %s <target> <count>\n", argv[0]);
        exit(1);
    }

    char target[100];
    int count = atoi(argv[2]);

    strncpy(target, argv[1], strlen(argv[1]));
    target[strlen(argv[1])] = '\0';

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("ERROR opening socket");
        exit(1);
    }

    struct sockaddr_in servaddr;
    memset((char *)&servaddr, '\0', sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);

    if (inet_pton(AF_INET, target, &servaddr.sin_addr) <= 0) {
        printf("ERROR, invalid address/port\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        printf("Ping %d\n", i);
        if (send(sockfd, "GET / HTTP/1.1\r\n\r\n", 32, 0) < 0) {
            perror("ERROR sending data");
            exit(1);
        }
        if (recv(sockfd, "HTTP/1.1 200 OK\r\n\r\n", 24, 0) < 0) {
            perror("ERROR receiving data");
            exit(1);
        }
        printf("Pong!\n");
        sleep(1);
    }

    close(sockfd);
    return 0;
}