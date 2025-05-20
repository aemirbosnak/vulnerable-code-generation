//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 256

// Potion details
const char *potions[] = {
    "Healing Potion",
    "Mana Potion",
    "Invisibility Potion",
    "Strength Potion",
    "Wisdom Potion"
};

void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    
    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Potion Master is ready to serve potions...\n");

    while (1) {
        // Accept a new client
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            continue;
        }

        // Serve the client
        read(new_socket, buffer, BUFFER_SIZE);
        printf("Wizard requested: %s\n", buffer);

        if (strcmp(buffer, "list") == 0) {
            // List potions
            char response[BUFFER_SIZE] = "Available potions:\n";
            for (int i = 0; i < sizeof(potions) / sizeof(potions[0]); ++i) {
                sprintf(response + strlen(response), "%d. %s\n", i + 1, potions[i]);
            }
            send(new_socket, response, strlen(response), 0);
        } else {
            // Handle potion ordering
            int potion_index = atoi(buffer) - 1;
            if (potion_index >= 0 && potion_index < sizeof(potions) / sizeof(potions[0])) {
                char response[BUFFER_SIZE];
                sprintf(response, "You have received a %s. May it aid you in your quests!", potions[potion_index]);
                send(new_socket, response, strlen(response), 0);
            } else {
                char *error_msg = "Invalid potion selected. Please try again.";
                send(new_socket, error_msg, strlen(error_msg), 0);
            }
        }
        
        // Close the connection with the current client
        close(new_socket);
        memset(buffer, 0, BUFFER_SIZE); // Clear the buffer
    }
}

void start_client() {
    int sock = 0;
    struct sockaddr_in serv_addr;
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

    // Connect to the potion master
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return;
    }

    printf("Welcome, brave wizard! Type 'list' to see available potions, or enter potion number to order: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove the trailing newline

    // Send the request
    send(sock, buffer, strlen(buffer), 0);
    
    // Receive response from the potion master
    read(sock, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);
    
    close(sock);
}

int main(int argc, char const *argv[]) {
    if (argc > 1 && strcmp(argv[1], "server") == 0) {
        start_server();
    } else {
        start_client();
    }
    return 0;
}