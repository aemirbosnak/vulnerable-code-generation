//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <time.h>

#define MAX_DATA 1024
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char send_data[MAX_DATA];
    char recv_data[MAX_DATA];
    int opt = 1;
    int addrlen = sizeof(server_addr);
    int ret;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP address> <port>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Socket creation failed: %s\n", strerror(errno));
        return 1;
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    server_addr.sin_port = htons(atoi(argv[2]));

    ret = connect(sockfd, (struct sockaddr *)&server_addr, addrlen);
    if (ret == -1) {
        fprintf(stderr, "Connection failed: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    memset(send_data, 'A', MAX_DATA);
    send_data[MAX_DATA - 1] = '\0';

    ret = send(sockfd, send_data, MAX_DATA, 0);
    if (ret == -1) {
        fprintf(stderr, "Send failed: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    memset(recv_data, 0, MAX_DATA);
    ret = recv(sockfd, recv_data, MAX_DATA, 0);
    if (ret == -1) {
        fprintf(stderr, "Recv failed: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    printf("Recv data: %s\n", recv_data);
    close(sockfd);

    return 0;
}