//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <errno.h>
#include <signal.h>
#include <netdb.h>

#define MAX_BUFF_SIZE 4096

// Struct to store client information
struct client_info {
    int client_fd;
    struct sockaddr_in client_addr;
};

// Function to handle client requests
void handle_client(struct client_info *client) {
    char buffer[MAX_BUFF_SIZE], host[MAX_BUFF_SIZE];
    int read_size, write_size, port = 80;
    struct hostent *server;
    struct sockaddr_in server_addr;

    // Read data from client
    read_size = read(client->client_fd, buffer, MAX_BUFF_SIZE);
    if (read_size < 0) {
        perror("Error reading from client");
        exit(1);
    }

    // Parse host and port from request headers
    if (sscanf(buffer, "GET http://%[^/]/", host) < 1) {
        perror("Invalid request format");
        exit(1);
    }

    // Check if port is specified in request headers
    if (strchr(host, ':') != NULL) {
        sscanf(host, "%[^:]:%d", host, &port);
    }

    // Get server information using DNS lookup
    server = gethostbyname(host);
    if (server == NULL) {
        perror("Error resolving host");
        exit(1);
    }

    // Create socket file descriptor
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Initialize server address struct
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);

    // Connect to server
    if (connect(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Forward request headers to server
    write_size = write(server_fd, buffer, strlen(buffer));
    if (write_size < 0) {
        perror("Error forwarding request headers");
        exit(1);
    }

    // Forward response data to client
    while ((read_size = read(server_fd, buffer, MAX_BUFF_SIZE)) > 0) {
        write_size = write(client->client_fd, buffer, read_size);
        if (write_size < 0) {
            perror("Error forwarding response data");
            exit(1);
        }
    }

    // Close sockets
    close(server_fd);
    close(client->client_fd);
    free(client);
}

int main(int argc, char *argv[]) {
    int proxy_fd, client_fd, sin_size, pid;
    struct sockaddr_in proxy_addr, client_addr;
    struct client_info *client;

    // Create socket file descriptor
    proxy_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_fd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Initialize proxy address struct
    bzero((char *) &proxy_addr, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_port = htons(8080);
    proxy_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to port
    if (bind(proxy_fd, (struct sockaddr *) &proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(proxy_fd, 5) < 0) {
        perror("Error listening for connections");
        exit(1);
    }

    // Handle incoming connections
    while (1) {
        sin_size = sizeof(struct sockaddr_in);
        client_fd = accept(proxy_fd, (struct sockaddr *) &client_addr, &sin_size);
        if (client_fd < 0) {
            perror("Error accepting connection");
            exit(1);
        }

        // Create client info struct and pass to child process
        client = malloc(sizeof(struct client_info));
        client->client_fd = client_fd;
        client->client_addr = client_addr;
        pid = fork();
        if (pid < 0) {
            perror("Error creating child process");
            exit(1);
        }
        else if (pid == 0) {
            close(proxy_fd);
            handle_client(client);
            exit(0);
        }
        else {
            close(client_fd);
        }
    }

    // Close socket
    close(proxy_fd);
    return 0;
}