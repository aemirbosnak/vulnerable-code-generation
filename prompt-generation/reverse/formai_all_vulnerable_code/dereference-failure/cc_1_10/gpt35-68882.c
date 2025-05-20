//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

// Function to handle client requests
void handleClientRequest(int clientSocket)
{
    char buffer[MAX_BUFFER_SIZE];
    char request[MAX_BUFFER_SIZE];
    struct sockaddr_in serverAddress;
    int serverSocket, bytesRead, bytesWritten;
    socklen_t addrLen;

    // Read client request
    memset(buffer, 0, MAX_BUFFER_SIZE);
    bytesRead = read(clientSocket, buffer, MAX_BUFFER_SIZE - 1);

    if (bytesRead == -1) {
        perror("Error reading request from client\n");
        return;
    }

    // Get server, port, and request from client request
    sscanf(buffer, "GET http://%99[^:]:%99d/%99[^\n]", request, &serverAddress.sin_port, request);
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(request);

    // Create server socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (serverSocket == -1) {
        perror("Error creating server socket\n");
        return;
    }

    // Connect to server
    if (connect(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("Error connecting to server\n");
        return;
    }

    // Write client request
    bytesWritten = write(serverSocket, buffer, strlen(buffer));

    if (bytesWritten == -1) {
        perror("Error writing request to server\n");
        return;
    }

    // Read server response and write to client
    while ((bytesRead = read(serverSocket, buffer, MAX_BUFFER_SIZE - 1)) > 0) {
        bytesWritten = write(clientSocket, buffer, bytesRead);

        if (bytesWritten == -1) {
            perror("Error writing response to client\n");
            return;
        }

        memset(buffer, 0, MAX_BUFFER_SIZE);
    }

    // Close sockets
    close(clientSocket);
    close(serverSocket);
}

int main(int argc, char *argv[]) {
    int serverSocket, clientSocket, bytesWritten, opt = 1;
    struct sockaddr_in serverAddress, clientAddress;
    socklen_t addrLen = sizeof(clientAddress);

    // Check for valid port number
    if (argc != 2) {
        printf("Usage: ./simple_proxy <port>\n");
        return 1;
    }
    int port = atoi(argv[1]);

    // Create server socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (serverSocket == -1) {
        perror("Error creating server socket\n");
        return 1;
    }

    // Set socket options
    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Error setting socket options\n");
        return 1;
    }

    // Bind server socket
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);

    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("Error binding server socket\n");
        return 1;
    }

    // Listen for client connections
    if (listen(serverSocket, 5) == -1) {
        perror("Error listening for clients\n");
        return 1;
    }

    printf("Proxy listening on port %d...\n", port);

    // Handle client requests
    while (1) {
        clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &addrLen);

        if (clientSocket == -1) {
            perror("Error accepting client connection\n");
            continue;
        }

        printf("Accepted client connection from %s:%d\n", inet_ntoa(clientAddress.sin_addr), ntohs(clientAddress.sin_port));

        handleClientRequest(clientSocket);

        printf("Closed client connection from %s:%d\n", inet_ntoa(clientAddress.sin_addr), ntohs(clientAddress.sin_port));
    }

    return 0;
}