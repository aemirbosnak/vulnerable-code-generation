//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define BUFFER_SIZE 4096

int main(int argc, char **argv) {
    // Parse command line arguments
    int port = atoi(argv[1]);
    
    // Create a socket for the client
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    // Create a socket for the web server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    // Bind the client socket to a port
    struct sockaddr_in client_addr;
    memset(&client_addr, 0, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    client_addr.sin_port = htons(port);
    bind(client_socket, (struct sockaddr*)&client_addr, sizeof(client_addr));
    
    // Listen for incoming connections from the client
    listen(client_socket, 5);
  
    while (1) {
        // Accept an incoming connection from the client
        int client_conn = accept(client_socket, NULL, NULL);
        
        // Connect to the web server
        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        server_addr.sin_port = htons(80);
        int server_conn = connect(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
        
        // Forward data from the client to the server
        char buffer[BUFFER_SIZE];
        int bytes_read;
        while ((bytes_read = recv(client_conn, buffer, BUFFER_SIZE, 0)) > 0) {
            send(server_conn, buffer, bytes_read, 0);
        }
        
        // Forward data from the server to the client
        while ((bytes_read = recv(server_conn, buffer, BUFFER_SIZE, 0)) > 0) {
            send(client_conn, buffer, bytes_read, 0);
        }
        
        // Close the connections
        close(client_conn);
        close(server_conn);
    }
    
    // Close the sockets
    close(client_socket);
    close(server_socket);
    
    return 0;
}