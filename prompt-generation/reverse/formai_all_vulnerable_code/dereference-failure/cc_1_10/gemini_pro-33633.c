//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Handle a client connection
void handle_client(int sockfd) {
    char buffer[1024];
    int n;

    // Read the request from the client
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("Error reading from socket");
        return;
    }

    // Parse the request
    char *method = strtok(buffer, " ");
    char *path = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");

    // Check if the request is valid
    if (strcmp(method, "GET") != 0) {
        printf("Invalid method: %s\n", method);
        return;
    }
    if (strcmp(path, "/") != 0) {
        printf("Invalid path: %s\n", path);
        return;
    }
    if (strcmp(version, "HTTP/1.1") != 0) {
        printf("Invalid version: %s\n", version);
        return;
    }

    // Send the response to the client
    char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>Hello, world!</h1>";
    n = write(sockfd, response, strlen(response));
    if (n < 0) {
        perror("Error writing to socket");
        return;
    }

    // Close the connection
    close(sockfd);
}

// Main function
int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;

    // Check if the user has provided a port number
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Get the port number from the user
    portno = atoi(argv[1]);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Set the socket options
    int optval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    // Bind the socket to the port number
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket");
        return 1;
    }

    // Listen for incoming connections
    listen(sockfd, 5);

    // Accept incoming connections
    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("Error accepting connection");
            return 1;
        }

        // Handle the client connection in a separate thread
        pid_t pid = fork();
        if (pid < 0) {
            perror("Error creating thread");
            return 1;
        } else if (pid == 0) {
            // This is the child process
            close(sockfd);
            handle_client(newsockfd);
            exit(0);
        } else {
            // This is the parent process
            close(newsockfd);
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}