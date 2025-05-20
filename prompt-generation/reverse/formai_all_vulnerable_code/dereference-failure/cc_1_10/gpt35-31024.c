//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    struct sockaddr_in server_address;
    struct hostent *server;
    int socket_fd, bytes_received;
    char buffer[BUFFER_SIZE];
    
    // Check for correct number of arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname> [port]\n", argv[0]);
        exit(1);
    }
    
    // Set the port number, default to 80 if not provided
    int port = (argc >= 3) ? atoi(argv[2]) : 80;
    
    // Create socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Failed to create socket");
        exit(1);
    }
    
    // Get server IP address from hostname
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Failed to get server IP address\n");
        exit(1);
    }
    
    // Configure server address struct
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr *)server->h_addr));
    server_address.sin_port = htons(port);
    
    // Connect to the server
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect to server");
        exit(1);
    }
    
    // Send GET request to server
    char *request = "GET / HTTP/1.1\r\nHost: %s\r\n\r\n";
    sprintf(buffer, request, argv[1]);
    if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send GET request");
        exit(1);
    }
    
    // Receive response from server
    memset(buffer, 0, sizeof(buffer));
    while ((bytes_received = recv(socket_fd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }
    
    // Check for error in receiving data
    if (bytes_received < 0) {
        perror("Failed to receive data");
        exit(1);
    }
    
    // Close socket
    close(socket_fd);
}