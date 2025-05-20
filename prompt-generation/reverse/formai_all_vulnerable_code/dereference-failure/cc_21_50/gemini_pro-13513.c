//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_CLIENTS 5
#define MAX_SIZE_MSG 512

int main(int argc, char *argv[]) {
    int server_socket, client_sockets[MAX_CLIENTS], max_clients_connected, max_socket_descriptor, i, j, k;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length;
    char msg[MAX_SIZE_MSG], buffer[MAX_SIZE_MSG];
    fd_set read_fds, write_fds;

    // Create the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(atoi(argv[1]));

    // Bind the server socket to the server address
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Initialize the client sockets array
    for (i = 0; i < MAX_CLIENTS; i++) {
        client_sockets[i] = -1;
    }

    // Initialize the max_clients_connected variable
    max_clients_connected = 0;

    // Initialize the max_socket_descriptor variable
    max_socket_descriptor = server_socket;

    // Initialize the read_fds and write_fds file descriptor sets
    FD_ZERO(&read_fds);
    FD_ZERO(&write_fds);

    // Add the server socket to the read_fds file descriptor set
    FD_SET(server_socket, &read_fds);

    // Main loop
    while (1) {
        // Reset the read_fds and write_fds file descriptor sets
        read_fds = write_fds;

        // Select the ready file descriptors
        if (select(max_socket_descriptor + 1, &read_fds, &write_fds, NULL, NULL) < 0) {
            perror("select");
            exit(EXIT_FAILURE);
        }

        // Check if the server socket is ready for reading
        if (FD_ISSET(server_socket, &read_fds)) {
            // Accept a new connection
            client_address_length = sizeof(client_address);
            client_sockets[max_clients_connected] = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length);
            if (client_sockets[max_clients_connected] < 0) {
                perror("accept");
                exit(EXIT_FAILURE);
            }

            // Add the new client socket to the read_fds file descriptor set
            FD_SET(client_sockets[max_clients_connected], &read_fds);

            // Increment the max_clients_connected variable
            max_clients_connected++;

            // Update the max_socket_descriptor variable
            if (client_sockets[max_clients_connected] > max_socket_descriptor) {
                max_socket_descriptor = client_sockets[max_clients_connected];
            }

            // Send a welcome message to the new client
            strcpy(msg, "Welcome to the chat server!\n");
            if (write(client_sockets[max_clients_connected], msg, strlen(msg)) < 0) {
                perror("write");
                exit(EXIT_FAILURE);
            }
        }

        // Check if any of the client sockets are ready for reading
        for (i = 0; i < max_clients_connected; i++) {
            if (FD_ISSET(client_sockets[i], &read_fds)) {
                // Read a message from the client
                memset(buffer, 0, sizeof(buffer));
                if (read(client_sockets[i], buffer, MAX_SIZE_MSG) < 0) {
                    perror("read");
                    exit(EXIT_FAILURE);
                }

                // Check if the client has disconnected
                if (strlen(buffer) == 0) {
                    // Close the client socket
                    close(client_sockets[i]);

                    // Remove the client socket from the read_fds file descriptor set
                    FD_CLR(client_sockets[i], &read_fds);

                    // Decrement the max_clients_connected variable
                    max_clients_connected--;

                    // Update the max_socket_descriptor variable
                    if (client_sockets[max_clients_connected] > max_socket_descriptor) {
                        max_socket_descriptor = client_sockets[max_clients_connected];
                    }

                    // Send a message to the other clients that the client has disconnected
                    strcpy(msg, "Client has disconnected.\n");
                    for (j = 0; j < max_clients_connected; j++) {
                        if (write(client_sockets[j], msg, strlen(msg)) < 0) {
                            perror("write");
                            exit(EXIT_FAILURE);
                        }
                    }

                } else {
                    // Send the message to the other clients
                    for (j = 0; j < max_clients_connected; j++) {
                        if (j != i) {
                            if (write(client_sockets[j], buffer, strlen(buffer)) < 0) {
                                perror("write");
                                exit(EXIT_FAILURE);
                            }
                        }
                    }
                }
            }
        }
    }

    // Close the server socket
    close(server_socket);

    // Close the client sockets
    for (i = 0; i < max_clients_connected; i++) {
        close(client_sockets[i]);
    }

    return 0;
}