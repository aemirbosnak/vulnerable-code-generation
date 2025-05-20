//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        exit(1);
    }

    char *ip = argv[1];
    struct sockaddr_in server_addr;
    int sockfd, ret;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Failed to create socket: %s\n", strerror(errno));
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7);

    if (inet_pton(AF_INET, ip, &server_addr.sin_addr) <= 0) {
        printf("Invalid IP address: %s\n", ip);
        exit(1);
    }

    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        printf("Failed to connect to server: %s\n", strerror(errno));
        exit(1);
    }

    char buffer[1024];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        ret = read(sockfd, buffer, sizeof(buffer));
        if (ret <= 0) {
            printf("Failed to read from server: %s\n", strerror(errno));
            exit(1);
        }

        char *response = strtok(buffer, " ");
        if (!response) {
            printf("Invalid response from server\n");
            exit(1);
        }

        time_t now = time(NULL);
        struct tm *tm = localtime(&now);
        char timestamp[80];
        strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm);

        printf("%s - %s\n", response, timestamp);
    }

    close(sockfd);
    return 0;
}