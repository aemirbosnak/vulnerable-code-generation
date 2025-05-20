//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <ctype.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to convert message to uppercase
void to_uppercase(char *buffer) {
    for(int i = 0; buffer[i]; i++) {
        buffer[i] = toupper(buffer[i]);
    }
}

// Server function
void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket to the address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Server listening on port %d...\n", PORT);

    // Accepting a connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                             (socklen_t*)&addrlen)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Chat loop
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int valread = read(new_socket, buffer, BUFFER_SIZE);
        if (valread <= 0) {
            printf("Connection closed or read failed.\n");
            break;
        }
        printf("Client: %s", buffer);

        // Convert to uppercase and send back
        to_uppercase(buffer);
        send(new_socket, buffer, strlen(buffer), 0);
        printf("Echo to client: %s", buffer);
    }

    close(new_socket);
    close(server_fd);
}

// Client function
void start_client() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    char message[BUFFER_SIZE];

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

    // Chat loop
    while (1) {
        printf("You: ");
        fgets(message, BUFFER_SIZE, stdin);
        send(sock, message, strlen(message), 0);

        // Clear buffer and read response
        memset(buffer, 0, BUFFER_SIZE);
        read(sock, buffer, BUFFER_SIZE);
        printf("Server: %s", buffer);

        if (strncmp(message, "exit", 4) == 0) {
            printf("Exiting chat...\n");
            break;
        }
    }

    close(sock);
}

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <server|client>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "server") == 0) {
        start_server();
    } else if (strcmp(argv[1], "client") == 0) {
        start_client();
    } else {
        fprintf(stderr, "Invalid argument. Please use 'server' or 'client'.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}