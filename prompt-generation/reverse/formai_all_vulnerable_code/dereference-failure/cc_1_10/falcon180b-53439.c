//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX 100

int main(int argc, char *argv[]) {

    if (argc < 3) {
        printf("Usage: %s <IP Address> <Timeout>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int timeout = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Could not create socket\n");
        return 1;
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(7);
    inet_pton(AF_INET, ip, &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error: Could not connect to server\n");
        close(sock);
        return 1;
    }

    char buffer[MAX];
    int bytes_received = 0;

    send(sock, "PING", strlen("PING"), 0);

    while (bytes_received < MAX) {
        int bytes_read = recv(sock, buffer + bytes_received, MAX - bytes_received, 0);
        if (bytes_read == -1) {
            printf("Error: Could not receive data from server\n");
            close(sock);
            return 1;
        }
        if (bytes_read == 0) {
            printf("Error: Server did not respond\n");
            close(sock);
            return 1;
        }
        bytes_received += bytes_read;
    }

    close(sock);

    if (strncmp(buffer, "PONG", strlen("PONG")) == 0) {
        printf("Server is alive\n");
    } else {
        printf("Server did not respond\n");
    }

    return 0;
}