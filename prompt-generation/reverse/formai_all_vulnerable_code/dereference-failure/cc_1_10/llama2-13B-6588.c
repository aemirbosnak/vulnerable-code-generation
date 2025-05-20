//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_LEN 1024
#define MAX_SERVER_LEN 2048

struct server_data {
    int sock;
    struct sockaddr_in server_addr;
    char server_name[MAX_SERVER_LEN];
};

struct client_data {
    int sock;
    struct sockaddr_in client_addr;
    char client_name[MAX_CLIENT_LEN];
};

int main() {
    int listen_sock;
    struct server_data server;
    struct client_data client;

    // Create a listening socket
    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("Error creating listening socket");
        exit(1);
    }

    // Set up the server address
    server.sock = listen_sock;
    server.server_addr.sin_family = AF_INET;
    server.server_addr.sin_addr.s_addr = INADDR_ANY;
    server.server_addr.sin_port = htons(8080);

    // Bind the server address to the socket
    if (bind(listen_sock, (struct sockaddr *)&server.server_addr, sizeof(server.server_addr)) < 0) {
        perror("Error binding server address");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(listen_sock, 5) < 0) {
        perror("Error listening for incoming connections");
        exit(1);
    }

    printf("Listening for incoming connections...\n");

    while (1) {
        // Accept an incoming connection
        client.sock = accept(listen_sock, (struct sockaddr *)NULL, NULL);
        if (client.sock < 0) {
            perror("Error accepting incoming connection");
            exit(1);
        }

        // Get the client address
        getpeername(client.sock, (struct sockaddr *)&client.client_addr, NULL);

        // Print the client address and wait for a message
        printf("Connected from %s\n", inet_ntoa(client.client_addr.sin_addr));
        char buffer[1024];
        recv(client.sock, buffer, 1024, 0);

        // Send a greeting message back to the client
        char *message = "Welcome, dear client! I am the romantic server. How may I assist you?";
        send(client.sock, message, strlen(message), 0);

        // Receive the client's message and print it
        recv(client.sock, buffer, 1024, 0);
        printf("Client says: %s\n", buffer);

        // Close the socket and free the client data
        close(client.sock);
        free(client.client_addr.sin_addr.s_addr);
        free(client.client_name);
    }

    return 0;
}