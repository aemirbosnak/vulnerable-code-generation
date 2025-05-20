//FormAI DATASET v1.0 Category: Client Server Application ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

// Structure for client thread
struct clientThreadArgs {
    int clientSocket;
};

void *clientHandler(void *args) {
    // Extract client socket    
    struct clientThreadArgs *threadArgs = args;
    int clientSocket = threadArgs->clientSocket;

    // Receive and send messages
    char message[100];
    char response[100];
    while (1) {
        int receive = recv(clientSocket, message, sizeof(message), 0);
        if (receive == 0) {
            // Client disconnected
            printf("Client disconnected\n");
            break;
        } else {
            // Echo message back to client
            sprintf(response, "Echo: %s", message);
            send(clientSocket, response, strlen(response), 0);
        }
    }

    // Close client socket and clean up
    close(clientSocket);
    free(threadArgs);
    pthread_exit(NULL);
}

int main() {
    // Create server socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        printf("Error creating server socket\n");
        return 1;
    }

    // Bind server socket to port 8080
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        printf("Error binding server socket to port 8080\n");
        return 1;
    }

    // Listen for client connections
    if (listen(serverSocket, 5) < 0) {
        printf("Error listening for client connections\n");
        return 1;
    }

    // Wait for clients
    while (1) {
        // Accept client connection
        struct sockaddr_in clientAddr;
        int clientSockLen = sizeof(clientAddr);
        int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, (socklen_t *)&clientSockLen);
        if (clientSocket < 0) {
            printf("Error accepting client connection\n");
            continue;
        }

        // Create a new thread to handle the client
        pthread_t clientThread;
        struct clientThreadArgs *threadArgs = malloc(sizeof(*threadArgs));
        threadArgs->clientSocket = clientSocket;
        if (pthread_create(&clientThread, NULL, clientHandler, threadArgs) < 0) {
            printf("Error creating client thread\n");
            return 1;
        }
    }

    // Clean up
    close(serverSocket);
    return 0;
}