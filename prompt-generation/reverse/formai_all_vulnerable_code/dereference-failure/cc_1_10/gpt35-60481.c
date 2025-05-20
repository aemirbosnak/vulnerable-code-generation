//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
 
#define BUFF_SIZE 1024
 
void error(char *message) {
    perror(message);
    exit(1);
}
 
int main(int argc, char *argv[]) {
    int client_sock, server_sock, client_len, server_len, n;
    struct sockaddr_in client_addr, server_addr;
    char buffer[BUFF_SIZE];
    char ip[INET_ADDRSTRLEN];
 
    // Check if the arguments are passed properly
    if (argc != 3) {
        error("Usage: ./proxy <client_port> <server_port>\n");
    }
 
    // Create client socket
    client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock == -1) {
        error("Error: opening client socket failed.\n");
    }
   
    // Bind client socket to given port
    bzero(&client_addr, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    client_addr.sin_port = htons(atoi(argv[1]));
 
    if(bind(client_sock, (struct sockaddr*)&client_addr, sizeof(client_addr)) == -1) {
        error("Error: binding client socket to port failed.\n");
    }
 
    // Listen for incoming connections from client
    if(listen(client_sock, 10) == -1) {
        error("Error: Unable to listen on client socket.\n");
    }
 
    printf("Proxy is now listening on %s:%s\n", "127.0.0.1", argv[1]);
 
    while(1) {
        client_len = sizeof(client_addr);
 
        // Accept incoming connection from client
        int client_fd = accept(client_sock, (struct sockaddr*)&client_addr, &client_len);
        if (client_fd == -1) {
            error("Error: Unable to accept incoming client connection.\n");
        }
        
        // Get client IP address and port
        if (inet_ntop(AF_INET, &client_addr.sin_addr, ip, sizeof(ip)) == NULL) {
            error("Error: Unable to get client IP address.\n");
        }
 
        printf("Accepted incoming connection from %s:%d\n", ip, ntohs(client_addr.sin_port));
 
        bzero(buffer, BUFF_SIZE);
        n = recv(client_fd, buffer, BUFF_SIZE, 0);
         
        // Create socket to connect to server
        server_sock = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sock == -1) {
            error("Error: Unable to create server socket.\n");
        }
 
        // Set server address
        bzero(&server_addr, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        server_addr.sin_port = htons(atoi(argv[2]));
 
        // Connect to server
        if(connect(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
            error("Error: Unable to connect to server.\n");
        }
 
        // Forward client request to server
        printf("Forwarding request to server: %s\n", buffer);
        write(server_sock, buffer, strlen(buffer));
 
        bzero(buffer, BUFF_SIZE);
 
        // Receive response from server
        int server_n = read(server_sock, buffer, BUFF_SIZE);
        if (server_n <= 0) {
            error("Error: Unable to receive response from server.\n");
        }
        
        // Forward server response to client
        printf("Forwarding response to client: %s\n", buffer);
        write(client_fd, buffer, server_n);
 
        close(client_fd);
        close(server_sock);
    }
 
    return 0;
}