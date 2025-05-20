//LLAMA2-13B DATASET v1.0 Category: Socket programming ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_CONNECTIONS 10
#define MAX_MESSAGE_LENGTH 1024

struct client_info {
    int sock;
    char ip_addr[INET_ADDRSTRLEN];
};

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(1234),
        .sin_addr.s_addr = INADDR_ANY
    };

    // Bind server address to socket
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock, MAX_CLIENT_CONNECTIONS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", server_addr.sin_port);

    while (1) {
        // Accept incoming connection
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Store client information
        struct client_info *client = (struct client_info *)malloc(sizeof(struct client_info));
        client->sock = client_sock;
        inet_ntop(AF_INET, &client_addr.sin_addr, client->ip_addr, INET_ADDRSTRLEN);

        // Handle client connections
        while (1) {
            char buffer[MAX_MESSAGE_LENGTH];
            int bytes_read = recv(client_sock, buffer, MAX_MESSAGE_LENGTH, 0);
            if (bytes_read < 0) {
                perror("recv failed");
                break;
            }

            // Print received message
            printf("Received message from %s: %s\n", client->ip_addr, buffer);

            // Send response
            char *message = "Hello, client!";
            int bytes_sent = send(client_sock, message, strlen(message), 0);
            if (bytes_sent < 0) {
                perror("send failed");
                break;
            }
        }

        // Close client socket
        close(client_sock);
    }

    return 0;
}