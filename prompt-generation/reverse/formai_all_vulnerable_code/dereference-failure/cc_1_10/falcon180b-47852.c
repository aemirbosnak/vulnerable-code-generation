//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define MAX_HOST_LEN 64
#define MAX_DATA_LEN 1024
#define USAGE "Usage: %s <hostname>\n"

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, USAGE, argv[0]);
        exit(1);
    }

    char hostname[MAX_HOST_LEN];
    strncpy(hostname, argv[1], MAX_HOST_LEN - 1);
    hostname[MAX_HOST_LEN - 1] = '\0';

    int sockfd, ret;
    struct sockaddr_in serv_addr;
    char send_data[MAX_DATA_LEN];
    char recv_data[MAX_DATA_LEN];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, hostname, &serv_addr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret == -1) {
        perror("connect failed");
        exit(1);
    }

    sprintf(send_data, "PING\n");
    ret = send(sockfd, send_data, strlen(send_data), 0);
    if (ret == -1) {
        perror("send failed");
        exit(1);
    }

    memset(recv_data, 0, MAX_DATA_LEN);
    ret = recv(sockfd, recv_data, MAX_DATA_LEN, 0);
    if (ret == -1) {
        perror("recv failed");
        exit(1);
    }

    close(sockfd);

    if (strcmp(recv_data, "PONG") == 0) {
        printf("%s is alive!\n", hostname);
    } else {
        printf("%s is dead!\n", hostname);
    }

    return 0;
}