//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct sockaddr_in dest_addr;
    struct timeval timeout;
    char *ip;
    int port;

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        exit(1);
    }

    ip = argv[1];
    port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &dest_addr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
    if (ret == -1) {
        printf("Error connecting to server\n");
        close(sockfd);
        exit(1);
    }

    timeout.tv_sec = 5;
    timeout.tv_usec = 0;
    ret = setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));
    if (ret == -1) {
        printf("Error setting socket timeout\n");
        close(sockfd);
        exit(1);
    }

    ret = send(sockfd, "PING", strlen("PING"), 0);
    if (ret == -1) {
        printf("Error sending ping packet\n");
        close(sockfd);
        exit(1);
    }

    ret = recv(sockfd, &dest_addr, sizeof(dest_addr), MSG_PEEK);
    if (ret == -1) {
        printf("Error receiving response\n");
        close(sockfd);
        exit(1);
    }

    if (dest_addr.sin_family!= AF_INET) {
        printf("Invalid response\n");
        close(sockfd);
        exit(1);
    }

    printf("Response received from %s:%d\n", inet_ntoa(dest_addr.sin_addr), ntohs(dest_addr.sin_port));

    close(sockfd);
    return 0;
}