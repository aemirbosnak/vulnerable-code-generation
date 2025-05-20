//Gemma-7B DATASET v1.0 Category: Chat server ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/errno.h>

#define MAX_CLIENTS 10

int main() {
    int sockfd, newsockfd, client_fd[MAX_CLIENTS], socklen = sizeof(client_fd), i;
    char msg[256], username[256];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    if (bind(sockfd, NULL, 0) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    listen(sockfd, MAX_CLIENTS);

    // Accept clients
    for (i = 0; i < MAX_CLIENTS; i++) {
        newsockfd = accept(sockfd, NULL, NULL);
        if (newsockfd < 0) {
            perror("Error accepting client");
            continue;
        }

        // Get the client's username
        recv(newsockfd, username, 256, 0);

        // Send a welcome message to the client
        sprintf(msg, "Welcome, %s!", username);
        send(newsockfd, msg, strlen(msg), 0);

        // Close the client's socket
        close(newsockfd);
    }

    return 0;
}