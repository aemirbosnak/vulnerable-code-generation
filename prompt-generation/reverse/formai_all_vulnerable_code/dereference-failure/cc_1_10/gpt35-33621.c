//FormAI DATASET v1.0 Category: Client Server Application ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
  
void error_handler(char* message) {
    perror(message);
    exit(EXIT_FAILURE);
}
  
int main(int argc, char const *argv[])
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *welcome_message = "Welcome to the server!";
      
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        error_handler("Socket creation failed");
    }
      
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
      
    // Bind socket to address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
    {
        error_handler("Binding failed");
    }
      
    // Listen for incoming connections
    if (listen(server_fd, 3) < 0)
    {
        error_handler("Listen failed");
    }
      
    // Accept and handle incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
    {
        error_handler("Acceptance failed");
    }
    
    // Send welcome message to client
    send(new_socket, welcome_message, strlen(welcome_message), 0);
    printf("Welcome message sent to client\n");
    
    // Receive message from client and echo it back
    read(new_socket, buffer, 1024);
    printf("Client said: %s\n", buffer);
    send(new_socket, buffer, strlen(buffer), 0);
    printf("Message echoed back to client\n");
    
    return 0;
}