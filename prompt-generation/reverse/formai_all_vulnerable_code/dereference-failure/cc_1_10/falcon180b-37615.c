//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <time.h>

#define MAX_HOST_LEN 1024
#define MAX_DATA_LEN 1024

#define QOS_MONITOR_PORT 8080

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    int opt = 1;
    int addrlen = sizeof(cli_addr);
    char host[MAX_HOST_LEN];
    char data[MAX_DATA_LEN];

    if (argc < 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    strcpy(host, argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(host);
    serv_addr.sin_port = htons(QOS_MONITOR_PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    printf("Connected to %s:%d\n", host, QOS_MONITOR_PORT);

    while (1) {
        memset(data, 0, sizeof(data));
        if (recv(sockfd, data, MAX_DATA_LEN, 0) <= 0) {
            perror("recv");
            exit(1);
        }

        printf("Received data: %s\n", data);
    }

    close(sockfd);
    return 0;
}