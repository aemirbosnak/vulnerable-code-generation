//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

// Global variables to store necessary thread info
pthread_t sender_tid, receiver_tid;
int running = 1, sock;

// Handler function for interrupts
void handler(int signum) {
    running = 0; // Stop the threads
    shutdown(sock, 2); // Shut down the socket
}

// Sender thread function
void *sender(void *arg) {
    while (running) {
        char message[1024];
        fgets(message, 1024, stdin); // Get user input
        if (strcmp(message, "quit\n") == 0) { // Check if user wants to quit
            running = 0;
            break;
        }
        send(sock, message, strlen(message), 0); // Send message to receiver
    }
    return NULL;
}

// Receiver thread function
void *receiver(void *arg) {
    while (running) {
        char buffer[1024];
        int bytes_read = recv(sock, buffer, 1024, 0); // Receive message from sender
        if (bytes_read <= 0) { // If the connection is closed or interrupted
            running = 0;
            break;
        }
        buffer[bytes_read] = '\0'; // Null-terminate the received message
        printf("%s", buffer); // Print the received message
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }
    signal(SIGINT, handler); // Set up interrupt signal handler

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set up server address and port number
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    inet_aton(argv[1], &server_addr.sin_addr);
    server_addr.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Create sender and receiver threads
    if (pthread_create(&sender_tid, NULL, sender, NULL) != 0) {
        perror("Error creating sender thread");
        exit(1);
    }
    if (pthread_create(&receiver_tid, NULL, receiver, NULL) != 0) {
        perror("Error creating receiver thread");
        exit(1);
    }

    // Wait for threads to complete
    pthread_join(sender_tid, NULL);
    pthread_join(receiver_tid, NULL);

    close(sock); // Close the socket

    exit(0);
}