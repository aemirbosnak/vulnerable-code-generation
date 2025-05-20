//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    // Check if input parameters are valid
    if (argc < 4) {
        printf("Usage: %s <proxy-port> <server-ip> <server-port>\n", argv[0]);
        exit(1);
    }

    // Parse input arguments
    int proxy_port = atoi(argv[1]);
    char* server_ip = argv[2];
    int server_port = atoi(argv[3]);

    // Create socket and initialize variables
    int proxy_fd = socket(AF_INET, SOCK_STREAM, 0);
    int client_fd, server_fd;
    struct sockaddr_in proxy_addr, client_addr, server_addr;
    char buffer[10240];

    // Initialize server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    // Bind socket to address and start listening
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_port = htons(proxy_port);
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    bind(proxy_fd, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr));
    listen(proxy_fd, 5);

    while (1) {
        // Accept incoming connections
        int client_addr_len = sizeof(client_addr);
        client_fd = accept(proxy_fd, (struct sockaddr *)&client_addr, (socklen_t *)&client_addr_len);

        // Connect to server
        server_fd = socket(AF_INET, SOCK_STREAM, 0);
        connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

        // Forward client request to server
        send(server_fd, buffer, recv(client_fd, buffer, sizeof(buffer), 0), 0);

        // Forward server response to client
        send(client_fd, buffer, recv(server_fd, buffer, sizeof(buffer), 0), 0);

        // Close the client and server connections
        close(client_fd);
        close(server_fd);
    }

    return 0;
}