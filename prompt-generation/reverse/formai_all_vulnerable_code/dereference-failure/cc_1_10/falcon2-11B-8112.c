//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

const int PORT = 1234;

// Server
void server() {
    int server_fd, new_connection, msg_len;
    struct sockaddr_in server_addr, client_addr;

    // Create a socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    // Prepare server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind the socket to the server address
    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket: %s\n", strerror(errno));
        exit(1);
    }

    // Listen for incoming connections
    listen(server_fd, 5);

    while (1) {
        // Accept a new connection
        new_connection = accept(server_fd, (struct sockaddr *) &client_addr, &msg_len);
        if (new_connection == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        // Receive messages from the client
        char buffer[256];
        ssize_t bytes_read;
        bytes_read = recv(new_connection, buffer, sizeof(buffer), 0);
        if (bytes_read == -1) {
            printf("Error receiving message: %s\n", strerror(errno));
            continue;
        }

        // Send a response back to the client
        send(new_connection, "Message received.\n", strlen("Message received.\n"), 0);

        // Close the connection
        close(new_connection);
    }
}

// Client
void client(const char *hostname, const char *port) {
    int client_fd, msg_len;
    struct sockaddr_in server_addr;

    // Create a socket
    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    // Prepare server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    // Connect to the server
    if (connect(client_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    // Send a message to the server
    char message[256];
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    send(client_fd, message, strlen(message), 0);

    // Receive a response from the server
    char response[256];
    ssize_t bytes_read;
    bytes_read = recv(client_fd, response, sizeof(response), 0);
    if (bytes_read == -1) {
        printf("Error receiving response: %s\n", strerror(errno));
        exit(1);
    }

    // Print the response
    printf("Server response: %s\n", response);

    // Close the connection
    close(client_fd);
}

int main() {
    char hostname[128];
    printf("Enter hostname: ");
    fgets(hostname, sizeof(hostname), stdin);
    char port[16];
    printf("Enter port: ");
    fgets(port, sizeof(port), stdin);

    client(hostname, port);

    return 0;
}