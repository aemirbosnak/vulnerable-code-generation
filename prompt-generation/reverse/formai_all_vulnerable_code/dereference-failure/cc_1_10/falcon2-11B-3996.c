//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>

// Function prototypes
void error(const char *msg);
void* connect_to_server(const char *host, int port);

// Main function
int main(int argc, char *argv[]) {
    // Check if correct number of arguments provided
    if (argc!= 2) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    // Get host and port from command line arguments
    char* host = argv[1];
    int port = atoi(argv[2]);

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error("Error creating socket");
        return 1;
    }

    // Connect to server
    void* connection = connect_to_server(host, port);
    if (connection == NULL) {
        error("Error connecting to server");
        return 1;
    }

    // Send message to server
    char message[] = "Hello, server!";
    send(connection, message, sizeof(message), 0);

    // Receive response from server
    char response[100];
    int bytes_received = recv(connection, response, sizeof(response), 0);
    if (bytes_received < 0) {
        error("Error receiving response from server");
        return 1;
    }

    // Close connection
    close(connection);

    // Print received response
    printf("Server response: %s\n", response);

    // Cleanup
    close(sock);

    return 0;
}

// Function to handle errors
void error(const char *msg) {
    perror(msg);
    exit(1);
}

// Function to connect to server
void* connect_to_server(const char *host, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error("Error creating socket");
        return NULL;
    }

    struct hostent* server = gethostbyname(host);
    if (server == NULL) {
        error("Error getting host information");
        return NULL;
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    memcpy(&address.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sock, (struct sockaddr*)&address, sizeof(address)) < 0) {
        error("Error connecting to server");
        return NULL;
    }

    return sock;
}