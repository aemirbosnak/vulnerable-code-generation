//FormAI DATASET v1.0 Category: Socket programming ; Style: modular
// A modular C program that demonstrates the usage of sockets in client-server communication.
// This program creates a server that listens to incoming connections and a client that sends messages to the server.

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

// Constants
#define BUFFER_SIZE 1024

// Function prototypes
int createServer(int port);
int createClient(char* host, int port);
void handleConnection(int socket);
void readFromSocket(int socket);

// Main function
int main(int argc, char* argv[]) {
    // Check arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }
    
    // Create server and client sockets
    int serverSocket = createServer(atoi(argv[2]));
    int clientSocket = createClient(argv[1], atoi(argv[2]));
    
    // Handle connections
    handleConnection(serverSocket);
    handleConnection(clientSocket);
    
    // Close sockets
    close(serverSocket);
    close(clientSocket);
    
    return 0;
}

// Create a server socket and start listening on the specified port
int createServer(int port) {
    // Create socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        perror("Error creating server socket");
        exit(1);
    }
    
    // Bind address
    struct sockaddr_in serverAddr;
    bzero((char*) &serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    if (bind(serverSocket, (struct sockaddr*) &serverAddr, sizeof(serverAddr)) < 0) {
        perror("Error binding server address");
        exit(1);
    }
    
    // Listen for incoming connections
    listen(serverSocket, 5);
    
    return serverSocket;
}

// Create a client socket and connect to the specified host and port
int createClient(char* host, int port) {
    // Get host information
    struct hostent* server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "Error finding host %s\n", host);
        exit(1);
    }
    
    // Create socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        perror("Error creating client socket");
        exit(1);
    }
    
    // Connect to server
    struct sockaddr_in serverAddr;
    bzero((char*) &serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &serverAddr.sin_addr.s_addr, server->h_length);
    serverAddr.sin_port = htons(port);
    if (connect(clientSocket, (struct sockaddr*) &serverAddr, sizeof(serverAddr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }
    
    return clientSocket;
}

// Handle incoming connections and read data from the socket
void handleConnection(int socket) {
    // Accept client connection
    struct sockaddr_in clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    int clientSocket = accept(socket, (struct sockaddr*) &clientAddr, &clientAddrLen);
    if (clientSocket < 0) {
        perror("Error accepting client connection");
        exit(1);
    }
    
    // Read data from socket
    readFromSocket(clientSocket);
    
    // Close client socket
    close(clientSocket);
}

// Read data from the socket and print it to the console
void readFromSocket(int socket) {
    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);
    read(socket, buffer, BUFFER_SIZE - 1);
    printf("Received message: %s\n", buffer);
}