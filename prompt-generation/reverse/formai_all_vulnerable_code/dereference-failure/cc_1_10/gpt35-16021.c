//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    // Check the command line arguments
    if (argc != 4) {
        printf("Usage: %s <server> <port> <filename>\n", argv[0]);
        exit(1);
    }

    // Create a client socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Failed to create client socket");
        exit(1);
    }

    // Setup the server address structure
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(atoi(argv[2]));

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect to the server");
        exit(1);
    }

    // Send the filename to the server
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "%s\n", argv[3]);
    send(client_socket, buffer, strlen(buffer), 0);

    // Receive the response from the server
    memset(buffer, 0, BUFFER_SIZE);
    recv(client_socket, buffer, BUFFER_SIZE, 0);

    // Check if the file exists
    if (strcmp(buffer, "File not found\n") == 0) {
        printf("%s", buffer);
        exit(1);
    }

    // Open the file for writing
    int file_descriptor = open(argv[3], O_CREAT | O_WRONLY, 0644);
    if (file_descriptor < 0) {
        perror("Failed to open file for writing");
        exit(1);
    }

    // Receive the file from the server and write it to disk
    ssize_t bytes_received;
    do {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received < 0) {
            perror("Failed to receive data from server");
            exit(1);
        } else if (bytes_received > 0) {
            int bytes_written = write(file_descriptor, buffer, bytes_received);
            if (bytes_written < 0) {
                perror("Failed to write data to file");
                exit(1);
            }
        }
    } while (bytes_received > 0);

    // Close the file
    close(file_descriptor);

    // Close the client socket
    close(client_socket);

    printf("File downloaded successfully\n");

    return 0;
}