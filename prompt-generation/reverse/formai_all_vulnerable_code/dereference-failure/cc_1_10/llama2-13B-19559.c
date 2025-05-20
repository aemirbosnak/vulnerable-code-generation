//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_CONNECTIONS 5
#define PORT 8888

struct client_info {
    int sock;
    char name[50];
};

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    listen(sock, 3);

    printf("Server started! Listening for incoming connections...\n");

    // Accept incoming connections
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);

        // Print the client's IP address and port
        printf("New client connection from IP address: %s, port: %d\n",
               inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Create a new client struct to store the client's information
        struct client_info *client = malloc(sizeof(struct client_info));
        client->sock = client_sock;

        // Read the client's name
        printf("Please enter your name: ");
        fgets(client->name, 50, stdin);

        // Send a welcome message to the client
        send(client->sock, "Hello, my dear client! Welcome to my server! 😊", 50, 0);

        // Loop until the client disconnects
        while (1) {
            char buffer[50];
            int bytes_read = recv(client->sock, buffer, 50, 0);

            // Print the client's message
            printf("Client says: %s\n", buffer);

            // Send a response back to the client
            send(client->sock, "You say: %s 😄", buffer, 0);

            // Check if the client has disconnected
            if (bytes_read < 0) {
                break;
            }
        }

        // Free the client struct
        free(client);
    }

    // Close the listening socket
    close(sock);

    return 0;
}