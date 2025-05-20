//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 8192

void proxy(int client_fd, struct sockaddr_in serv_addr)
{
    // Create socket for server connection
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    
    // Connect to server
    if (connect(server_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        return;
    }
    
    // Initialize buffer
    char buf[BUFSIZE];
    memset(buf, 0, BUFSIZE);
    
    // Forward request from client to server
    int bytes_read = recv(client_fd, buf, BUFSIZE, 0);
    send(server_fd, buf, bytes_read, 0);
    
    // Forward response from server to client
    memset(buf, 0, BUFSIZE);
    bytes_read = recv(server_fd, buf, BUFSIZE, 0);
    send(client_fd, buf, bytes_read, 0);
    
    // Close sockets
    close(client_fd);
    close(server_fd);
}

int main(int argc, char *argv[])
{
    // Parse command-line arguments
    if (argc != 3) {
        printf("Usage: %s <proxy_port> <server_ip>\n", argv[0]);
        exit(1);
    }
    int proxy_port = atoi(argv[1]);
    char *server_ip = argv[2];
    
    // Create socket for proxy
    int proxy_fd = socket(AF_INET, SOCK_STREAM, 0);
    
    // Bind socket to port
    struct sockaddr_in proxy_addr;
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    proxy_addr.sin_port = htons(proxy_port);
    if (bind(proxy_fd, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Error binding to port");
        exit(1);
    }
    
    // Listen for connections
    listen(proxy_fd, SOMAXCONN);
    printf("Proxy listening on port %d...\n", proxy_port);
    
    // Accept and handle connections
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_fd = accept(proxy_fd, (struct sockaddr *)&client_addr, &client_len);
        if (client_fd < 0) {
            perror("Error accepting connection");
            continue;
        }
        printf("Accepted connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        struct sockaddr_in serv_addr;
        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = inet_addr(server_ip);
        serv_addr.sin_port = htons(80);
        proxy(client_fd, serv_addr);
    }
    
    return 0;
}