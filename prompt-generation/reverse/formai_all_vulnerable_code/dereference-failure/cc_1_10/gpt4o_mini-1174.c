//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// File Server Code
void start_file_server() {
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

    // Attach socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Start listening for connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("File server listening on port %d...\n", PORT);

    // Accept a connection
    if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Clear the buffer and read the filename from the client
    memset(buffer, 0, sizeof(buffer));
    int read_size = read(client_fd, buffer, sizeof(buffer));
    if (read_size <= 0) {
        perror("Receive failed");
        close(client_fd);
        return;
    }
    
    // Open the requested file
    int file_fd = open(buffer, O_RDONLY);
    if (file_fd < 0) {
        perror("File not found");
        const char *not_found_msg = "File not found!\n";
        send(client_fd, not_found_msg, strlen(not_found_msg), 0);
    } else {
        // Send file content to the client
        ssize_t bytes_read;
        while ((bytes_read = read(file_fd, buffer, sizeof(buffer))) > 0) {
            send(client_fd, buffer, bytes_read, 0);
            memset(buffer, 0, sizeof(buffer)); // Clear buffer
        }
        close(file_fd);
    }

    close(client_fd);
    close(server_fd);
    printf("File server shutting down...\n");
}

// File Client Code
void start_file_client(const char *filename) {
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
    
    // Convert IPv4 and IPv6 addresses from text to binary
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("Invalid address/ Address not supported \n");
        return;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection Failed \n");
        return;
    }
    
    // Send filename to the server
    send(sock, filename, strlen(filename), 0);
    
    // Read response (file content) from server
    ssize_t read_size;
    while ((read_size = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        // Print received content to stdout
        write(STDOUT_FILENO, buffer, read_size);
        memset(buffer, 0, sizeof(buffer)); // Clear buffer
    }

    close(sock);
}

// Main Function
int main(int argc, char const *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename_to_request>\n", argv[0]);
        return 1;
    }

    // Uncomment either of the following for server or client mode
    // start_file_server(); // Uncomment to start server
    start_file_client(argv[1]); // Pass filename as argument to start client

    return 0;
}