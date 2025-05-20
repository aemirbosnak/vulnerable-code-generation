//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_PORTS 65535

int main(int argc, char *argv[]) {
    int sockfd, port, max_sd;
    struct sockaddr_in target;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&target, 0, sizeof(target));

    target.sin_family = AF_INET;
    target.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &target.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&target, sizeof(target)) == -1) {
        printf("Error connecting to %s:%s\n", argv[1], argv[2]);
        exit(1);
    }

    printf("Connected to %s:%s\n", argv[1], argv[2]);

    for (port = 1; port <= MAX_PORTS; port++) {
        if (port == atoi(argv[2]))
            continue;

        target.sin_port = htons(port);

        if (sendto(sockfd, " ", 1, 0, (struct sockaddr *)&target, sizeof(target)) == -1) {
            printf("Port %d is closed\n", port);
            continue;
        }

        max_sd = socket(AF_INET, SOCK_STREAM, 0);

        if (max_sd == -1) {
            printf("Error creating socket\n");
            exit(1);
        }

        memset(&target, 0, sizeof(target));

        target.sin_family = AF_INET;
        target.sin_port = htons(port);
        target.sin_addr.s_addr = inet_addr(argv[1]);

        if (connect(max_sd, (struct sockaddr *)&target, sizeof(target)) == 0) {
            printf("Port %d is open\n", port);
            close(max_sd);
        } else {
            printf("Port %d is closed\n", port);
        }
    }

    close(sockfd);
    return 0;
}