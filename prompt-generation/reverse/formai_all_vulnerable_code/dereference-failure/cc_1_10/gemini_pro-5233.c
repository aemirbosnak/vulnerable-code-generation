//GEMINI-pro DATASET v1.0 Category: Networking ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

struct client_data {
    int client_socket;
    char *client_ip;
    int client_port;
};

int handle_client(struct client_data *client) {
    char buffer[1024];
    int bytes_received;

    // Receive data from the client
    bytes_received = recv(client->client_socket, buffer, 1024, 0);
    if (bytes_received < 0) {
        perror("Error receiving data from client");
        return -1;
    }

    // Print the data received from the client
    printf("Received %d bytes from client %s:%d\n", bytes_received, client->client_ip, client->client_port);
    printf("Data: %s\n", buffer);

    // Send data back to the client
    char *response = "Hello from the server!";
    int bytes_sent = send(client->client_socket, response, strlen(response), 0);
    if (bytes_sent < 0) {
        perror("Error sending data to client");
        return -1;
    }

    // Print the data sent to the client
    printf("Sent %d bytes to client %s:%d\n", bytes_sent, client->client_ip, client->client_port);

    // Close the client socket
    close(client->client_socket);

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Get the port number from the command line
    int port = atoi(argv[1]);

    // Create a server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating server socket");
        return 1;
    }

    // Set up the server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    // Bind the server socket to the server address
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error binding server socket");
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Error listening for incoming connections");
        return 1;
    }

    printf("Server listening on port %d\n", port);

    // Main loop: accept incoming connections and handle them
    while (1) {
        // Accept an incoming connection
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_len);
        if (client_socket < 0) {
            perror("Error accepting incoming connection");
            continue;
        }

        // Get the client's IP address and port number
        char *client_ip = inet_ntoa(client_address.sin_addr);
        int client_port = ntohs(client_address.sin_port);

        // Create a client data structure
        struct client_data client;
        client.client_socket = client_socket;
        client.client_ip = client_ip;
        client.client_port = client_port;

        // Handle the client in a separate thread
        pthread_t thread;
        pthread_create(&thread, NULL, (void *) handle_client, &client);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}