//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void love_letter_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char *message = "Dear beloved, your heart is the diary of my soul.";
    char buffer[BUFFER_SIZE] = {0};

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET; // IPv4
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Bind the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    
    // Start listening for love seekers
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Love Letter Server is waiting for the desires of the heart...\n");

    while (1) {
        // Accepting a connection from a love poet
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            close(server_fd);
            exit(EXIT_FAILURE);
        }

        // Greet the poet and send the love letter
        read(new_socket, buffer, BUFFER_SIZE);
        printf("Poet's request: %s\n", buffer);
        send(new_socket, message, strlen(message), 0);
        printf("Love letter sent to the poet!\n");
        close(new_socket);
    }
}

void love_letter_client() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *request = "Requesting a beautiful love letter...";
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return;
    }

    serv_addr.sin_family = AF_INET; // IPv4
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return;
    }

    // Connect to the love letter server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection to the love letter server failed \n");
        return;
    }

    // Send a request
    send(sock, request, strlen(request), 0);
    printf("A heartfelt request has been sent to the server...\n");

    // Receive the love letter
    read(sock, buffer, BUFFER_SIZE);
    printf("Received love letter: %s\n", buffer);
    close(sock);
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <mode: client/server>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "server") == 0) {
        love_letter_server();
    } else if (strcmp(argv[1], "client") == 0) {
        love_letter_client();
    } else {
        fprintf(stderr, "Unknown mode! Please choose either 'client' or 'server'.\n");
        return EXIT_FAILURE;
    }

    return 0;
}