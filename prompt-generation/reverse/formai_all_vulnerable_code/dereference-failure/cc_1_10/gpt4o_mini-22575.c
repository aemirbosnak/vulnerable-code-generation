//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function Declarations
void *client_handler(void *socket_desc);
void error_handling(const char *message);

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error_handling("socket failed");
    }
    
    // Setting the address family, IP address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Bind the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        error_handling("bind failed");
    }
    
    // Start listening for connections
    if (listen(server_fd, 3) < 0) {
        error_handling("listen");
    }
    
    printf("Server listening on port %d...\n", PORT);
    
    while (1) {
        // Accepting a new connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            error_handling("accept");
        }
        
        printf("Connection established with client.\n");
        
        // Handle the client in a separate thread
        pthread_t client_thread;
        if (pthread_create(&client_thread, NULL, client_handler, (void *)&new_socket) < 0) {
            error_handling("could not create thread");
        }
    }

    close(server_fd);
    return 0;
}

void *client_handler(void *socket_desc) {
    int sock = *(int*)socket_desc;
    char buffer[BUFFER_SIZE];
    int read_size;
    
    // Receiving messages from the client
    while ((read_size = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0'; // Null-terminate the received string
        printf("Client: %s\n", buffer);
        
        // Echo the message back to the client
        send(sock, buffer, strlen(buffer), 0);
        printf("Echoed back: %s\n", buffer);
    }
    
    if (read_size == 0) {
        puts("Client disconnected");
        fflush(stdout);
    } else if (read_size == -1) {
        error_handling("recv failed");
    }
    
    // Free the socket pointer
    free(socket_desc);
    return 0;
}

void error_handling(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}