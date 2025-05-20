//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_HOSTNAME 256
#define BUF_SIZE 1024

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    char hostname[MAX_HOSTNAME];
    strncpy(hostname, argv[1], MAX_HOSTNAME - 1);
    hostname[MAX_HOSTNAME - 1] = '\0';

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7);

    int ret = inet_pton(AF_INET, hostname, &server_addr.sin_addr);
    if (ret <= 0) {
        printf("Error resolving hostname: %s\n", strerror(errno));
        close(sock);
        exit(1);
    }

    ret = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        printf("Error connecting to %s: %s\n", hostname, strerror(errno));
        close(sock);
        exit(1);
    }

    char send_buf[BUF_SIZE];
    strncpy(send_buf, "PING", BUF_SIZE - 1);
    send_buf[BUF_SIZE - 1] = '\0';

    ret = send(sock, send_buf, strlen(send_buf), 0);
    if (ret == -1) {
        printf("Error sending PING: %s\n", strerror(errno));
        close(sock);
        exit(1);
    }

    char recv_buf[BUF_SIZE];
    memset(recv_buf, 0, BUF_SIZE);

    ret = recv(sock, recv_buf, BUF_SIZE - 1, 0);
    if (ret <= 0) {
        printf("Error receiving response from %s\n", hostname);
        close(sock);
        exit(1);
    }

    printf("Response from %s: %s\n", hostname, recv_buf);

    close(sock);
    return 0;
}