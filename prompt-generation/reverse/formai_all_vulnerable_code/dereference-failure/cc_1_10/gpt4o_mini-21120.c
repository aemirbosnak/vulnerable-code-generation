//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: imaginative
// Treasure Hunt Game: Client-Server Application 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 256

// Function to display instructions
void displayInstructions() {
    printf("Welcome to the Treasure Hunt Game!\n");
    printf("Try to guess the answer to earn points!\n");
    printf("Type 'exit' to close the game.\n\n");
}

// Server Code
void startServer() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char *hints[] = {
        "I am taken from a mine, and shut up in a wooden case, from which I am never released. What am I?",
        "The more you take, the more you leave behind. What am I?",
        "What has keys but can't open locks?",
        "I speak without a mouth and hear without ears. What am I?"
    };
    int hintsIndex = 0;
    char buffer[BUFFER_SIZE] = {0};
    
    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Treasure Hunt Server is running... Waiting for players to join!\n");
    
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        
        // Reset buffer and send hint
        memset(buffer, 0, sizeof(buffer));
        send(new_socket, hints[hintsIndex], strlen(hints[hintsIndex]), 0);
        printf("Hint sent to client: %s\n", hints[hintsIndex]);
        
        // Increment hint index
        hintsIndex = (hintsIndex + 1) % (sizeof(hints) / sizeof(hints[0]));

        // Wait for response
        read(new_socket, buffer, sizeof(buffer));
        printf("Client guessed: %s\n", buffer);
        
        // Check answer
        if (strcmp(buffer, "Gold") == 0 || 
            strcmp(buffer, "Footsteps") == 0 || 
            strcmp(buffer, "Piano") == 0 || 
            strcmp(buffer, "Echo") == 0) {
            char *response = "Correct! You earn 10 points!\n";
            send(new_socket, response, strlen(response), 0);
        } else {
            char *response = "Wrong answer! Better luck next time!\n";
            send(new_socket, response, strlen(response), 0);
        }
        
        close(new_socket);
    }
    
    close(server_fd);
}

// Client Code
void startClient() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return;
    }
    
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return;
    }
    
    displayInstructions();

    while(1) {
        memset(buffer, 0, sizeof(buffer));

        // Read hint from server
        read(sock, buffer, sizeof(buffer));
        printf("Server Hint: %s\n", buffer);
        
        printf("Enter your guess: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
        
        // Exit condition
        if(strcmp(buffer, "exit") == 0){
            printf("Thank you for playing! Goodbye!\n");
            break;
        }
        
        // Send guess to server
        send(sock, buffer, strlen(buffer), 0);
        
        // Read response from server
        read(sock, buffer, sizeof(buffer));
        printf("Server Response: %s", buffer);
    }

    close(sock);
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [server/client]\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "server") == 0) {
        startServer();
    } else if (strcmp(argv[1], "client") == 0) {
        startClient();
    } else {
        fprintf(stderr, "Invalid argument. Use 'server' or 'client'.\n");
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}