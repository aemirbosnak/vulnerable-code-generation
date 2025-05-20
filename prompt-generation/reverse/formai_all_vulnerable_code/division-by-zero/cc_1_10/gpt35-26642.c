//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <signal.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

// Struct to store network properties
typedef struct {
    int packetLoss;
    int jitter;
    int latency;
} NetworkQuality;

// Function to simulate network latency
void simulateLatency() {
    // Generate a random latency between 50 and 200ms
    int latency = (rand() % 150) + 50;
    struct timespec tim, rem;
    tim.tv_sec = 0;
    tim.tv_nsec = latency * 1000000L;
    nanosleep(&tim, &rem);
}

// Function to simulate packet loss
void simulatePacketLoss(NetworkQuality* quality) {
    // Generate a random number between 0 and 100
    int chance = rand() % 100;
    if(chance < quality->packetLoss) {
        // Simulate packet loss by doing nothing
        return;
    }
    // Otherwise, simulate latency
    simulateLatency();
}

// Function to simulate jitter
void simulateJitter(NetworkQuality* quality) {
    // Generate a random number between 0 and jitter value
    int jitter = rand() % quality->jitter;
    // Add the jitter to the latency
    int totalLatency = quality->latency + jitter;
    // Simulate the latency with added jitter
    struct timespec tim, rem;
    tim.tv_sec = 0;
    tim.tv_nsec = totalLatency * 1000000L;
    nanosleep(&tim, &rem);
}

// Function to handle SIGINT signal
void handleInterrupt(int sig) {
    printf("\nQuitting...\n");
    exit(0);
}

int main() {
    // Register SIGINT handler
    signal(SIGINT, handleInterrupt);

    // Initialize network quality struct with default values
    NetworkQuality networkQuality = { 0, 0, 100 };

    // Create socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSocket < 0) {
        printf("Failed to create socket\n");
        exit(1);
    }

    // Set socket options for SO_REUSEADDR
    int opt = 1;
    if(setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        printf("Failed to set socket options\n");
        exit(1);
    }

    // Bind socket to port
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);

    if(bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) {
        printf("Failed to bind socket to port\n");
        exit(1);
    }

    // Listen for connections
    if(listen(serverSocket, 3) < 0) {
        printf("Failed to listen for connections\n");
        exit(1);
    }

    // Accept a connection
    printf("Waiting for connection...\n");
    int clientSocket;
    struct sockaddr_in clientAddress;
    socklen_t addressLength;
    if((clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &addressLength)) < 0) {
        printf("Failed to accept connection\n");
        exit(1);
    }

    printf("Connection established!\n");

    // Loop to receive and send messages
    while(1) {
        char buffer[MAX_BUFFER_SIZE] = { 0 };

        // Receive message from client
        int bytesRead = recv(clientSocket, buffer, MAX_BUFFER_SIZE, 0);
        if(bytesRead < 0) {
            printf("Failed to receive message\n");
            exit(1);
        }

        // Simulate packet loss and jitter
        simulatePacketLoss(&networkQuality);
        simulateJitter(&networkQuality);

        // Print received message
        printf("Received message: %s\n", buffer);

        // Send message to client
        if(send(clientSocket, buffer, strlen(buffer), 0) < 0) {
            printf("Failed to send message\n");
            exit(1);
        }
    }
}