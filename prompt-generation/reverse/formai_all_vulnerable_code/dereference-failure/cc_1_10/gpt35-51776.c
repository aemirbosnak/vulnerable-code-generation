//FormAI DATASET v1.0 Category: Simple Web Server ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    int server_fd, client_fd, port_num, opt = 1;
    struct sockaddr_in address;

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Initialize server address
    port_num = atoi(argv[1]);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port_num);

    // Bind socket to address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("\nListening on port %d...\n\n", port_num);

    while (1) {
        // Accept incoming connection
        if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&address)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        char buffer[1024] = {0};
        int valread = read(client_fd, buffer, 1024);
        printf("Request Received: %s\n", buffer);
        char *response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Welcome to my server</h1></body></html>";
        send(client_fd, response, strlen(response), 0);
        printf("Response Sent: %s\n\n", response);

        close(client_fd);
    }

    return 0;
}