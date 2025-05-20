//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: high level of detail
/* A simple HTTP proxy server that accepts client connections and forwards requests to origin server */

//Includes required libraries
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

//Define constants for buffer size and port number
#define BUF_SIZE 4096
#define SERVER_PORT 8080

//Function to handle the client request and forward to origin server
void handle_request(int client_sock, char* server_name)
{
    //Create new socket for connecting to origin server
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    
    if (server_sock < 0) 
    {
        perror("Error in creating server socket");
        exit(1);
    }
    
    //Get origin server information using DNS lookup
    struct hostent* server = gethostbyname(server_name);
    
    if (server == NULL) 
    {
        perror("Error in resolving server address");
        exit(1);
    }
    
    //Create server address structure with IP and port number
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);   //Default HTTP port
    bcopy((char*)server->h_addr, 
          (char*)&server_addr.sin_addr.s_addr, server->h_length);
    
    //Connect to origin server
    if (connect(server_sock, (struct sockaddr*)&server_addr, 
                                sizeof(server_addr)) < 0)
    {
        perror("Error in connecting to server");
        exit(1);
    }
    
    //Read request from client and forward to server 
    char* buffer = (char*)malloc(BUF_SIZE);
    memset(buffer, 0, BUF_SIZE);
    int n = 0;
    
    while ((n = read(client_sock, buffer, BUF_SIZE - 1)) > 0) 
    {
        if (write(server_sock, buffer, n) < 0)
        {
            perror("Error in writing to server socket");
            exit(1);
        }
        
        memset(buffer, 0, BUF_SIZE);
    }
    
    //Read response from server and forward to client
    memset(buffer, 0, BUF_SIZE);
    
    while ((n = read(server_sock, buffer, BUF_SIZE - 1)) > 0)
    {
        if (write(client_sock, buffer, n) < 0)
        {
            perror("Error in writing to client socket");
            exit(1);
        }
        
        memset(buffer, 0, BUF_SIZE);
    }
    
    //Close sockets and free buffer memory
    close(server_sock);
    close(client_sock);
    free(buffer);
}

//Main function that listens for incoming connections
int main()
{
    //Create new socket for server
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    
    if (server_sock < 0) 
    {
        perror("Error in creating server socket");
        exit(1);
    }
    
    //Create server address structure with IP and port number
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);   //Any incoming interface
    server_addr.sin_port = htons(SERVER_PORT);
    
    //Bind socket to server address
    if (bind(server_sock, (struct sockaddr*)&server_addr, 
                                sizeof(server_addr)) < 0)
    {
        perror("Error in binding server socket");
        exit(1); 
    }
    
    //Listen for incoming connections
    if (listen(server_sock, 10) < 0)
    {
        perror("Error in listening for connections");
        exit(1);
    }
    
    printf("HTTP Proxy Server running on port %d...\n", SERVER_PORT);
    
    while (1)
    {
        //Accept incoming client connection and handle request
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_sock = accept(server_sock, 
                    (struct sockaddr*)&client_addr, &client_len);
        
        if (client_sock < 0) 
        {
            perror("Error in accepting client connection");
            continue;
        }
        
        //Fork a child process to handle the client request
        pid_t pid = fork();
        
        if (pid < 0)
        {
            perror("Error in creating child process");
            exit(1);
        }
        else if (pid == 0)
        {
            close(server_sock);
            handle_request(client_sock, "www.google.com");
            exit(0);
        }
        else
        {
            close(client_sock);
        }
    }
    
    close(server_sock);
    return 0;
}