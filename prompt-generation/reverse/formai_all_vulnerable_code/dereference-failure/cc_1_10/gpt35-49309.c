//FormAI DATASET v1.0 Category: Client Server Application ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_BUFFER_SIZE 1024

void error(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    // Check for correct command-line usage
    if (argc < 2) {
        fprintf(stderr, "Error: Please provide a port number.\n");
        exit(1);
    }

    // Initialize socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error: Could not create socket.");
    }

    // Clear and set server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind socket to server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Error: Could not bind socket to address.");
    }

    // Listen for client connections
    listen(sockfd, 5);

    while (1) {
        // Accept new connection
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            error("Error: Could not accept connection from client.");
        }

        // Spawn child process to handle client request
        int pid = fork();
        if (pid < 0) {
            error("Error: Could not create new process to handle client request.");
        } else if (pid == 0) {
            // Child process
            close(sockfd);

            // Receive message from client
            memset(buffer, 0, MAX_BUFFER_SIZE);
            n = read(newsockfd, buffer, MAX_BUFFER_SIZE - 1);
            if (n < 0) {
                error("Error: Could not read message from client.");
            }

            // Process message
            printf("Message received: %s\n", buffer);
            char* response = "Server received your message.";

            // Send response to client
            n = write(newsockfd, response, strlen(response));
            if (n < 0) {
                error("Error: Could not send response to client.");
            }

            exit(0);
        } else {
            // Parent process
            close(newsockfd);
        }
    }

    close(sockfd);
    return 0;
}