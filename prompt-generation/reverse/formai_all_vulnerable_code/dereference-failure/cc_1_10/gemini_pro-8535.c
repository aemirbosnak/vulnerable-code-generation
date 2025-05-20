//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void handle_connection(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;

    while (1) {
        n = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (n <= 0) {
            break;
        }

        // Parse the received data and check for suspicious activity.
        // Here is an example of checking for SQL injection attacks:
        char *ptr = buffer;
        while (*ptr != '\0') {
            if (*ptr == '\'' || *ptr == '"') {
                // Suspicious character found, raise an alert.
                printf("Possible SQL injection attack detected!\n");
                break;
            }
            ptr++;
        }

        // Send a response back to the client.
        n = send(sockfd, "Hello, world!", 13, 0);
        if (n <= 0) {
            break;
        }
    }

    close(sockfd);
}

int main(int argc, char **argv) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;

    // Validate the input arguments.
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // Parse the port number from the command line.
    portno = atoi(argv[1]);

    // Create a socket.
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set the socket options.
    int optval = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        perror("Error setting socket options");
        exit(1);
    }

    // Bind the socket to the specified port.
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for incoming connections.
    if (listen(sockfd, 5) < 0) {
        perror("Error listening for connections");
        exit(1);
    }

    // Accept incoming connections.
    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("Error accepting connection");
            continue;
        }

        // Handle the connection in a separate thread.
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, (void *)handle_connection, (void *)newsockfd);
        pthread_detach(thread_id);
    }

    // Close the socket.
    close(sockfd);

    return 0;
}