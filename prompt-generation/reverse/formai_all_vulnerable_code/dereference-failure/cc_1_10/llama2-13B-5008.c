//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_CONNECTIONS 5
#define PORT_RANGE 1024

struct client_info {
    int sock;
    char IP[16];
    char name[16];
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <port_range>\n", argv[0]);
        return 1;
    }

    int port_range = atoi(argv[1]);
    struct client_info clients[MAX_CLIENT_CONNECTIONS];
    int client_count = 0;

    // Create sockets
    for (int i = 0; i < MAX_CLIENT_CONNECTIONS; i++) {
        clients[i].sock = socket(AF_INET, SOCK_STREAM, 0);
        if (clients[i].sock < 0) {
            perror("socket creation failed");
            exit(1);
        }
    }

    // Bind sockets to any address and port
    for (int i = 0; i < MAX_CLIENT_CONNECTIONS; i++) {
        struct sockaddr_in server_addr = {
            .sin_family = AF_INET,
            .sin_port = htons(0),
            .sin_addr.s_addr = INADDR_ANY
        };
        bind(clients[i].sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    }

    // Listen for incoming connections
    for (int i = 0; i < MAX_CLIENT_CONNECTIONS; i++) {
        listen(clients[i].sock, 3);
    }

    // Accept connections
    while (1) {
        for (int i = 0; i < MAX_CLIENT_CONNECTIONS; i++) {
            struct sockaddr_in client_addr;
            socklen_t client_len = sizeof(client_addr);
            int client_sock = accept(clients[i].sock, (struct sockaddr *)&client_addr, &client_len);
            if (client_sock < 0) {
                perror("accept() failed");
                exit(1);
            }
            // Store client information
            clients[i].sock = client_sock;
            inet_ntop(AF_INET, &client_addr.sin_addr, clients[i].IP, sizeof(clients[i].IP));
            strncpy(clients[i].name, inet_ntoa(client_addr.sin_addr), sizeof(clients[i].name));
            printf("Client connected: %s (%s)\n", clients[i].name, clients[i].IP);
        }
    }

    // Close sockets
    for (int i = 0; i < MAX_CLIENT_CONNECTIONS; i++) {
        close(clients[i].sock);
    }

    return 0;
}