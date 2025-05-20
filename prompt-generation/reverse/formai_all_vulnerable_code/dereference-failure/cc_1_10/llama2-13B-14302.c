//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_CONNECTIONS 10
#define PORT_RANGE 1024

struct client_info {
    int sock;
    char ip_address[INET_ADDRSTRLEN];
    uint16_t port;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <port_range>\n", argv[0]);
        return 1;
    }

    int port_range = atoi(argv[1]);
    if (port_range < 1 || port_range > PORT_RANGE) {
        printf("Invalid port range: %d\n", port_range);
        return 2;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        return 3;
    }

    struct client_info clients[MAX_CLIENT_CONNECTIONS];
    memset(clients, 0, sizeof(clients));

    int client_count = 0;
    while (1) {
        socklen_t client_len = sizeof(clients[0].ip_address);
        int client_sock = accept(sock, (struct sockaddr *)&clients[0].ip_address, &client_len);
        if (client_sock < 0) {
            perror("accept failed");
            break;
        }

        clients[client_count].sock = client_sock;
        clients[client_count].port = ntohs(clients[0].port);
        client_count++;

        if (client_count >= MAX_CLIENT_CONNECTIONS) {
            break;
        }
    }

    for (int i = 0; i < client_count; i++) {
        char ip_str[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &clients[i].ip_address, ip_str, sizeof(ip_str));
        printf("Client %d: %s:%d\n", i, ip_str, clients[i].port);
    }

    for (int i = 0; i < client_count; i++) {
        close(clients[i].sock);
    }

    close(sock);

    return 0;
}