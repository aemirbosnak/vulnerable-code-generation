//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define MAX_PORTS 65535

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <port range>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[2]) + MAX_PORTS - 1;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(start_port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    int result = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (result < 0) {
        printf("Error connecting to %s:%d\n", ip, start_port);
        return 1;
    }

    printf("Scanning ports from %d to %d on %s...\n", start_port, end_port, ip);
    for (int port = start_port; port <= end_port; port++) {
        if (port == start_port) {
            char buffer[BUFFER_SIZE];
            memset(buffer, 0, sizeof(buffer));
            sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", ip);
            send(sock, buffer, strlen(buffer), 0);
        }

        char response[BUFFER_SIZE];
        memset(response, 0, sizeof(response));
        int bytes_received = recv(sock, response, BUFFER_SIZE, 0);
        if (bytes_received > 0) {
            printf("%d: Open\n", port);
        } else {
            printf("%d: Closed\n", port);
        }
    }

    close(sock);
    return 0;
}