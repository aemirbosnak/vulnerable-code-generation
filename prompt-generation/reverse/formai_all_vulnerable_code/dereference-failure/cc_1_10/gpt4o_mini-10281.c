//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to handle the server-side operations
void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Setting up the address structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket to the specified port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    // Accepting a connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    printf("Connected to client\n");

    // Read and echo back the message
    while (1) {
        int read_size = read(new_socket, buffer, BUFFER_SIZE);
        if (read_size <= 0) {
            printf("Connection closed by client\n");
            break;
        }
        printf("Client: %s\n", buffer);
        send(new_socket, buffer, read_size, 0);
        memset(buffer, 0, sizeof(buffer));
    }

    close(new_socket);
    close(server_fd);
}

// Function to handle the client-side operations
void start_client() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    
    // Creating socket
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

    // Connecting to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return;
    }

    printf("Connected to server\n");

    // Client communication loop
    while (1) {
        printf("Enter message: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        send(sock, buffer, strlen(buffer), 0);
        
        // Exit if user sends "/exit"
        if (strncmp(buffer, "/exit", 5) == 0) {
            printf("Exiting...\n");
            break;
        }

        // Receiving the echo from server
        int valread = read(sock, buffer, BUFFER_SIZE);
        buffer[valread] = '\0';  // Null-terminate buffer
        printf("Server: %s\n", buffer);
        memset(buffer, 0, sizeof(buffer));
    }
    
    close(sock);
}

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <server/client>\n", argv[0]);
        return -1;
    }

    if (strcmp(argv[1], "server") == 0) {
        start_server();
    } else if (strcmp(argv[1], "client") == 0) {
        start_client();
    } else {
        printf("Invalid argument. Please use 'server' or 'client'.\n");
    }

    return 0;
}