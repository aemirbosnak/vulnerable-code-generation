//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_CONNECTIONS 10
#define BUFFER_SIZE 1024

struct client_info {
    int sock;
    char ip_addr[INET_ADDRSTRLEN];
};

int main(void) {
    int listen_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];
    struct client_info clients[MAX_CLIENT_CONNECTIONS];
    int i, j;

    // Create the listen socket
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) {
        perror("socket failed");
        exit(1);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // Bind the listen socket to the address and port
    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(listen_fd, MAX_CLIENT_CONNECTIONS) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Listening for incoming connections...\n");

    while (1) {
        // Accept an incoming connection
        client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_len);
        if (client_fd < 0) {
            perror("accept failed");
            continue;
        }

        // Print the client's IP address and port
        printf("Client connected from IP address %s port %d\n",
               inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Create a new client structure to store the client's information
        struct client_info *new_client = (struct client_info *)malloc(sizeof(struct client_info));
        new_client->sock = client_fd;
        inet_pton(AF_INET, &client_addr.sin_addr, new_client->ip_addr);

        // Add the new client to the list of connected clients
        for (i = 0; i < MAX_CLIENT_CONNECTIONS - 1; i++) {
            if (strcmp(clients[i].ip_addr, new_client->ip_addr) != 0) {
                break;
            }
        }
        clients[i].sock = new_client->sock;
        strcpy(clients[i].ip_addr, new_client->ip_addr);

        // Handle incoming data from the client
        while (1) {
            recv(client_fd, buffer, BUFFER_SIZE, 0);
            if (buffer[0] == '\0') {
                break;
            }
            printf("Received message from client: %s\n", buffer);
            // Send a response back to the client
            send(client_fd, "Hello, client!", 13, 0);
        }

        // Close the client connection
        close(client_fd);
    }

    return 0;
}