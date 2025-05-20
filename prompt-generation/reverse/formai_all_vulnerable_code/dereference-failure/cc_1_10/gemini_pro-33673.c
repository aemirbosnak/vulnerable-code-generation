//GEMINI-pro DATASET v1.0 Category: Networking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Prepare a socket for listening on a given port.
int prepare_listening_socket(int port) {
    int sockfd;

    // Create a socket.
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the socket address.
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);

    // Bind the socket to the address.
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Set the socket to listen for incoming connections.
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Accept a connection from a client.
int accept_connection(int sockfd) {
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Accept a connection from a client.
    int client_sockfd;
    if ((client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Print some information about the connected client.
    char client_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);
    printf("Connected to client at %s:%d\n", client_ip, ntohs(client_addr.sin_port));

    return client_sockfd;
}

// Send a message to a client.
void send_message(int sockfd, const char *message) {
    // Send the message to the client.
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }
}

// Receive a message from a client.
char *receive_message(int sockfd) {
    // Allocate a buffer for the message.
    char *message = malloc(1024);

    // Receive the message from the client.
    if (recv(sockfd, message, 1023, 0) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Null-terminate the message.
    message[strlen(message)] = '\0';

    return message;
}

// Close a socket.
void close_socket(int sockfd) {
    // Close the socket.
    if (close(sockfd) < 0) {
        perror("close");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv) {
    // Check if the port was specified.
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Convert the port to an integer.
    int port = atoi(argv[1]);

    // Prepare a socket for listening on the given port.
    int sockfd = prepare_listening_socket(port);

    // Loop forever, accepting connections from clients.
    while (1) {
        // Accept a connection from a client.
        int client_sockfd = accept_connection(sockfd);

        // Send a welcome message to the client.
        send_message(client_sockfd, "Hello, world!\n");

        // Receive a message from the client.
        char *message = receive_message(client_sockfd);

        // Print the message to the console.
        printf("Received message: %s\n", message);

        // Free the message buffer.
        free(message);

        // Close the connection to the client.
        close_socket(client_sockfd);
    }

    // Close the listening socket.
    close_socket(sockfd);

    return 0;
}