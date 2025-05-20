//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function declarations
void handleClient(int clientSocket);
void startServer();
void startClient(const char *ipAddress);
void errorExit(const char *message);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server|client> [ip address]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "server") == 0) {
        startServer();
    } else if (strcmp(argv[1], "client") == 0 && argc == 3) {
        startClient(argv[2]);
    } else {
        fprintf(stderr, "Invalid arguments.\n");
    }

    return 0;
}

void errorExit(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void handleClient(int clientSocket) {
    char buffer[BUFFER_SIZE];
    int bytesRead;

    // Loop to communicate with the client
    while ((bytesRead = read(clientSocket, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytesRead] = '\0'; // Null-terminate the received string
        printf("Received: %s\n", buffer);
        
        // Respond to the client
        const char *response = "Message received!";
        write(clientSocket, response, strlen(response));
    }

    // Close the client socket
    close(clientSocket);
}

void startServer() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addrLen = sizeof(clientAddr);

    // Create socket
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        errorExit("Socket creation failed");
    }

    // Set up server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    // Bind socket
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        errorExit("Bind failed");
    }

    // Listen for incoming connections
    if (listen(serverSocket, 3) < 0) {
        errorExit("Listen failed");
    }

    printf("Server is running on port %d...\n", PORT);

    // Accept clients indefinitely
    while ((clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &addrLen)) >= 0) {
        printf("Connection established with a client.\n");
        handleClient(clientSocket);
    }

    if (clientSocket < 0) {
        errorExit("Accept failed");
    }

    // Close the server socket
    close(serverSocket);
}

void startClient(const char *ipAddress) {
    int clientSocket;
    struct sockaddr_in serverAddr;
    char message[BUFFER_SIZE];

    // Create socket
    if ((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        errorExit("Socket creation failed");
    }

    // Set up server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, ipAddress, &serverAddr.sin_addr) <= 0) {
        errorExit("Invalid address");
    }

    // Connect to the server
    if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        errorExit("Connection failed");
    }

    // Communicate with the server
    while (1) {
        printf("Enter message (type 'exit' to quit): ");
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = 0; // Remove newline character

        if (strcmp(message, "exit") == 0) {
            break;
        }

        write(clientSocket, message, strlen(message));

        char response[BUFFER_SIZE] = {0};
        read(clientSocket, response, sizeof(response) - 1);
        printf("Server response: %s\n", response);
    }

    // Close the client socket
    close(clientSocket);
}