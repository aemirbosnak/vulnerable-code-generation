//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Function prototypes
void usage(char* programName);
int setupClient(char* host, int port);
int setupServer(char* host, int port);
int sendData(int sockfd, char* buffer, int bufferSize);

int main(int argc, char *argv[])
{
    // Check for correct usage
    if (argc!= 3) {
        usage(argv[0]);
        return 1;
    }

    // Set up the client socket
    int clientSocket = setupClient(argv[1], atoi(argv[2]));
    if (clientSocket < 0) {
        fprintf(stderr, "Error setting up the client socket\n");
        return 1;
    }

    // Set up the server socket
    int serverSocket = setupServer(argv[1], atoi(argv[2]));
    if (serverSocket < 0) {
        fprintf(stderr, "Error setting up the server socket\n");
        return 1;
    }

    // Create a buffer to hold incoming data
    char buffer[1024];

    // Loop until the client wants to exit
    while (1) {
        // Send the data to the client
        if (sendData(clientSocket, "Welcome to the Simple HTTP Proxy!\n", 42) < 0) {
            fprintf(stderr, "Error sending data to the client\n");
            return 1;
        }

        // Receive the data from the client
        if (recv(clientSocket, buffer, sizeof(buffer), 0) < 0) {
            fprintf(stderr, "Error receiving data from the client\n");
            return 1;
        }

        // Send the data to the server
        if (sendData(serverSocket, buffer, strlen(buffer)) < 0) {
            fprintf(stderr, "Error sending data to the server\n");
            return 1;
        }

        // Receive the data from the server
        if (recv(serverSocket, buffer, sizeof(buffer), 0) < 0) {
            fprintf(stderr, "Error receiving data from the server\n");
            return 1;
        }

        // Send the data to the client
        if (sendData(clientSocket, buffer, strlen(buffer)) < 0) {
            fprintf(stderr, "Error sending data to the client\n");
            return 1;
        }

        // Close the sockets and exit the program
        if (close(serverSocket) < 0) {
            fprintf(stderr, "Error closing the server socket\n");
            return 1;
        }
        if (close(clientSocket) < 0) {
            fprintf(stderr, "Error closing the client socket\n");
            return 1;
        }
        break;
    }

    return 0;
}

// Usage function
void usage(char* programName)
{
    fprintf(stderr, "Usage: %s <host> <port>\n", programName);
    fprintf(stderr, "Example: %s example.com 8080\n", programName);
    fprintf(stderr, "Description: A simple HTTP proxy program\n");
    exit(1);
}

// Set up the client socket
int setupClient(char* host, int port)
{
    // Create the client socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        perror("Error creating the client socket");
        return -1;
    }

    // Set up the client socket address
    struct sockaddr_in clientAddr;
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_port = htons(port);
    clientAddr.sin_addr.s_addr = inet_addr(host);

    // Connect to the server
    if (connect(clientSocket, (struct sockaddr*)&clientAddr, sizeof(clientAddr)) < 0) {
        perror("Error connecting to the server");
        return -1;
    }

    return clientSocket;
}

// Set up the server socket
int setupServer(char* host, int port)
{
    // Create the server socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        perror("Error creating the server socket");
        return -1;
    }

    // Set up the server socket address
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(host);

    // Bind to the port
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Error binding to the port");
        return -1;
    }

    // Listen for connections
    if (listen(serverSocket, 1) < 0) {
        perror("Error listening for connections");
        return -1;
    }

    return serverSocket;
}

// Send data to the socket
int sendData(int sockfd, char* buffer, int bufferSize)
{
    // Send the data
    if (send(sockfd, buffer, bufferSize, 0) < 0) {
        perror("Error sending data to the socket");
        return -1;
    }

    return 0;
}