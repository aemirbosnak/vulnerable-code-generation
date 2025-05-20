//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

#define MAX_DATA_SIZE 1024
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct sockaddr_in server_addr;
    char data[MAX_DATA_SIZE];
    int datalen;
    struct timeval timeout;

    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    memset(data, 0, MAX_DATA_SIZE);
    datalen = snprintf(data, MAX_DATA_SIZE, "PING");

    ret = send(sockfd, data, datalen, 0);
    if (ret == -1) {
        printf("Error sending data\n");
        exit(1);
    }

    printf("Ping sent to server\n");

    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;

    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    ret = recv(sockfd, data, MAX_DATA_SIZE, 0);
    if (ret == -1) {
        if (errno == EAGAIN || errno == EWOULDBLOCK) {
            printf("No response from server\n");
        } else {
            printf("Error receiving data\n");
        }
        exit(1);
    }

    printf("Response from server: %s\n", data);

    close(sockfd);
    return 0;
}