//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 8080
#define MAX_QUEUE_LENGTH 10
#define MAX_BUFFER_LENGTH 1024

// Function to print error message and exit program
void error(const char* message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main() {
    int server_fd, new_socket, response;
    struct sockaddr_in address;
    struct hostent* host;
    int addrlen = sizeof(address);
    char buffer[MAX_BUFFER_LENGTH] = {0};
    char* client_message = "Hello from the server!";
    
    // Create socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        error("Socket creation failed");
    }
    
    // Resolve host and port
    host = gethostbyname("localhost");
    if (host == NULL) {
        error("Host resolution failed");
    }
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    memcpy(&address.sin_addr.s_addr, host->h_addr, host->h_length);
    
    // Bind socket to address and port
    if (bind(server_fd, (struct sockaddr*)&address, addrlen) < 0) {
        error("Binding failed");
    }
    
    // Listen for incoming connections
    if (listen(server_fd, MAX_QUEUE_LENGTH) < 0) {
        error("Listening failed");
    }
    
    // Accept incoming connection
    new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
    if (new_socket < 0) {
        error("Accepting connection failed");
    }
    
    // Receive message from client
    response = recv(new_socket, buffer, MAX_BUFFER_LENGTH, 0);
    if (response < 0) {
        error("Receiving message failed");
    }
    printf("Message from client: %s\n", buffer);
    
    // Send message to client
    response = send(new_socket, client_message, strlen(client_message), 0);
    if (response < 0) {
        error("Sending message failed");
    }
    printf("Message sent to client: %s\n", client_message);
    
    // Close socket
    close(new_socket);
    close(server_fd);
    
    return 0;
}