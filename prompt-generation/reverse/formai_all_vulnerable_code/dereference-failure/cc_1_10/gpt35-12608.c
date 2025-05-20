//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int client_sock, server_sock, n;
    struct sockaddr_in client_addr, server_addr;
    char buffer[BUFFER_SIZE];

    if (argc != 3) {
        printf("Usage: %s <client_port> <server_port>", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create sockets
    client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock < 0) {
        error("Error opening client socket");
    }
    
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        error("Error opening server socket");
    }

    // Bind sockets to ports
    memset(&client_addr, 0, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = INADDR_ANY;
    client_addr.sin_port = htons(atoi(argv[1]));

    if (bind(client_sock, (struct sockaddr *) &client_addr, sizeof(client_addr)) < 0) {
        error("Error binding client socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[2]));

    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("Error binding server socket");
    }
    
    // Listen for incoming connections
    if (listen(client_sock, 1) < 0) {
        error("Error listening for client connections");
    }

    if (listen(server_sock, 1) < 0) {
        error("Error listening for server connections");
    }

    printf("Proxy server listening on %s:%s\n", argv[1], argv[2]);
    
    while (1) {
        int client_sock_fd, server_sock_fd, len = sizeof(client_addr);
        char client_ip[INET_ADDRSTRLEN];
        memset(buffer, 0, BUFFER_SIZE);
        
        // Accept incoming connection from client
        client_sock_fd = accept(client_sock, (struct sockaddr *) &client_addr, &len);
        if (client_sock_fd < 0) {
            error("Error accepting client connection");
        }
        
        inet_ntop(AF_INET, &(client_addr.sin_addr), client_ip, INET_ADDRSTRLEN);
        
        printf("Received request from %s:%d\n", client_ip, ntohs(client_addr.sin_port));
        
        // Connect to server
        server_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sock_fd < 0) {
            error("Error opening socket for server connection");
        }
        
        if (connect(server_sock_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
            error("Error connecting to server");
        }
        
        printf("Connected to server\n");
        
        // Send client request to server
        if (write(server_sock_fd, buffer, strlen(buffer)) < 0) {
            error("Error sending request to server");
        }
        
        printf("Sent request to server\n");
        
        // Receive response from server and send to client
        memset(buffer, 0, BUFFER_SIZE);
        while ((n = read(server_sock_fd, buffer, BUFFER_SIZE - 1)) > 0) {
            if (write(client_sock_fd, buffer, n) < 0) {
                error("Error sending response to client");
            }
            
            memset(buffer, 0, BUFFER_SIZE);
        }
        
        if (n < 0) {
            error("Error receiving response from server");
        }
        
        printf("Sent response to client\n");
        
        close(client_sock_fd);
        close(server_sock_fd);
    }
    
    close(client_sock);
    close(server_sock);
    
    return 0;
}