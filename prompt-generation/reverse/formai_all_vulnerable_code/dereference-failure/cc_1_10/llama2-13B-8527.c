//LLAMA2-13B DATASET v1.0 Category: Socket programming ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_MIN 1024
#define PORT_MAX 65535
#define IP_ADDR_LEN 16

struct server_config {
    int port;
    char ip_addr[IP_ADDR_LEN];
};

int main(int argc, char *argv[]) {
    struct server_config server;
    struct sockaddr_in server_addr;
    socklen_t client_len = sizeof(struct sockaddr_in);
    int client_fd;

    // Parse command line arguments
    if (argc < 3) {
        printf("Usage: %s <server_ip> <server_port>\n", argv[0]);
        return 1;
    }

    // Set server IP address and port number
    server.port = atoi(argv[2]);
    strcpy(server.ip_addr, argv[1]);

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        return 1;
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server.port);
    inet_pton(AF_INET, server.ip_addr, &server_addr.sin_addr);

    // Bind the socket to the address and port
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        return 1;
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("listen failed");
        return 1;
    }

    // Accept an incoming connection
    client_fd = accept(sock, (struct sockaddr *)NULL, &client_len);
    if (client_fd < 0) {
        perror("accept failed");
        return 1;
    }

    // Read data from the client
    char buffer[1024];
    int bytes_read = read(client_fd, buffer, 1024);
    if (bytes_read < 0) {
        perror("read failed");
        return 1;
    }

    // Print the received data
    printf("Received message: %s\n", buffer);

    // Write a response back to the client
    char *message = "Hello, client!";
    int bytes_written = write(client_fd, message, strlen(message));
    if (bytes_written < 0) {
        perror("write failed");
        return 1;
    }

    // Close the socket
    close(client_fd);

    return 0;
}