//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define MAX_CONN 1024
#define PORT 8080

struct conn {
    int sock;
    struct sockaddr_in cli_addr;
    char cli_ip[16];
    char cli_port[6];
};

void create_conn(struct conn *conn, int sock) {
    memset(conn, 0, sizeof(struct conn));
    conn->sock = sock;
}

void handle_connection(struct conn *conn) {
    char buffer[1024];
    int len = recv(conn->sock, buffer, 1024, 0);
    if (len > 0) {
        printf("Received message from %s:%s: %s\n",
            inet_ntoa(conn->cli_addr.sin_addr),
            conn->cli_port,
            buffer);
        send(conn->sock, "Hello, client!", 13, 0);
    }
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(1);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("binding failed");
        exit(1);
    }

    listen(sock, MAX_CONN);

    struct conn *conn = malloc(sizeof(struct conn));
    create_conn(conn, sock);

    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        handle_connection(conn);
        close(client_sock);
    }

    return 0;
}