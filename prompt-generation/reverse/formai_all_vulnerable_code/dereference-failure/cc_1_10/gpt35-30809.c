//FormAI DATASET v1.0 Category: Socket programming ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

#define MAXSIZE 1024

int main(int argc, char *argv[]) {

    int sockfd, newsockfd, portno, clilen;
    char buffer[MAXSIZE];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    // Create a new socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Handle errors if the socket creation fails
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set all values in the server address struct to zero
    bzero((char *) &serv_addr, sizeof(serv_addr));

    // Get the port number from the command line arguments
    portno = atoi(argv[1]);

    // Set the values for the server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // Listen for incoming connections
    listen(sockfd, 5);

    clilen = sizeof(cli_addr);

    while(1) {
        // Accept incoming connections
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

        // Handle errors if accepting a connection fails
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        // Fork a new process to handle the incoming connection
        int pid = fork();

        if (pid < 0) {
            perror("ERROR on fork");
            exit(1);
        }

        if (pid == 0) {
            // We are in the child process

            // Close the original socket
            close(sockfd);

            // Clear the buffer
            bzero(buffer, MAXSIZE);

            // Read data from the socket
            n = read(newsockfd, buffer, MAXSIZE);

            // Handle errors if reading from the socket fails
            if (n < 0) {
                perror("ERROR reading from socket");
                exit(1);
            }

            // Print the message received from the client
            printf("Here is the message: %s\n", buffer);

            // Write a message back to the client
            n = write(newsockfd, "I received your message", 23);

            // Handle errors if writing to the socket fails
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }

            // Close the new socket
            close(newsockfd);
            return 0;
        }
        else {
            // We are in the parent process

            // Close the new socket
            close(newsockfd);
        }
    }

    // Close the original socket
    close(sockfd);

    return 0;
}