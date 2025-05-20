//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n, ret;
    char *ip_addr = "192.168.1.1";
    char *data = "PING";
    struct sockaddr_in server_addr;
    struct timeval timeout;

    if (argc < 3) {
        printf("Usage: %s <IP address> <timeout in seconds>\n", argv[0]);
        exit(1);
    }

    timeout.tv_sec = atoi(argv[2]);
    timeout.tv_usec = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7);
    inet_pton(AF_INET, ip_addr, &server_addr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        perror("connect");
        exit(1);
    }

    while (1) {
        send(sockfd, data, strlen(data), 0);
        n = recv(sockfd, data, MAX_DATA_SIZE, 0);
        if (n <= 0) {
            if (n == 0) {
                printf("Timeout!\n");
            } else {
                perror("recv");
            }
            break;
        }
        data[n] = '\0';
        printf("%s", data);
    }

    close(sockfd);
    return 0;
}