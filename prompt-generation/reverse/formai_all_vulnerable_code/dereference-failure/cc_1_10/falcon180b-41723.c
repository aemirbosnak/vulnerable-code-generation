//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024
#define WAIT_TIME 5

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOSTNAME];
    strncpy(hostname, argv[1], MAX_HOSTNAME - 1);
    hostname[MAX_HOSTNAME - 1] = '\0';

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7);

    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid hostname\n");
        close(sock);
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        close(sock);
        return 1;
    }

    char data[MAX_DATA];
    snprintf(data, MAX_DATA - 1, "PING %s\r\n", hostname);

    if (send(sock, data, strlen(data), 0) == -1) {
        perror("send");
        close(sock);
        return 1;
    }

    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(sock, &read_fds);

    struct timeval tv;
    tv.tv_sec = WAIT_TIME;
    tv.tv_usec = 0;

    if (select(sock + 1, &read_fds, NULL, NULL, &tv) <= 0) {
        fprintf(stderr, "Timeout\n");
        close(sock);
        return 1;
    }

    char buffer[MAX_DATA];
    int bytes_received = recv(sock, buffer, MAX_DATA - 1, 0);
    if (bytes_received <= 0) {
        fprintf(stderr, "No response from server\n");
        close(sock);
        return 1;
    }

    buffer[bytes_received] = '\0';
    printf("Response: %s", buffer);

    close(sock);
    return 0;
}