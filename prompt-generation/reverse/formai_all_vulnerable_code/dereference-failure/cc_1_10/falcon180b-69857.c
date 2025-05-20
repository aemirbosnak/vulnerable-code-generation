//Falcon-180B DATASET v1.0 Category: Firewall ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_CONNECTIONS 1024
#define BUFFER_SIZE 1024

struct connection {
    int socket;
    char ip[INET6_ADDRSTRLEN];
    int port;
};

int main() {
    int server_socket = socket(AF_INET6, SOCK_STREAM, 0);
    struct sockaddr_in6 server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin6_family = AF_INET6;
    server_addr.sin6_port = htons(12345);
    inet_pton(AF_INET6, "::", &server_addr.sin6_addr);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding to port 12345.\n");
        return 1;
    }

    printf("Server started on port 12345.\n");

    int client_socket = accept(server_socket, NULL, NULL);
    struct sockaddr_in6 client_addr;
    socklen_t addr_size = sizeof(client_addr);
    if (getsockname(client_socket, (struct sockaddr*)&client_addr, &addr_size) == -1) {
        printf("Error getting client address.\n");
        return 1;
    }

    char client_ip[INET6_ADDRSTRLEN];
    inet_ntop(AF_INET6, &client_addr.sin6_addr, client_ip, sizeof(client_ip));
    int client_port = ntohs(client_addr.sin6_port);

    printf("Client connected from %s:%d.\n", client_ip, client_port);

    struct connection* connections = malloc(MAX_CONNECTIONS * sizeof(struct connection));
    int num_connections = 1;

    while (1) {
        char buffer[BUFFER_SIZE];
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Client disconnected.\n");
            close(client_socket);
            client_socket = -1;
            continue;
        }

        for (int i = 0; i < num_connections; i++) {
            if (connections[i].socket!= -1) {
                send(connections[i].socket, buffer, bytes_received, 0);
            }
        }
    }

    return 0;
}