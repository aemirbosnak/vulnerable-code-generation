//Gemma-7B DATASET v1.0 Category: Simple Web Server ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_CLIENT 10
#define BUFFER_SIZE 1024

// Define a configurable structure for each client connection
typedef struct ClientConnection {
    int clientSockfd;
    char clientName[256];
    struct ClientConnection* next;
} ClientConnection;

ClientConnection* head = NULL;

// Function to handle client connections
void handleClient(int clientSockfd) {
    // Allocate memory for a new client connection
    ClientConnection* newClient = malloc(sizeof(ClientConnection));
    newClient->clientSockfd = clientSockfd;
    snprintf(newClient->clientName, 256, "Client %d", clientSockfd);
    newClient->next = head;
    head = newClient;

    // Send a welcome message to the client
    write(clientSockfd, "Welcome to the server!", 23);

    // Receive a message from the client
    char message[BUFFER_SIZE];
    read(clientSockfd, message, BUFFER_SIZE);

    // Echo the message back to the client
    write(clientSockfd, message, strlen(message));

    // Close the client connection
    close(clientSockfd);

    // Free the memory allocated for the client connection
    free(newClient);
}

int main() {
    // Create a socket
    int serverSockfd = socket(AF_INET, SOCK_STREAM, htons(8080));

    // Bind the socket to a port
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    bind(serverSockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    // Listen for client connections
    int clientSockfd;
    while ((clientSockfd = accept(serverSockfd, NULL, NULL)) != -1) {
        handleClient(clientSockfd);
    }

    // Close the server socket
    close(serverSockfd);

    return 0;
}