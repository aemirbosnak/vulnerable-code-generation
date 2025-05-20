//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    int sockfd, ret, count = 0;
    struct timeval tv;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    int opt = 1;

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error: Failed to create socket\n");
        exit(1);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Failed to connect to server\n");
        exit(1);
    }

    tv.tv_sec = 5;
    tv.tv_usec = 0;

    while (1) {
        ret = setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));
        if (ret < 0) {
            printf("Error: Failed to set timeout\n");
            exit(1);
        }

        ret = recv(sockfd, buffer, sizeof(buffer), 0);
        if (ret < 0) {
            printf("Error: Failed to receive data\n");
            exit(1);
        } else if (ret == 0) {
            printf("Connection closed by server\n");
            exit(1);
        }

        if (strncmp(buffer, "PING", 4) == 0) {
            count++;
            printf("Received %d PING packets\n", count);
        }
    }

    close(sockfd);
    return 0;
}