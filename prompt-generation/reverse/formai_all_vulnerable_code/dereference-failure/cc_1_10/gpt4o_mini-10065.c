//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to generate a random dice roll
int roll_dice() {
    return (rand() % 6) + 1; // Returns a value between 1 and 6
}

// Server function to handle incoming client requests
void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Dice Roller Server running on port %d...\n", PORT);

    while (1) {
        // Accept a new connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Read message from client
        read(new_socket, buffer, BUFFER_SIZE);
        printf("Client requested a dice roll...\n");

        // Roll the dice
        int result = roll_dice();
        snprintf(buffer, BUFFER_SIZE, "You rolled a %d\n", result);

        // Send the result back to the client
        send(new_socket, buffer, strlen(buffer), 0);
        printf("Sent result to client: %s", buffer);
        
        // Close the socket
        close(new_socket);
    }
}

// Client function to request a dice roll from the server
void start_client() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *hello = "Roll the dice!";
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return;
    }

    // Send a message to the server
    send(sock, hello, strlen(hello), 0);
    printf("Message sent to server: %s\n", hello);

    // Read the server response
    read(sock, buffer, BUFFER_SIZE);
    printf("Server response: %s", buffer);

    // Close the socket
    close(sock);
}

int main(int argc, char const *argv[]) {
    srand(time(0)); // Seed the random number generator

    if (argc > 1 && strcmp(argv[1], "client") == 0) {
        start_client(); // Run the client
    } else {
        start_server(); // Run the server
    }

    return 0;
}