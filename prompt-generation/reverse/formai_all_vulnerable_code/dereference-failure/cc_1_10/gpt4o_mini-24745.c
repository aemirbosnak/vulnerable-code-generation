//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

// Define buffer size
#define BUFFER_SIZE 1024

// Function to rotate a shape
void rotate_shape(char *shape, char *result) {
    result[0] = '\0';
    int i;
    int lines = 0;
    
    // Count lines and store them in an array
    char *temp = strtok(shape, "\n");
    while(temp) {
        lines++;
        temp = strtok(NULL, "\n");
    }

    // Build the shape matrix
    char shape_matrix[10][10] = {0};
    temp = strtok(shape, "\n");
    for (i = 0; i < lines && temp; i++) {
        strcpy(shape_matrix[i], temp);
        temp = strtok(NULL, "\n");
    }

    // Rotate the shape 90 degrees clockwise
    for (i = 0; i < lines; i++) {
        int j;
        for (j = 0; j < strlen(shape_matrix[i]); j++) {
            result[strlen(shape_matrix[lines - 1 - j]) + i] = shape_matrix[i][j];
        }
        result[strlen(shape_matrix[lines - 1 - j]) + i + 1] = '\n';
    }
    result[strlen(shape_matrix[lines - 1]) + lines] = '\0';
}

// Server function
void start_server(int port) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char result[BUFFER_SIZE] = {0};

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        return;
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        return;
    }
    
    // Start listening
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        return;
    }

    printf("Server is listening on port %d\n", port);

    while (1) {
        // Accept a new connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            continue;
        }

        // Read shape from client
        read(new_socket, buffer, BUFFER_SIZE);
        printf("Received shape:\n%s\n", buffer);
        
        // Rotate the shape
        rotate_shape(buffer, result);

        // Send back the rotated shape
        send(new_socket, result, strlen(result), 0);
        close(new_socket);
        printf("Sent rotated shape:\n%s\n", result);
    }
}

// Client function
void start_client(const char *server_ip, int port) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *shape = "O\nO O\n O \n";
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return;
    }
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, server_ip, &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return;
    }
    
    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return;
    }

    // Send shape to server
    send(sock, shape, strlen(shape), 0);
    printf("Shape sent to server:\n%s\n", shape);

    // Receive rotated shape
    read(sock, buffer, BUFFER_SIZE);
    printf("Received rotated shape from server:\n%s\n", buffer);

    close(sock);
}

int main(int argc, char const *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s server|client <port> [server_ip]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "server") == 0) {
        start_server(atoi(argv[2]));
    } else if (strcmp(argv[1], "client") == 0) {
        if (argc < 4) {
            fprintf(stderr, "Usage: %s client <port> <server_ip>\n", argv[0]);
            exit(EXIT_FAILURE);
        }
        start_client(argv[3], atoi(argv[2]));
    } else {
        fprintf(stderr, "Invalid argument! Use 'server' or 'client'.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}