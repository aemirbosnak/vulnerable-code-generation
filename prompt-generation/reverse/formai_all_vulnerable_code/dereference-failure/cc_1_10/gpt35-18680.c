//FormAI DATASET v1.0 Category: Client Server Application ; Style: scientific
/*
 * This program demonstrates a simple scientific client-server application that
 * calculates the square root of a number provided by the client.
 *
 * Author: John Doe
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <math.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int serverSocket, clientSocket, portNumber;
    socklen_t clientAddressLength;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in serverAddress, clientAddress;

    if (argc < 2) {
        printf("Usage: %s port_number\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    portNumber = atoi(argv[1]);

    // Create server socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        perror("Error opening server socket");
        exit(EXIT_FAILURE);
    }

    // Initialize server address structure
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(portNumber);

    // Bind server socket to address
    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("Error binding server socket to address");
        exit(EXIT_FAILURE);
    }

    // Listen for client connections
    if (listen(serverSocket, 1) < 0) {
        perror("Error listening for client connections");
        exit(EXIT_FAILURE);
    }

    printf("Server started and listening on port %d\n", portNumber);

    while (1) {
        clientAddressLength = sizeof(clientAddress);

        // Accept client connection
        clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLength);
        if (clientSocket < 0) {
            perror("Error accepting client connection");
            exit(EXIT_FAILURE);
        }

        printf("Client connected\n");

        // Receive number from client
        if (recv(clientSocket, buffer, MAX_BUFFER_SIZE, 0) < 0) {
            perror("Error receiving number from client");
            exit(EXIT_FAILURE);
        }

        // Convert string to double
        double number = atof(buffer);

        printf("Received number from client: %f\n", number);

        // Calculate square root
        double result = sqrt(number);

        // Convert result to string
        char resultString[MAX_BUFFER_SIZE];
        snprintf(resultString, MAX_BUFFER_SIZE, "%f", result);

        // Send result to client
        if (send(clientSocket, resultString, strlen(resultString), 0) < 0) {
            perror("Error sending result to client");
            exit(EXIT_FAILURE);
        }

        printf("Sent result to client: %f\n", result);

        // Close client socket
        close(clientSocket);
    }

    // Close server socket
    close(serverSocket);

    return 0;
}