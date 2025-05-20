//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024

void recScan(int sock, char *host, int start, int end);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <host> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        return 2;
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(0);
    inet_pton(AF_INET, argv[1], &server.sin_addr);

    bind(sock, (struct sockaddr *)&server, sizeof(server));
    listen(sock, 3);

    int client_sock = accept(sock, NULL, NULL);
    if (client_sock < 0) {
        perror("accept() failed");
        close(sock);
        return 3;
    }

    char buffer[1024];
    recScan(client_sock, argv[1], 0, PORT_RANGE);

    close(client_sock);
    close(sock);

    return 0;
}

void recScan(int sock, char *host, int start, int end) {
    if (start > end) {
        return;
    }

    char port_str[10];
    snprintf(port_str, 10, "%d", start);
    struct sockaddr_in port;
    port.sin_family = AF_INET;
    port.sin_port = htons(atoi(port_str));
    inet_pton(AF_INET, host, &port.sin_addr);

    int connect_res = connect(sock, (struct sockaddr *)&port, sizeof(port));
    if (connect_res < 0) {
        perror("connect() failed");
        return;
    }

    recScan(sock, host, start + 1, end);

    close(sock);
}