//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 256

// Function to analyze the message - a little detective work
void analyze_message(char *message) {
    printf("Analyzing the message: \"%s\"\n", message);
    // Simple analysis logic
    if (strstr(message, "murder") != NULL) {
        printf("Conclusion: A nefarious act might be at play!\n");
    } else if (strstr(message, "robbery") != NULL) {
        printf("Conclusion: The motive seems to revolve around theft.\n");
    } else {
        printf("Conclusion: This appears to be a benign conversation...\n");
    }
}

// Server Side
void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;  // All incoming connections
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen");
        exit(EXIT_FAILURE);
    }

    printf("Watson: The game is afoot! Server is waiting for messages...\n");

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept");
            exit(EXIT_FAILURE);
        }

        read(new_socket, buffer, BUFFER_SIZE);
        printf("Holmes received: \"%s\"\n", buffer);
        analyze_message(buffer);

        // Respond back to the client
        char *response = "Your message has been analyzed, Mr. Holmes.";
        send(new_socket, response, strlen(response), 0);
        close(new_socket);
        memset(buffer, 0, BUFFER_SIZE); // Clear buffer for next use
    }
}

// Client Side
void start_client() {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *message = "There's been a murder in Baker Street!";
    char buffer[BUFFER_SIZE] = {0};

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

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return;
    }

    send(sock, message, strlen(message), 0);
    printf("Holmes has sent: \"%s\"\n", message);
    valread = read(sock, buffer, BUFFER_SIZE);
    printf("Server response: \"%s\"\n", buffer);

    close(sock);
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        printf("Usage: %s (server|client)\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "server") == 0) {
        start_server();
    } else if (strcmp(argv[1], "client") == 0) {
        start_client();
    } else {
        printf("Unknown option! Please choose either 'server' or 'client'.\n");
        return 1;
    }

    return 0;
}