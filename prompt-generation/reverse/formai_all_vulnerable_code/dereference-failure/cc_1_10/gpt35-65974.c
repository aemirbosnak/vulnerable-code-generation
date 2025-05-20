//FormAI DATASET v1.0 Category: Socket programming ; Style: standalone
/* 
    Title: Custom Server-Client Chat App
    Author: [Your Name]
    Description: A simple chat application between client and server using sockets.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 9000

int main()
{
    int server_socket, new_socket, read_size, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char *client_msg;
    char server_msg[200] = "Welcome to the chat!\n";
    
    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1)
    {
        printf("Error: couldn't create server socket.\n");
        exit(EXIT_FAILURE);
    }
    
    // Prepare sockaddr_in structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    // Bind socket to address and port
    if(bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Error: couldn't bind server socket.\n");
        exit(EXIT_FAILURE);
    }
    printf("Server started and listening on port %d!\n", PORT);
    
    // Listen for incoming connections
    listen(server_socket, 3);
    
    // Accept incoming connection
    client_socket = sizeof(struct sockaddr_in);
    new_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&client_socket);
    if(new_socket < 0)
    {
        printf("Error: couldn't establish connection with client.\n");
        exit(EXIT_FAILURE);
    }
    
    // Send welcome message to client
    write(new_socket, server_msg, strlen(server_msg));
    
    // Chat with client
    while((read_size = recv(new_socket, client_msg, 200, 0)) > 0)
    {
        // Trim client message
        client_msg[read_size] = '\0';
        
        // Send client message to server
        printf("Client: %s", client_msg);
        
        // Prompt server for message
        printf("Server: ");
        fgets(server_msg, 200, stdin);
        
        // Send server message to client
        write(new_socket, server_msg, strlen(server_msg));
    }
    
    // Close sockets and exit program
    close(new_socket);
    close(server_socket);
    return 0;
}