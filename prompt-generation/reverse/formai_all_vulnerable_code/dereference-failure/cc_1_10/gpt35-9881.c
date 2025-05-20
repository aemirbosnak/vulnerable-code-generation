//FormAI DATASET v1.0 Category: Port Scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define TIMEOUT_SECONDS 1

int main(int argc, char *argv[]) {
    int sockfd, port, err;
    struct sockaddr_in target_addr;
    fd_set fds;
    struct timeval timeout;

    if (argc < 2) {
        printf("Usage: portscanner [ip]\n");
        return 1;
    }

    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket()");
        return 1;
    }

    FD_ZERO(&fds);
    FD_SET(sockfd, &fds);

    timeout.tv_sec = TIMEOUT_SECONDS;
    timeout.tv_usec = 0;

    for (port = 1; port <= MAX_PORTS; port++) {
        target_addr.sin_port = htons(port);
        err = connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr));

        if (err == 0) {
            printf("Port %d open\n", port);
        }

        if (err == -1 && FD_ISSET(sockfd, &fds)) {
            FD_CLR(sockfd, &fds);
            printf("Port %d closed\n", port);
        }

        FD_SET(sockfd, &fds);

        select(sockfd + 1, NULL, &fds, NULL, &timeout);
    }

    close(sockfd);

    return 0;
}