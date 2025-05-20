//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define TRUE    1
#define FALSE   0
#define PORT    7
#define SA struct sockaddr

int main(int argc, char *argv[]) {
    int sockfd, ret, i, opt = TRUE;
    struct sockaddr_in serverAddr;
    char recvBuff[1024];
    fd_set readfds;
    struct timeval timeout;
    int maxfd;

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Timeout>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error opening socket\n");
        exit(1);
    }

    serverAddr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &serverAddr.sin_addr);
    serverAddr.sin_port = htons(PORT);

    if (connect(sockfd, (SA *)&serverAddr, sizeof(serverAddr)) == -1) {
        printf("Error connecting to %s\n", argv[1]);
        exit(1);
    }

    printf("Connected to %s\n", argv[1]);

    ret = setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
    if (ret == -1) {
        printf("Error setting timeout\n");
        exit(1);
    }

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    maxfd = sockfd;

    while (opt) {
        ret = select(maxfd + 1, &readfds, NULL, NULL, &timeout);
        if (ret == -1) {
            printf("Error with select\n");
            exit(1);
        }

        if (FD_ISSET(sockfd, &readfds)) {
            memset(recvBuff, 0, sizeof(recvBuff));
            ret = recv(sockfd, recvBuff, sizeof(recvBuff), 0);
            if (ret == 0) {
                printf("Connection closed by %s\n", argv[1]);
                opt = FALSE;
            } else if (ret == -1) {
                printf("Error receiving data\n");
                opt = FALSE;
            } else {
                printf("Received: %s", recvBuff);
            }
        }
    }

    close(sockfd);
    return 0;
}