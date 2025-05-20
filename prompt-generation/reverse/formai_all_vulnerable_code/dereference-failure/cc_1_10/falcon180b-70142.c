//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOSTNAME];
    strcpy(hostname, argv[1]);

    int sockfd, ret;
    struct sockaddr_in serv_addr;
    char send_data[MAX_DATA];
    char recv_data[MAX_DATA];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(7);
    ret = inet_pton(AF_INET, hostname, &serv_addr.sin_addr);
    if (ret <= 0) {
        printf("Invalid hostname\n");
        close(sockfd);
        return 1;
    }

    ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret == -1) {
        printf("Error connecting to host\n");
        close(sockfd);
        return 1;
    }

    int timeout_ms = TIMEOUT * 1000;
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout_ms, sizeof(timeout_ms));
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout_ms, sizeof(timeout_ms));

    strcpy(send_data, "PING");
    send(sockfd, send_data, strlen(send_data), 0);

    ret = recv(sockfd, recv_data, MAX_DATA, 0);
    if (ret <= 0) {
        printf("No response from host\n");
        close(sockfd);
        return 1;
    }

    if (strncmp(recv_data, "PONG", 4)!= 0) {
        printf("Invalid response from host\n");
        close(sockfd);
        return 1;
    }

    printf("Host is alive\n");
    close(sockfd);
    return 0;
}