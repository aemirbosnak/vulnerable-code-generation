//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function declarations
void recursive_send(int sockfd, char buffer[]);

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    char *hostname, buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Check command-line arguments
    if (argc < 3) {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(0);
    }

    hostname = argv[1];
    portno = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR: opening socket\n");
        exit(1);
    }

    // Get server details
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR: no such host %s\n", hostname);
        exit(0);
    }

    // Load server details into serv_addr
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "ERROR: connecting to server\n");
        exit(1);
    }

    // Recursive send data to server
    recursive_send(sockfd, buffer);

    // Close socket
    close(sockfd);

    return 0;
}

void recursive_send(int sockfd, char buffer[]) {
    int n;

    // Get data from user
    printf("Enter message to server: ");
    fgets(buffer, BUFFER_SIZE, stdin);

    // Remove newline character from input
    buffer[strcspn(buffer, "\n")] = 0;

    // Send data to server
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "ERROR: writing to socket\n");
        exit(1);
    }

    // Check if user wants to send more data
    printf("Do you want to send another message? (y/n): ");
    fgets(buffer, BUFFER_SIZE, stdin);

    // Remove newline character from input
    buffer[strcspn(buffer, "\n")] = 0;

    // If user wants to send more data, recursive call to this function
    if (strcmp(buffer, "y") == 0) {
        recursive_send(sockfd, buffer);
    }
}