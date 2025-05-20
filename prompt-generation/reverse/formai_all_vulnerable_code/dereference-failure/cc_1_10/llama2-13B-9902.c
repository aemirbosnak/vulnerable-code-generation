//LLAMA2-13B DATASET v1.0 Category: Socket programming ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_CONNECTIONS 10
#define MAX_MESSAGE_SIZE 1024

struct server_config {
    int port;
    int max_clients;
    int message_size;
};

struct client_config {
    int sock;
    int port;
    char address[INET_ADDRSTRLEN];
};

int main(int argc, char *argv[]) {
    struct server_config server_config;
    struct client_config client_config;

    // Parse command line arguments
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <server_port> <max_clients> <message_size>\n", argv[0]);
        return 1;
    }

    server_config.port = atoi(argv[1]);
    server_config.max_clients = atoi(argv[2]);
    server_config.message_size = atoi(argv[3]);

    // Create server socket
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("socket failed");
        return 1;
    }

    // Set server address and port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_config.port);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Bind server socket
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_sock, server_config.max_clients) < 0) {
        perror("listen failed");
        return 1;
    }

    // Accept incoming connections
    int client_sock;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    while ((client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len)) > 0) {
        // Set client address and port
        struct sockaddr_in *client_ptr = (struct sockaddr_in *)&client_addr;
        char client_address[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, client_ptr, client_address, sizeof(client_address));

        // Print client address and port
        printf("Client connected from %s port %d\n", client_address, ntohs(client_ptr->sin_port));

        // Receive message from client
        char message[MAX_MESSAGE_SIZE];
        recv(client_sock, message, MAX_MESSAGE_SIZE, 0);

        // Send response message to client
        char *message_ptr = message;
        int message_len = strlen(message);
        send(client_sock, message_ptr, message_len, 0);

        // Close client socket
        close(client_sock);
    }

    // Close server socket
    close(server_sock);

    return 0;
}