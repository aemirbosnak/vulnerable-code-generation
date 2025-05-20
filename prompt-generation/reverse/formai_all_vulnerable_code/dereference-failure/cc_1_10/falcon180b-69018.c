//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_DATA_SIZE 1024
#define TIMEOUT_SEC 5
#define TIMEOUT_USEC 0

int main(int argc, char *argv[]) {
    int sock, ret;
    struct sockaddr_in server_addr;
    char data[MAX_DATA_SIZE];
    int data_len;
    int timeout_sec;
    int timeout_usec;
    struct timeval tv;

    if (argc!= 4) {
        printf("Usage: %s <IP address> <port> <timeout>\n", argv[0]);
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    server_addr.sin_port = htons(atoi(argv[2]));

    timeout_sec = atoi(argv[3]);
    timeout_usec = 0;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    ret = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    while (1) {
        memset(data, 0, MAX_DATA_SIZE);
        data_len = send(sock, "PING", strlen("PING"), 0);
        if (data_len <= 0) {
            printf("Error sending data: %s\n", strerror(errno));
            close(sock);
            return 1;
        }

        memset(data, 0, MAX_DATA_SIZE);
        data_len = recv(sock, data, MAX_DATA_SIZE, 0);
        if (data_len <= 0) {
            printf("Error receiving data: %s\n", strerror(errno));
            close(sock);
            return 1;
        }

        if (data_len == strlen("PONG")) {
            printf("Server is alive.\n");
            break;
        } else {
            printf("Server is not responding.\n");
        }

        close(sock);
    }

    return 0;
}