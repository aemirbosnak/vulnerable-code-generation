//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/telnet.h>

#define PORT_RANGE 1024
#define MAX_CONNECTIONS 50

struct host_info {
    char *host;
    int port;
};

struct connection {
    int sock;
    struct host_info *host_info;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        return 2;
    }

    struct host_info *host_info = malloc(sizeof(struct host_info));
    host_info->host = argv[1];
    host_info->port = 0;

    int port_range_start = 0;
    int port_range_end = PORT_RANGE;

    for (int i = port_range_start; i < port_range_end; i++) {
        struct connection *connection = malloc(sizeof(struct connection));
        connection->sock = socket(AF_INET, SOCK_STREAM, 0);
        if (connection->sock < 0) {
            perror("socket creation failed");
            continue;
        }

        int result = telnet_connect(connection, host_info);
        if (result == 0) {
            printf("Connected to %s on port %d\n", host_info->host, i);
            connection->host_info = host_info;
            host_info->port = i;
            break;
        } else if (result == -1) {
            perror("telnet_connect failed");
            close(connection->sock);
            free(connection);
            continue;
        }

        close(connection->sock);
        free(connection);
    }

    free(host_info);
    close(sock);

    return 0;
}

int telnet_connect(struct connection *connection, struct host_info *host_info) {
    char *host = host_info->host;
    int port = host_info->port;

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    if (connect(connection->sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        return -1;
    }

    return 0;
}