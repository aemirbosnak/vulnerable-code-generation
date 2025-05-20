//FormAI DATASET v1.0 Category: Client Server Application ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    // Check for command-line arguments
    if (argc != 3) {
        printf("Usage: %s <ip_address> <port_number>\n", argv[0]);
        return 1;
    }

    // Parse command-line arguments
    char* server_ip = argv[1];
    int server_port = atoi(argv[2]);

    // Create socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Set up server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        perror("Error setting up server address");
        return 1;
    }

    // Connect to server
    if (connect(socket_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    // Send message to server
    char buffer[BUFFER_SIZE];
    printf("Enter message: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    send(socket_fd, buffer, strlen(buffer), 0);

    // Receive response from server
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(socket_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response from server");
        return 1;
    }
    printf("Server response: %s", buffer);

    // Close socket and exit
    close(socket_fd);
    return 0;
}