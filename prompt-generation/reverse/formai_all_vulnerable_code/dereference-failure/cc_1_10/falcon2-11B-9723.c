//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: futuristic
// The year is 2121, and the internet has evolved beyond our wildest dreams.
// But even in this new world, the need for a proxy remains.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>

// Global variables
int server_fd, client_fd;
struct sockaddr_in server_addr, client_addr;
char buffer[4096];

void proxy_request(int client_fd, char *request) {
    // Send request to server
    write(client_fd, request, strlen(request));

    // Receive response from server
    int response_len = read(client_fd, buffer, sizeof(buffer));
    if (response_len < 0) {
        perror("Error reading response from server");
        exit(1);
    }
    buffer[response_len] = '\0';

    // Send response back to client
    write(client_fd, buffer, response_len);
}

int main(int argc, char *argv[]) {
    // Parse command line arguments
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", argv[0]);
        exit(1);
    }
    char *server_ip = argv[1];
    unsigned short server_port = atoi(argv[2]);

    // Create socket for communication with server
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set up server address and connect to server
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);
    if (connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Create socket for communication with client
    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set up client address and bind to port
    memset(&client_addr, 0, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(0);
    inet_pton(AF_INET, "127.0.0.1", &client_addr.sin_addr);
    if (bind(client_fd, (struct sockaddr *)&client_addr, sizeof(client_addr)) < 0) {
        perror("Error binding to port");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(client_fd, 5) < 0) {
        perror("Error listening for connections");
        exit(1);
    }

    // Accept incoming connection from client
    struct sockaddr_in client_addr_in;
    socklen_t client_addr_size = sizeof(client_addr_in);
    client_fd = accept(client_fd, (struct sockaddr *)&client_addr_in, &client_addr_size);
    if (client_fd < 0) {
        perror("Error accepting connection");
        exit(1);
    }

    // Forward requests to server
    while (1) {
        // Receive request from client
        int request_len = read(client_fd, buffer, sizeof(buffer));
        if (request_len < 0) {
            perror("Error reading request from client");
            exit(1);
        }
        buffer[request_len] = '\0';

        // Send request to server
        proxy_request(server_fd, buffer);

        // Receive response from server
        int response_len = read(server_fd, buffer, sizeof(buffer));
        if (response_len < 0) {
            perror("Error reading response from server");
            exit(1);
        }
        buffer[response_len] = '\0';

        // Send response back to client
        write(client_fd, buffer, response_len);
    }

    // Close sockets
    close(client_fd);
    close(server_fd);

    return 0;
}