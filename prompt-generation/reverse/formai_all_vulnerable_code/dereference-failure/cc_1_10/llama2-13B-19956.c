//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define MAX_CONNS 1024
#define MAX_PACKET 1024

struct conn {
    int sock;
    struct sockaddr_in client_addr;
    char client_name[100];
};

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Allow connections from anywhere
    struct sockaddr_in bind_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
        .sin_addr.s_addr = INADDR_ANY
    };
    if (bind(sock, (struct sockaddr *)&bind_addr, sizeof(bind_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", bind_addr.sin_port);

    while (1) {
        // Accept an incoming connection
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("accept failed");
            continue;
        }

        // Print the client's IP address and port
        printf("New connection from %s:%d\n",
               inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Create a new connection structure
        struct conn *conn = malloc(sizeof(struct conn));
        conn->sock = client_sock;
        conn->client_addr = client_addr;
        strcpy(conn->client_name, "Unknown");

        // Handle incoming packets
        while (1) {
            char buffer[MAX_PACKET];
            int bytes_read = recv(client_sock, buffer, MAX_PACKET, 0);
            if (bytes_read < 0) {
                perror("recv failed");
                break;
            }

            // Check if the client sent a valid request
            if (strcmp(buffer, "HELLO") != 0) {
                printf("Invalid request from %s:%d\n",
                       inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                continue;
            }

            // Send a response back to the client
            char *message = "Hello, client!";
            send(client_sock, message, strlen(message), 0);

            // Update the client's name
            strcpy(conn->client_name, "Hello");
        }

        // Close the connection
        close(client_sock);
        free(conn);
    }

    return 0;
}