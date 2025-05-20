//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/telnet.h>

#define BRAVE_PORT_RANGE 1024  // brave port range
#define BRAVE_MAX_CONNECTIONS 10 // maximum number of connections

struct brave_connection {
    int sock;  // socket descriptor
    struct sockaddr_in server_addr;  // server address
    char buffer[1024];  // buffer for reading and writing
};

int brave_scan_port(int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    int status = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (status < 0) {
        perror("connect failed");
        return -1;
    }

    char buffer[1024];
    recv(sock, buffer, 1024, 0);
    close(sock);

    return 0;
}

int brave_scan(int start_port, int end_port) {
    int brave_ports = end_port - start_port + 1;
    struct brave_connection *connections = calloc(brave_ports, sizeof(struct brave_connection));

    for (int i = start_port; i <= end_port; i++) {
        if (brave_scan_port(i) == -1) {
            continue;
        }

        struct brave_connection *conn = connections + i - start_port;
        conn->sock = socket(AF_INET, SOCK_STREAM, 0);
        conn->server_addr.sin_family = AF_INET;
        conn->server_addr.sin_port = htons(i);
        conn->server_addr.sin_addr.s_addr = INADDR_ANY;

        int status = connect(conn->sock, (struct sockaddr *)&conn->server_addr, sizeof(conn->server_addr));
        if (status < 0) {
            perror("connect failed");
            close(conn->sock);
            continue;
        }

        char buffer[1024];
        recv(conn->sock, buffer, 1024, 0);
        close(conn->sock);
    }

    free(connections);

    return brave_ports;
}

int main() {
    int brave_ports = brave_scan(1024, 65535);
    printf("Brave ports found: %d\n", brave_ports);

    return 0;
}