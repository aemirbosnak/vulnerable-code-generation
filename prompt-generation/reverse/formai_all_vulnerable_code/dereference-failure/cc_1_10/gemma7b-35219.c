//Gemma-7B DATASET v1.0 Category: Chat server ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/wait.h>

#define MAX_Clients 10

int main()
{
    int sockfd, newsockfd, client_fd[MAX_Clients], i, n, pid;
    char msg[256], username[256], buffer[256];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket
    if (bind(sockfd, NULL, 0) < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    listen(sockfd, MAX_Clients);

    // Accept clients
    for (i = 0; i < MAX_Clients; i++)
    {
        newsockfd = accept(sockfd, NULL, NULL);
        if (newsockfd < 0)
        {
            perror("Error accepting client");
            continue;
        }

        // Get the client's username
        recv(newsockfd, username, 256, 0);

        // Send a welcome message to the client
        sprintf(msg, "Welcome, %s!", username);
        send(newsockfd, msg, strlen(msg), 0);

        // Create a child process for each client
        pid = fork();

        if (pid == 0)
        {
            // Close the socket
            close(newsockfd);

            // Get the client's message
            recv(newsockfd, buffer, 256, 0);

            // Print the client's message
            printf("%s: %s\n", username, buffer);

            // Exit the child process
            exit(0);
        }

        // Close the client socket
        close(newsockfd);
    }

    // Close the server socket
    close(sockfd);

    return 0;
}