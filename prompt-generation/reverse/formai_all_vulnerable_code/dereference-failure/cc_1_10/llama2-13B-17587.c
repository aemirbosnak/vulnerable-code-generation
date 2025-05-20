//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define PORT_RANGE 1024-65535
#define MAX_CONN 1024

struct conn_info {
    int sock;
    struct sockaddr_in client_addr;
    char *client_ip;
    int established;
};

void init_conn(struct conn_info *conn) {
    conn->sock = -1;
    memset(&conn->client_addr, 0, sizeof(struct sockaddr_in));
    conn->client_ip = malloc(INET_ADDRSTRLEN);
}

void close_conn(struct conn_info *conn) {
    if (conn->sock != -1) {
        close(conn->sock);
        conn->sock = -1;
    }
    free(conn->client_ip);
}

int check_port(int port) {
    if (port < PORT_RANGE || port > PORT_RANGE) {
        return 0;
    }
    return 1;
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    struct conn_info conn;
    init_conn(&conn);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(struct sockaddr_in);
        int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);

        if (check_port(client_addr.sin_port)) {
            printf("Accepted connection from %s on port %d\n", client_ip, client_addr.sin_port);
            conn.sock = client_sock;
            conn.client_addr = client_addr;
            conn.client_ip = strdup(client_ip);
            conn.established = 1;
        } else {
            close(client_sock);
            printf("Rejected connection from %s on port %d\n", client_ip, client_addr.sin_port);
        }
    }

    return 0;
}