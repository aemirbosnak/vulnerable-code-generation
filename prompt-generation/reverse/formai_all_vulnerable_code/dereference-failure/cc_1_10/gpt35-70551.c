//FormAI DATASET v1.0 Category: Networking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 9001
#define BUFFER_SIZE 1024

void handle_client(int client_socket_fd, struct sockaddr_in client_address);
char* get_ip_str(const struct sockaddr *sa);

int main(int argc, char *argv[])
{
    int server_socket_fd, client_socket_fd, optval;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);

    // Create server socket
    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd < 0)
    {
        perror("Error opening server socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options to reuse port
    optval = 1;
    setsockopt(server_socket_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    // Bind server socket to PORT
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0)
    {
        perror("Error binding server socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket_fd, 5) < 0)
    {
        perror("Error listening on server socket");
        exit(EXIT_FAILURE);
    }

    printf("Happy Networking Example Server started on port %d...\n", PORT);

    // Accept incoming client connections
    while (true)
    {
        client_socket_fd = accept(server_socket_fd, (struct sockaddr *) &client_address, &client_address_len);
        if (client_socket_fd < 0)
        {
            perror("Error accepting client connection");
            continue;
        }

        printf("Handling client connection from %s...\n", get_ip_str((struct sockaddr *) &client_address));

        // Create child process to handle client connection
        if (fork() == 0)
        {
            // Child process
            close(server_socket_fd);
            handle_client(client_socket_fd, client_address);
            close(client_socket_fd);
            exit(EXIT_SUCCESS);
        }
        else
        {
            // Parent process
            close(client_socket_fd);
        }
    }

    return 0;
}

void handle_client(int client_socket_fd, struct sockaddr_in client_address)
{
    char buffer[BUFFER_SIZE];

    // Read message from client
    memset(buffer, 0, BUFFER_SIZE);
    if (read(client_socket_fd, buffer, BUFFER_SIZE) < 0)
    {
        perror("Error reading from client");
    }

    printf("Received message from %s: %s\n", get_ip_str((struct sockaddr *) &client_address), buffer);

    // Send reply to client
    char reply[BUFFER_SIZE] = "Hello from Happy Networking Example Server!";
    if (write(client_socket_fd, reply, strlen(reply)) < 0)
    {
        perror("Error writing to client");
    }

    printf("Sent reply to %s: %s\n", get_ip_str((struct sockaddr *) &client_address), reply);
}

char* get_ip_str(const struct sockaddr *sa)
{
    char *s = malloc(INET_ADDRSTRLEN);
    switch(sa->sa_family)
    {
        case AF_INET:
            inet_ntop(AF_INET, &(((struct sockaddr_in*)sa)->sin_addr), s, INET_ADDRSTRLEN);
            break;

        case AF_INET6:
            inet_ntop(AF_INET6, &(((struct sockaddr_in6*)sa)->sin6_addr), s, INET_ADDRSTRLEN);
            break;

        default:
            strcpy(s, "Unknown");
            break;
    }
    return s;
}