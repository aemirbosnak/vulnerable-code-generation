//FormAI DATASET v1.0 Category: Socket programming ; Style: lively
// Hey! Let's create a simple chat program with C Socket Programming!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_MSG_LENGTH 256 // Maximum length of a message

int main(int argc, char *argv[]) {
    // Initialize variables
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[MAX_MSG_LENGTH + 1];
    int bytes_received;
    
    // Make sure the correct number of arguments are provided
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP Address> <Port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Attempt to create TCP socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) != 1) {
        fprintf(stderr, "Invalid IP Address\n");
        exit(EXIT_FAILURE);
    }
    
    // Attempt to connect to server
    if (connect(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }
    
    // Great, we're connected! Let's start chatting
    printf("Connected to server! Start chatting:\n");

    // Loop to keep sending and receiving messages until "exit" is entered 
    while(1) {
        // Clear buffer
        memset(buffer, 0, sizeof(buffer));
        
        // Get message from user
        fgets(buffer, MAX_MSG_LENGTH, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character
        
        // Send message
        if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
            perror("Error sending message");
            exit(EXIT_FAILURE);
        }

        // Check if user wants to exit
        if (strcmp(buffer, "exit") == 0) {
            break;
        }
        
        // Wait for response from server
        bytes_received = recv(sockfd, buffer, MAX_MSG_LENGTH, 0);
        
        // Check for errors and end-of-file
        if (bytes_received == -1) {
            perror("Error receiving message");
            exit(EXIT_FAILURE);
        } else if (bytes_received == 0) {
            printf("Connection closed by server\n");
            break;
        }
        
        // Null-terminate the message
        buffer[bytes_received] = '\0';
        
        // Display server's response
        printf("Server: %s\n", buffer);
    }

    // Close the socket and exit
    printf("Closing connection and exiting...\n");
    close(sockfd);
    exit(EXIT_SUCCESS);
}