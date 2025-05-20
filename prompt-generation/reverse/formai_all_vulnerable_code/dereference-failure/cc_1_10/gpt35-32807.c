//FormAI DATASET v1.0 Category: Networking ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

// Constants
#define MAX_CLIENTS 5
#define MESSAGE_SIZE 1024

// Global variables
int server_socket_fd;
int client_socket_fd[MAX_CLIENTS];
char message[MESSAGE_SIZE + 1];
socklen_t client_address_len[MAX_CLIENTS];
struct sockaddr_in server_address, client_address[MAX_CLIENTS];

// Function prototypes
void handle_connection(int client_id);
void sigint_handler(int sig);

int main(int argc, char *argv[])
{
    int i, client_id;
    fd_set readfds;

    // Ignore SIGPIPE to avoid termination on broken pipe
    signal(SIGPIPE, SIG_IGN);

    // Initialize server socket file descriptor
    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd == -1)
    {
        perror("Error creating server socket");
        exit(1);
    }

    // Initialize server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(atoi(argv[1]));

    // Bind server socket to server address
    if (bind(server_socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
    {
        perror("Error binding server socket to server address");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket_fd, MAX_CLIENTS) == -1)
    {
        perror("Error listening for incoming connections");
        exit(1);
    }

    printf("Server listening on port %d\n", atoi(argv[1]));

    // Setup signal handler for SIGINT (Ctrl+C) to cleanup resources
    signal(SIGINT, sigint_handler);

    // Loop to handle incoming client connections and messages
    while (1)
    {
        // Initialize file descriptor set and add server socket to it
        FD_ZERO(&readfds);
        FD_SET(server_socket_fd, &readfds);

        // Add all connected client sockets to the file descriptor set
        for (i = 0; i < MAX_CLIENTS; i++)
        {
            if (client_socket_fd[i] != 0)
            {
                FD_SET(client_socket_fd[i], &readfds);
            }
        }

        // Wait for activity on any of the file descriptors
        if (select(FD_SETSIZE, &readfds, NULL, NULL, NULL) == -1)
        {
            perror("Error waiting for activity on file descriptors");
            exit(1);
        }

        // Handle activity on server socket (new client connection)
        if (FD_ISSET(server_socket_fd, &readfds))
        {
            // Find a free slot for the new client socket file descriptor
            for (i = 0; i < MAX_CLIENTS; i++)
            {
                if (client_socket_fd[i] == 0)
                {
                    client_address_len[i] = sizeof(client_address[i]);
                    client_socket_fd[i] = accept(server_socket_fd, (struct sockaddr *)&client_address[i], &client_address_len[i]);
                    if (client_socket_fd[i] == -1)
                    {
                        perror("Error accepting new client connection");
                        exit(1);
                    }
                    printf("New client connection from %s:%d, assigned ID %d\n", inet_ntoa(client_address[i].sin_addr), ntohs(client_address[i].sin_port), i);
                    break;
                }
            }

            // If no free slot is found, reject the new client connection
            if (i == MAX_CLIENTS)
            {
                printf("New client connection rejected: maximum number of clients reached\n");
                close(accept(server_socket_fd, (struct sockaddr *)&client_address[i], &client_address_len[i]));
            }
        }

        // Handle activity on any of the connected client sockets (received message)
        for (i = 0; i < MAX_CLIENTS; i++)
        {
            if (client_socket_fd[i] != 0 && FD_ISSET(client_socket_fd[i], &readfds))
            {
                client_id = i;
                handle_connection(client_id);
            }
        }
    }

    return 0;
}

void handle_connection(int client_id)
{
    ssize_t message_size;

    // Receive message from client
    message_size = recv(client_socket_fd[client_id], message, MESSAGE_SIZE, 0);

    // If message is empty, client has disconnected
    if (message_size == 0)
    {
        printf("Client %d disconnected\n", client_id);
        close(client_socket_fd[client_id]);
        client_socket_fd[client_id] = 0;
        return;
    }

    // If message could not be received due to an error, log an error message
    if (message_size == -1)
    {
        perror("Error receiving message from client");
        close(client_socket_fd[client_id]);
        client_socket_fd[client_id] = 0;
        return;
    }

    // Terminate the message string
    message[message_size] = '\0';

    // Send received message to all connected clients (except sender)
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        if (i != client_id && client_socket_fd[i] != 0)
        {
            if (send(client_socket_fd[i], message, strlen(message), 0) == -1)
            {
                perror("Error sending message to client");
            }
        }
    }

    printf("Received message from client %d: %s", client_id, message);
}

void sigint_handler(int sig)
{
    printf("Exiting...\n");

    // Close all open client sockets
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        if (client_socket_fd[i] != 0)
        {
            close(client_socket_fd[i]);
        }
    }

    // Close server socket and exit
    close(server_socket_fd);
    exit(0);
}