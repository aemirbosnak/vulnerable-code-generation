//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: portable
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
    struct sockaddr_in client_addr;
    char client_name[50];
};

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up the address structure
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(8080),
    };

    // Bind the socket to the address and port
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock, MAX_CLIENT_CONNECTIONS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening for incoming connections...\n");

    while (1) {
        // Accept an incoming connection
        int client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Get the client address and port
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        getpeername(client_sock, (struct sockaddr *)&client_addr, &client_addr_len);

        // Print the client information
        printf("Client connecting from IP address %s on port %d\n",
               inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Create a new client structure
        struct client_info *client = malloc(sizeof(struct client_info));
        client->sock = client_sock;
        client->client_addr = client_addr;
        strcpy(client->client_name, "Unknown");

        // Loop over the client connections and print their information
        for (int i = 0; i < MAX_CLIENT_CONNECTIONS; i++) {
            if (client->client_name[i] != '\0') {
                // Print the client name and port
                printf("Client %d: %s (%d)\n", i, client->client_name, ntohs(client->client_addr.sin_port));
            }
        }

        // Close the client socket
        close(client_sock);
    }

    // Close the server socket
    close(sock);

    return 0;
}