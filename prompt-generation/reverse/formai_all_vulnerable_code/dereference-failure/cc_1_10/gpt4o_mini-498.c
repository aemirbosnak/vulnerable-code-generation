//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        handle_error("Socket failed");
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        handle_error("Bind failed");
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        handle_error("Listen failed");
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            handle_error("Accept failed");
        }

        int read_size = read(new_socket, buffer, BUFFER_SIZE);
        if (read_size < 0) {
            handle_error("Read failed");
        }

        printf("Received: %s\n", buffer);
        
        // Echoing back the received message
        send(new_socket, buffer, read_size, 0);
        printf("Echoed: %s\n", buffer);
        close(new_socket);
    }

    close(server_fd);
}

void start_client(const char *server_ip) {
    int sock;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handle_error("Socket creation error");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, server_ip, &serv_addr.sin_addr) <= 0) {
        handle_error("Invalid address / Address not supported");
    }
    
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        handle_error("Connection failed");
    }

    printf("Connected to server at %s:%d\n", server_ip, PORT);

    while (1) {
        printf("Enter message (type 'exit' to quit): ");
        fgets(buffer, BUFFER_SIZE, stdin);  // Read user input

        if (strncmp(buffer, "exit", 4) == 0) {
            break; // Exit on 'exit'
        }

        send(sock, buffer, strlen(buffer), 0);
        printf("Message sent: %s\n", buffer);
        
        // Wait for echo
        int read_size = read(sock, buffer, BUFFER_SIZE);
        if (read_size < 0) {
            handle_error("Read failed");
        }
        buffer[read_size] = '\0'; // Null-terminate the string
        printf("Received from server: %s\n", buffer);
    }

    close(sock);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <server|client> [server_ip]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "server") == 0) {
        start_server();
    } else if (strcmp(argv[1], "client") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Usage: %s client <server_ip>\n", argv[0]);
            exit(EXIT_FAILURE);
        }
        start_client(argv[2]);
    } else {
        fprintf(stderr, "Invalid argument. Use 'server' or 'client'.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}