//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUF_SIZE 1024

// Function to encrypt using Caesar cipher
void caesar_encrypt(char *input, int shift, char *output) {
    while (*input) {
        if (*input >= 'a' && *input <= 'z') {
            *output = ((*input - 'a' + shift) % 26) + 'a';
        } else if (*input >= 'A' && *input <= 'Z') {
            *output = ((*input - 'A' + shift) % 26) + 'A';
        } else {
            *output = *input;  // Non-alphabetical characters remain unchanged
        }
        input++;
        output++;
    }
    *output = '\0'; // Null terminate the output string
}

// Server function
void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUF_SIZE] = {0};
    char encrypted_message[BUF_SIZE];

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }

    // Set up address struct
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        // Accept incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Read message from client
        read(new_socket, buffer, BUF_SIZE);
        printf("Received message: %s\n", buffer);

        // Encrypt the message
        caesar_encrypt(buffer, 3, encrypted_message);  // Shift of 3
        printf("Encrypted message: %s\n", encrypted_message);

        // Send encrypted message back to client
        send(new_socket, encrypted_message, strlen(encrypted_message), 0);
        close(new_socket);
    }
}

// Client function
void start_client(const char *message) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUF_SIZE] = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error \n");
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("Invalid address/ Address not supported \n");
        return;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection Failed \n");
        return;
    }

    // Send message to server
    send(sock, message, strlen(message), 0);
    printf("Message sent to server: %s\n", message);

    // Read the encrypted response
    read(sock, buffer, BUF_SIZE);
    printf("Encrypted message received from server: %s\n", buffer);

    close(sock);
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <message to encrypt>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Fork into server and client
    pid_t pid = fork();

    if (pid == 0) {
        // Child process runs the server
        start_server();
    } else if (pid > 0) {
        // Parent process runs the client
        sleep(1);  // Give server time to start
        start_client(argv[1]);
    } else {
        printf("Forking failed\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}