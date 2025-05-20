//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024
#define TIME_OUT 5

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOSTNAME];
    strncpy(hostname, argv[1], MAX_HOSTNAME - 1);

    int port = atoi(argv[2]);

    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr))!= 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    char data[MAX_DATA];
    int data_len = strlen(argv[1]) + strlen(argv[2]) + 2;

    snprintf(data, MAX_DATA, "GET / HTTP/1.1\r\nHost: %s:%d\r\n\r\n", argv[1], port);

    send(sockfd, data, data_len, 0);

    struct timeval tv;
    tv.tv_sec = TIME_OUT;
    tv.tv_usec = 0;

    fd_set fds;
    FD_ZERO(&fds);

    FD_SET(sockfd, &fds);

    select(sockfd + 1, &fds, NULL, NULL, &tv);

    char response[MAX_DATA];
    memset(response, 0, MAX_DATA);

    int bytes_received = recv(sockfd, response, MAX_DATA, 0);

    if (bytes_received <= 0) {
        printf("No response from server\n");
        close(sockfd);
        return 1;
    }

    printf("Response:\n%s", response);

    close(sockfd);
    return 0;
}