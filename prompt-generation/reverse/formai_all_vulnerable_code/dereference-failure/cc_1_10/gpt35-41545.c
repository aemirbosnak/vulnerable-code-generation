//FormAI DATASET v1.0 Category: Chat server ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>      // For string operations
#include <sys/socket.h>  // For socket creation
#include <arpa/inet.h>   // For getting the IP address


int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s port\n", argv[0]);
        return -1;
    }

    int port = strtol(argv[1], NULL, 10);       // Convert port number from string to integer

    int server_fd, client_fd;                   // Socket file descriptor
    struct sockaddr_in server_addr, client_addr; // Server and client address structure
    char buffer[1024] = {0};                    // Buffer to store messages

    // Create a socket for server
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Prepare the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    // Bind server to the socket
    if(bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if(listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", port);

    while(1) {  // Server keeps on running
        // Accept incoming connection
        int client_addr_len = sizeof(client_addr);
        
        if((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t*)&client_addr_len)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New client connected...\n");

        // Receive messages from client
        while(1) {  // Client is still connected
            int bytes_received = recv(client_fd, buffer, 1024, 0);
            if(bytes_received <= 0) {
                printf("Client disconnected...\n");
                close(client_fd);  // Close client socket
                break;
            }
            printf("[%s:%d] %s\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), buffer);

            // Send response to client
            int bytes_sent = send(client_fd, buffer, strlen(buffer), 0);
            if(bytes_sent < 0) {
                perror("send failed");
                exit(EXIT_FAILURE);
            }
            memset(buffer, 0, sizeof(buffer));  // Clear the buffer for next message
        }
    }

    // Close the server socket
    close(server_fd);
    return 0;
}