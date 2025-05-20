//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Global Variables
int server_fd;
int port_number;
struct sockaddr_in server_address;

// Function Prototypes
int setup_socket(int);
int accept_client(int);
void display_usage(char*);
void handle_client(int);

int main(int argc, char *argv[]) {
    // Check Command Line Arguments
    if (argc!= 3) {
        display_usage(argv[0]);
        exit(1);
    }
    
    // Parse Port Number
    port_number = atoi(argv[2]);
    
    // Create a Socket
    server_fd = setup_socket(port_number);
    
    if (server_fd == -1) {
        perror("Error in socket creation");
        exit(1);
    }
    
    // Accept Clients
    while (1) {
        int client_fd = accept_client(server_fd);
        
        if (client_fd == -1) {
            perror("Error in accepting clients");
            exit(1);
        }
        
        handle_client(client_fd);
    }
    
    return 0;
}

// Function to set up the socket
int setup_socket(int port_number) {
    int sockfd;
    struct sockaddr_in server_address;
    int opt = 1;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        exit(1);
    }
    
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    server_address.sin_addr.s_addr = INADDR_ANY;
    
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Error in setting socket options");
        exit(1);
    }
    
    if (bind(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Error in binding socket");
        exit(1);
    }
    
    if (listen(sockfd, 5) == -1) {
        perror("Error in listening");
        exit(1);
    }
    
    return sockfd;
}

// Function to accept incoming connections
int accept_client(int sockfd) {
    struct sockaddr_in client_address;
    int client_fd;
    
    socklen_t client_len = sizeof(client_address);
    client_fd = accept(sockfd, (struct sockaddr *)&client_address, &client_len);
    
    if (client_fd == -1) {
        perror("Error in accepting clients");
        exit(1);
    }
    
    return client_fd;
}

// Function to display usage information
void display_usage(char *program) {
    printf("Usage: %s <port_number>\n", program);
}

// Function to handle client connections
void handle_client(int client_fd) {
    char buffer[1024];
    int n;
    
    // Read the client's request
    bzero(buffer, sizeof(buffer));
    n = read(client_fd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("Error in reading client's request");
        exit(1);
    }
    
    buffer[n] = '\0';
    
    // Process the client's request
    printf("Client's request: %s\n", buffer);
    
    // Send a response to the client
    bzero(buffer, sizeof(buffer));
    strcpy(buffer, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body>Hello, World!</body></html>");
    n = write(client_fd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("Error in writing to client");
        exit(1);
    }
}