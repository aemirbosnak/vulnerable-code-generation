//GEMINI-pro DATASET v1.0 Category: Networking ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Custom error handling macro
#define ERROR(msg) { perror(msg); exit(EXIT_FAILURE); }

// Create a socket, bind it to an address and port, and listen for connections
int create_server_socket(const char *address, int port) {
    int sockfd;
    struct sockaddr_in servaddr;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        ERROR("socket");
    }

    // Clear the server address structure
    memset(&servaddr, 0, sizeof(servaddr));

    // Set the server address and port
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(address);
    servaddr.sin_port = htons(port);

    // Bind the socket to the address and port
    if (bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1) {
        ERROR("bind");
    }

    // Listen for connections
    if (listen(sockfd, 5) == -1) {
        ERROR("listen");
    }

    return sockfd;
}

// Accept a connection from a client
int accept_connection(int server_sockfd) {
    int client_sockfd;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Accept a connection from a client
    if ((client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_addr, &client_addr_len)) == -1) {
        ERROR("accept");
    }

    return client_sockfd;
}

// Send a message to a client
int send_message(int client_sockfd, const char *message) {
    int sent_bytes;

    // Send the message to the client
    if ((sent_bytes = send(client_sockfd, message, strlen(message), 0)) == -1) {
        ERROR("send");
    }

    return sent_bytes;
}

// Receive a message from a client
int receive_message(int client_sockfd, char *buffer, size_t buffer_size) {
    int received_bytes;

    // Receive a message from the client
    if ((received_bytes = recv(client_sockfd, buffer, buffer_size, 0)) == -1) {
        ERROR("recv");
    }

    return received_bytes;
}

// Close a socket
void close_socket(int sockfd) {
    close(sockfd);
}

int main(int argc, char **argv) {
    int server_sockfd, client_sockfd;
    char buffer[256];
    int received_bytes;

    // Check if the correct number of arguments have been provided
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a server socket
    server_sockfd = create_server_socket(argv[1], atoi(argv[2]));

    // Continuously accept connections from clients
    while (1) {
        // Accept a connection from a client
        client_sockfd = accept_connection(server_sockfd);

        // Receive a message from the client
        received_bytes = receive_message(client_sockfd, buffer, sizeof(buffer));

        // Check if the client has disconnected
        if (received_bytes == 0) {
            printf("Client disconnected\n");
            close_socket(client_sockfd);
            continue;
        }

        // Print the message from the client
        printf("Received message: %s\n", buffer);

        // Send a message to the client
        send_message(client_sockfd, "Hello world!\n");

        // Close the client socket
        close_socket(client_sockfd);
    }

    // Close the server socket
    close_socket(server_sockfd);

    return EXIT_SUCCESS;
}