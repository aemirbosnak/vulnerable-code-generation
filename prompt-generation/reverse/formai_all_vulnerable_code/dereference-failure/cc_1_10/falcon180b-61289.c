//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_DATA_SIZE 1024
#define TRUE 1
#define FALSE 0
#define PING_INTERVAL 1

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char data[MAX_DATA_SIZE];
    int data_size;
    int opt = TRUE;
    int interval = PING_INTERVAL;
    char *ip_address;
    int port;
    struct timeval timeout;
    fd_set readfds;

    if (argc!= 4) {
        printf("Usage: %s <ip_address> <port> <interval>\n", argv[0]);
        exit(1);
    }

    ip_address = argv[1];
    port = atoi(argv[2]);
    interval = atoi(argv[3]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error: socket creation failed\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: connection failed\n");
        close(sockfd);
        exit(1);
    }

    while (opt) {
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);

        timeout.tv_sec = interval;
        timeout.tv_usec = 0;

        if (select(sockfd + 1, &readfds, NULL, NULL, &timeout) == -1) {
            printf("Error: select failed\n");
            close(sockfd);
            exit(1);
        }

        if (FD_ISSET(sockfd, &readfds)) {
            data_size = recv(sockfd, data, MAX_DATA_SIZE, 0);

            if (data_size == -1) {
                printf("Error: recv failed\n");
                close(sockfd);
                exit(1);
            }

            printf("Received data: %s\n", data);
        }
    }

    close(sockfd);
    exit(0);
}