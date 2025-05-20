//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_HOSTNAME_LEN 256
#define MAX_DATA_LEN 64
#define TIME_OUT 5

int main(int argc, char *argv[])
{
    if (argc!= 2) {
        printf("Usage: %s hostname/IP\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOSTNAME_LEN];
    strcpy(hostname, argv[1]);

    printf("Pinging %s...\n", hostname);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7);

    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        printf("Invalid hostname/IP\n");
        close(sock);
        return 1;
    }

    char data[MAX_DATA_LEN] = "PING";
    send(sock, data, strlen(data), 0);

    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(sock, &read_fds);

    struct timeval tv;
    tv.tv_sec = TIME_OUT;
    tv.tv_usec = 0;

    int ret = select(sock + 1, &read_fds, NULL, NULL, &tv);

    if (ret == -1) {
        printf("Error with select: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    if (FD_ISSET(sock, &read_fds)) {
        char response[MAX_DATA_LEN];
        memset(response, 0, sizeof(response));
        int bytes_received = recv(sock, response, sizeof(response), 0);

        if (bytes_received <= 0) {
            printf("No response from server\n");
        } else {
            response[bytes_received] = '\0';
            printf("Response: %s\n", response);
        }
    } else {
        printf("Timeout\n");
    }

    close(sock);
    return 0;
}