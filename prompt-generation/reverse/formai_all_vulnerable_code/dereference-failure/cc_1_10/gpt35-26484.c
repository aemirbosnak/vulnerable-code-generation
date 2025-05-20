//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Constants
#define SERVER_ADDR "127.0.0.1"    // The server IP address
#define SERVER_PORT 8888           // The server port number
#define MAX_MSG_LEN 256            // Maximum message length

// Helper function to send a message to the server
void send_msg(int sockfd, const char* msg) {
    int len = strlen(msg) + 1;  // Include null character
    send(sockfd, msg, len, 0);
}

// Helper function to receive a message from the server
void recv_msg(int sockfd, char* buffer) {
    int num_bytes = recv(sockfd, buffer, MAX_MSG_LEN, 0);
    buffer[num_bytes] = '\0';   // Add null character
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set the server address and port
    memset(&server_addr, 0, sizeof(server_addr));  // Zero out structure
    server_addr.sin_family = AF_INET;               // IPv4 address family
    server_addr.sin_port = htons(SERVER_PORT);      // Server port number
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR); // Server IP address

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Print a welcome message
    printf("Welcome to Happy Chat!\n");
    printf("Type ':q' to quit.\n");

    // Main loop
    char msg[MAX_MSG_LEN];
    char recv_buffer[MAX_MSG_LEN];
    while (1) {
        // Get user input
        printf("> ");
        fgets(msg, MAX_MSG_LEN, stdin);

        // Check for quit command
        if (strcmp(msg, ":q\n") == 0) {
            printf("Goodbye!\n");
            break;
        }

        // Send message to server
        send_msg(sockfd, msg);

        // Receive reply from server
        recv_msg(sockfd, recv_buffer);
        printf("Server: %s\n", recv_buffer);
    }

    // Close the socket
    close(sockfd);

    return 0;
}