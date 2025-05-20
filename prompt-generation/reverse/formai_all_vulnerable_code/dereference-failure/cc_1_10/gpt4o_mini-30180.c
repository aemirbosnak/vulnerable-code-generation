//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 256
#define MAX_CLIENTS 5

void riddleserver() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char *riddle = "I speak without a mouth and hear without ears. I have no body, but I come alive with the wind. What am I?";
    char *correct_answer = "Echo";
    char buffer[BUFFER_SIZE] = {0};

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Structure to hold server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Riddle Server is running on port %d...\n", PORT);

    while (1) {
        // Accept an incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Send a riddle to the client
        send(new_socket, riddle, strlen(riddle), 0);
        printf("Sent riddle to client: %s\n", riddle);

        // Receive the answer from the client
        int valread = read(new_socket, buffer, BUFFER_SIZE);
        buffer[valread] = '\0';
        printf("Received answer from client: %s\n", buffer);

        // Check if the answer is correct
        if (strcasecmp(buffer, correct_answer) == 0) {
            char *response = "Correct! Well done!";
            send(new_socket, response, strlen(response), 0);
        } else {
            char *response = "Incorrect! Try again.";
            send(new_socket, response, strlen(response), 0);
        }

        // Close the socket with the client
        close(new_socket);
    }
}

void riddleclient() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    char *answer = NULL;

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

    // Reading the riddle from the server
    int valread = read(sock, buffer, BUFFER_SIZE);
    buffer[valread] = '\0';
    printf("Received riddle from server: %s\n", buffer);

    // Get user's answer
    answer = (char *)malloc(BUFFER_SIZE);
    printf("Please enter your answer: ");
    fgets(answer, BUFFER_SIZE, stdin);
    answer[strcspn(answer, "\n")] = 0; // Remove newline character

    // Send the answer to the server
    send(sock, answer, strlen(answer), 0);
    printf("Sent answer to server: %s\n", answer);

    // Read server response
    valread = read(sock, buffer, BUFFER_SIZE);
    buffer[valread] = '\0';
    printf("Server response: %s\n", buffer);

    // Clean up
    free(answer);
    close(sock);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <server/client>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Starting the server or client based on argument
    if (strcmp(argv[1], "server") == 0) {
        riddleserver();
    } else if (strcmp(argv[1], "client") == 0) {
        riddleclient();
    } else {
        fprintf(stderr, "Invalid argument: %s. Use 'server' or 'client'.\n", argv[1]);
    }

    return 0;
}