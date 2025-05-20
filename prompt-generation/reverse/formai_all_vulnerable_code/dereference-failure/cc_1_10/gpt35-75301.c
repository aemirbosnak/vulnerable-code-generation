//FormAI DATASET v1.0 Category: Networking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5000
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    
    // Create server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        printf("Error creating socket: %d\n",errno);
        return -1;
    }
    
    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                &opt, sizeof(opt))) {
        printf("Error setting socket options: %d\n",errno);
        return -1;
    }
    
    // Bind socket to address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0 ) {
        printf("Error binding socket to address: %d\n",errno);
        return -1;
    }
    
    // Set socket to listening mode
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        printf("Error listening on socket: %d\n",errno);
        return -1;
    }
    
    printf("Server listening on port %d\n", PORT);
    
    while(1) {
        // Accept incoming connection
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if (new_socket < 0) {
            printf("Error accepting connection: %d\n",errno);
            continue;
        }
        
        printf("New client connected: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
        
        // Read data from client
        valread = read(new_socket, buffer, BUFFER_SIZE);
        if (valread <= 0) {
            printf("Error reading data from client: %d\n",errno);
            continue;
        }
        
        printf("Data received from client: %s\n",buffer);
        
        // Send response to client
        char response[] = "Hello world!";
        send(new_socket, response, strlen(response), 0);
        
        printf("Response sent to client\n");
        
        close(new_socket);
        printf("Client disconnected\n");
    }
    
    return 0;
}