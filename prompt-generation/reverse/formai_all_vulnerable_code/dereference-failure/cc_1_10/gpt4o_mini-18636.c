//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to handle the server side operations
void start_server() {
    int server_fd, client_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Configure server address structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for client connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        // Accept client connection
        if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Accepted a connection from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Receive file name from client
        read(client_fd, buffer, BUFFER_SIZE);
        printf("Receiving file: %s\n", buffer);

        // Open file for writing
        FILE *fp = fopen(buffer, "wb");
        if (fp == NULL) {
            perror("File opening failed");
            close(client_fd);
            continue;
        }

        // Receive file data
        while (1) {
            int bytes_read = read(client_fd, buffer, BUFFER_SIZE);
            if (bytes_read <= 0) break;
            fwrite(buffer, sizeof(char), bytes_read, fp);
        }

        printf("File received successfully.\n");
        fclose(fp);
        close(client_fd);
    }
}

// Function to handle client side operations
void start_client(const char *file_name) {
    int sock;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Assign server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address / Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Send file name
    send(sock, file_name, strlen(file_name), 0);
    printf("Sending file: %s\n", file_name);

    // Open the file for reading
    FILE *fp = fopen(file_name, "rb");
    if (fp == NULL) {
        perror("File opening failed");
        close(sock);
        return;
    }

    // Send file content
    while (!feof(fp)) {
        int bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, fp);
        send(sock, buffer, bytes_read, 0);
    }

    printf("File sent successfully.\n");
    fclose(fp);
    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_name_to_send>\n", argv[0]);
        fprintf(stderr, "Start server first by running: %s server\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "server") == 0) {
        start_server();
    } else {
        start_client(argv[1]);
    }

    return 0;
}