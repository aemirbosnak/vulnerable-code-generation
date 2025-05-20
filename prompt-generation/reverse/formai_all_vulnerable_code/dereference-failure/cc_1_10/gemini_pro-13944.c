//GEMINI-pro DATASET v1.0 Category: Browser Plugin ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Function to handle client requests
void handle_client(int sockfd) {
    int n;
    char buffer[256];

    while (1) {
        // Read the request from the client
        n = read(sockfd, buffer, 255);
        if (n < 0) {
            perror("Error reading from client");
            close(sockfd);
            return;
        }

        // Process the request
        if (strcmp(buffer, "quit") == 0) {
            // Client wants to quit, so close the connection
            close(sockfd);
            return;
        } else {
            // Send the response back to the client
            n = write(sockfd, buffer, strlen(buffer));
            if (n < 0) {
                perror("Error writing to client");
                close(sockfd);
                return;
            }
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;

    // Check the number of arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // Parse the port number
    portno = atoi(argv[1]);

    // Create a new socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set the server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("Error listening for connections");
        exit(1);
    }

    // Accept incoming connections
    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("Error accepting connection");
            continue;
        }

        // Handle the client request in a separate thread
        pid_t pid = fork();
        if (pid == 0) {
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