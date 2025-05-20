//FormAI DATASET v1.0 Category: Chat server ; Style: post-apocalyptic
// Post-Apocalyptic Chat Server
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Create a struct to hold client data
typedef struct {
    int socket;
    char name[20];
} client_t;

// Function to handle incoming messages
void handle_message(int sender_socket, char* message, client_t* clients, int num_clients) {
    for (int i = 0; i < num_clients; i++) {
        if (clients[i].socket == sender_socket) {
            continue;
        }
        char output_message[BUFFER_SIZE];
        snprintf(output_message, BUFFER_SIZE, "%s: %s", clients[i].name, message);
        send(clients[i].socket, output_message, strlen(output_message), 0);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s port\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Create server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set up server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[1]));
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind server address to socket
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }
    printf("Listening for incoming connections on port %s...\n", argv[1]);

    // Set up array to hold client data
    client_t clients[MAX_CLIENTS];
    fd_set client_fds;
    int num_clients = 0;
    char buffer[BUFFER_SIZE];

    while (true) {
        // Clear out client_fds and add server_socket
        FD_ZERO(&client_fds);
        FD_SET(server_socket, &client_fds);

        // Add all connected clients
        for (int i = 0; i < num_clients; i++) {
            FD_SET(clients[i].socket, &client_fds);
        }

        // Check if there is any activity on any of the sockets
        int activity = select(FD_SETSIZE, &client_fds, NULL, NULL, NULL);
        if (activity == -1) {
            perror("select");
            return EXIT_FAILURE;
        }

        // If activity is on server_socket, there is a new connection
        if (FD_ISSET(server_socket, &client_fds)) {
            // Accept new connection
            struct sockaddr_in client_address;
            socklen_t address_size = sizeof(client_address);
            int new_socket = accept(server_socket, (struct sockaddr*)&client_address, &address_size);
            if (new_socket == -1) {
                perror("accept");
                return EXIT_FAILURE;
            }

            // Add new client to array
            clients[num_clients].socket = new_socket;
            snprintf(clients[num_clients].name, 20, "Client-%d", num_clients+1);
            num_clients++;

            // Send welcome message to new client
            char welcome_message[] = "Welcome to the post-apocalyptic chat room!\n";
            send(new_socket, welcome_message, strlen(welcome_message), 0);

            // Print out information about new connection
            printf("New connection from %s:%d as %s\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port), clients[num_clients-1].name);
        }

        // Check all connected clients for activity
        for (int i = 0; i < num_clients; i++) {
            if (FD_ISSET(clients[i].socket, &client_fds)) {
                // Receive client message
                int valread = read(clients[i].socket, buffer, BUFFER_SIZE);
                if (valread <= 0) {
                    // Handle disconnected client
                    printf("%s has left the chat.\n", clients[i].name);
                    close(clients[i].socket);
                    clients[i].socket = -1;
                    continue;
                }

                // Handle incoming message
                buffer[valread] = '\0';
                handle_message(clients[i].socket, buffer, clients, num_clients);
            }
        }

        // Remove disconnected clients from array
        int num_removed = 0;
        for (int i = 0; i < num_clients; i++) {
            if (clients[i].socket == -1) {
                num_removed++;
                for (int j = i; j < num_clients - 1; j++) {
                    clients[j] = clients[j+1];
                }
            }
        }
        num_clients -= num_removed;
    }

    return EXIT_SUCCESS;
}