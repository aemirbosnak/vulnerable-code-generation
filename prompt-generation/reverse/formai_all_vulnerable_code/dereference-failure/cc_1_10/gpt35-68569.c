//FormAI DATASET v1.0 Category: Client Server Application ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT 8000
#define BUFSIZE 1024

// Function to generate and return a random 4-digit code
char* generateCode() {
    char* code = malloc(sizeof(char) * 5);
    for(int i=0; i<4; i++) {
        int num = rand() % 10;
        code[i] = num + '0';
    }
    code[4] = '\0';
    return code;
}

// Function to compare two codes and return the number of matching digits
int compareCodes(char* code1, char* code2) {
    int count = 0;
    for(int i=0; i<4; i++) {
        if(code1[i] == code2[i]) {
            count++;
        }
    }
    return count;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFSIZE] = {0};

    // Create socket file descriptor
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to address and port
    if(bind(server_fd, (struct sockaddr*)&address, addrlen) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if(listen(server_fd, 2) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Generate secret code
    char* secretCode = generateCode();

    // Wait for two clients to connect
    printf("Waiting for players...\n");
    int numPlayers = 0;
    while(numPlayers < 2) {
        if((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        char message[BUFSIZE] = "\nWelcome to the game of deduction!\n";
        send(new_socket, message, strlen(message), 0);
        numPlayers++;
    }
    printf("2 players connected.\n");

    // Game loop
    int gameOver = 0;
    while(!gameOver) {
        // Receive guess from client
        int valread = read(new_socket, buffer, BUFSIZE);
        buffer[valread] = '\0';
        printf("Client sent: %s\n", buffer);

        // Compare guess with secret code
        int numMatches = compareCodes(buffer, secretCode);

        // Send clue to client
        char clue[BUFSIZE];
        sprintf(clue, "Your guess, %s, has %d matching digits.\n", buffer, numMatches);
        send(new_socket, clue, strlen(clue), 0);
        
        // Check for correct guess
        if(numMatches == 4) {
            char winMessage[BUFSIZE] = "Congratulations, you have guessed the secret code!\n";
            send(new_socket, winMessage, strlen(winMessage), 0);
            gameOver = 1;
        }
    }

    // Close sockets and free memory
    close(new_socket);
    close(server_fd);
    free(secretCode);

    return 0;
}