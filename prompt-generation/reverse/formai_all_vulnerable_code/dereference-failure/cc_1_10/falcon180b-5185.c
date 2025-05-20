//Falcon-180B DATASET v1.0 Category: Firewall ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_CONNECTIONS 1000
#define BUFFER_SIZE 2048

struct connection {
    int sock;
    struct sockaddr_in addr;
};

struct connection *connections[MAX_CONNECTIONS];
int num_connections = 0;

void add_connection(int sock, struct sockaddr_in addr) {
    if (num_connections >= MAX_CONNECTIONS) {
        printf("Too many connections!\n");
        return;
    }
    struct connection *conn = malloc(sizeof(struct connection));
    conn->sock = sock;
    conn->addr = addr;
    connections[num_connections++] = conn;
}

void remove_connection(int sock) {
    for (int i = 0; i < num_connections; i++) {
        if (connections[i]->sock == sock) {
            close(sock);
            free(connections[i]);
            connections[i] = connections[num_connections - 1];
            num_connections--;
            return;
        }
    }
}

void handle_connection(int sock) {
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            remove_connection(sock);
            break;
        }
        printf("Received: %s\n", buffer);
    }
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "0.0.0.0", &server_addr.sin_addr);

    bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_sock, 10);

    while (1) {
        printf("Waiting for connection...\n");
        struct sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_len);
        if (client_sock == -1) {
            printf("Error accepting connection\n");
            continue;
        }
        add_connection(client_sock, client_addr);
        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, (void *)handle_connection, (void *)client_sock);
    }

    return 0;
}