//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 80 // HTTP Port
#define BUFFER_SIZE 1024 // Size of receive buffer

int main(int argc, char *argv[]) {
    if(argc != 2) { // Check if URL is passed as command line argument
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    char request[BUFFER_SIZE], response[BUFFER_SIZE];
    char *hostname = argv[1], *path = "/";
    struct sockaddr_in server_address;
    struct hostent *server;

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd < 0) { // Check if socket creation failed
        perror("Error creating socket");
        return 1;
    }

    // Get server information
    server = gethostbyname(hostname);
    if(server == NULL) { // Check if server not found
        printf("Could not find server: %s\n", hostname);
        return 1;
    }

    // Set up server address
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    bcopy(server->h_addr, &server_address.sin_addr.s_addr, server->h_length);

    if(connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) { // Check if connection failed
        perror("Error connecting to server");
        return 1;
    }

    // Format HTTP request
    snprintf(request, BUFFER_SIZE, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);

    // Send request to server
    if(write(socket_fd, request, strlen(request)) < 0) { // Check if write failed
        perror("Error writing to socket");
        return 1;
    }

    // Receive response from server
    if(read(socket_fd, response, BUFFER_SIZE) < 0) { // Check if read failed
        perror("Error reading from socket");
        return 1;
    }

    // Print response from server
    printf("%s", response);

    // Close socket
    close(socket_fd);

    return 0;
}