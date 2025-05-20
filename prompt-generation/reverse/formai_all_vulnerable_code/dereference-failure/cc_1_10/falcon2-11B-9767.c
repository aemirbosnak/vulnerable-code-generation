//Falcon2-11B DATASET v1.0 Category: Networking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_MESSAGE_LENGTH 1024

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_MESSAGE_LENGTH];

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error opening socket\n");
        exit(EXIT_FAILURE);
    }

    // Set up the address struct for the server
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(EXIT_FAILURE);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(5000);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error connecting\n");
        exit(EXIT_FAILURE);
    }

    // Send data to the server
    printf("Enter a message (up to %d characters): ", MAX_MESSAGE_LENGTH);
    fgets(buffer, MAX_MESSAGE_LENGTH, stdin);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error writing to socket");
        exit(EXIT_FAILURE);
    }

    // Receive data from the server
    n = read(sockfd, buffer, MAX_MESSAGE_LENGTH);
    if (n < 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }
    printf("Received message: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}