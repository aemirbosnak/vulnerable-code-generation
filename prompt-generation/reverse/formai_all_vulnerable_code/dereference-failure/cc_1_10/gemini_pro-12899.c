//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 1024

// Array of client sockets
int client_sockets[MAX_CONNECTIONS];
int num_clients = 0;

// Function to handle incoming connections
void handle_connection(int client_socket) {
    char buffer[BUFFER_SIZE];

    // Receive data from the client
    int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("recv");
        close(client_socket);
        return;
    }

    // Parse the data and check if it is a valid request
    char *command = strtok(buffer, " ");
    if (strcmp(command, "CONNECT") != 0) {
        // Invalid request. Send an error message to the client and close the connection.
        send(client_socket, "Invalid request\n", strlen("Invalid request\n"), 0);
        close(client_socket);
        return;
    }

    // Get the destination address and port
    char *destination_address = strtok(NULL, " ");
    char *destination_port = strtok(NULL, " ");

    // Create a new socket for the connection to the destination
    int destination_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (destination_socket < 0) {
        perror("socket");
        close(client_socket);
        return;
    }

    // Connect to the destination
    struct sockaddr_in destination_addr;
    memset(&destination_addr, 0, sizeof(destination_addr));
    destination_addr.sin_family = AF_INET;
    destination_addr.sin_addr.s_addr = inet_addr(destination_address);
    destination_addr.sin_port = htons(atoi(destination_port));
    if (connect(destination_socket, (struct sockaddr *)&destination_addr, sizeof(destination_addr)) < 0) {
        perror("connect");
        close(client_socket);
        close(destination_socket);
        return;
    }

    // Add the client socket and the destination socket to the array of client sockets
    client_sockets[num_clients] = client_socket;
    client_sockets[num_clients + 1] = destination_socket;
    num_clients += 2;

    // Fork a child process to handle the data transfer between the client and the destination
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        close(client_socket);
        close(destination_socket);
        return;
    } else if (pid == 0) {
        // Child process
        char buffer[BUFFER_SIZE];

        while (1) {
            // Receive data from the client
            int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if (bytes_received < 0) {
                perror("recv");
                exit(1);
            } else if (bytes_received == 0) {
                // Client closed the connection. Close the destination socket and exit.
                close(destination_socket);
                exit(0);
            }

            // Send the data to the destination
            if (send(destination_socket, buffer, bytes_received, 0) < 0) {
                perror("send");
                exit(1);
            }
        }
    } else {
        // Parent process
        char buffer[BUFFER_SIZE];

        while (1) {
            // Receive data from the destination
            int bytes_received = recv(destination_socket, buffer, BUFFER_SIZE, 0);
            if (bytes_received < 0) {
                perror("recv");
                exit(1);
            } else if (bytes_received == 0) {
                // Destination closed the connection. Close the client socket and exit.
                close(client_socket);
                exit(0);
            }

            // Send the data to the client
            if (send(client_socket, buffer, bytes_received, 0) < 0) {
                perror("send");
                exit(1);
            }
        }
    }
}

// Function to handle signals
void handle_signal(int sig) {
    int status;

    // Wait for all child processes to exit
    while (wait(&status) > 0);

    // Close all client sockets
    for (int i = 0; i < num_clients; i++) {
        close(client_sockets[i]);
    }

    // Exit the program
    exit(0);
}

int main() {
    int server_socket;
    struct sockaddr_in server_addr;

    // Create a new socket for the server
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        return 1;
    }

    // Set the server address and port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(54321);

    // Bind the socket to the server address and port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        close(server_socket);
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CONNECTIONS) < 0) {
        perror("listen");
        close(server_socket);
        return 1;
    }

    // Handle signals
    signal(SIGCHLD, handle_signal);

    // Main loop
    while (1) {
        // Accept a new connection
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }

        // Handle the connection in a separate thread
        handle_connection(client_socket);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}