//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_address;
    struct hostent *server;
    char buffer[BUFFER_SIZE + 1];

    // Check if the user provided the server hostname and port
    if (argc < 3) {
        printf("Usage: %s server_hostname server_port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the hostname and port from the command line arguments
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Resolve the server hostname to its IP address
    server = gethostbyname(hostname);
    if (server == NULL) {
        printf("Error: Could not resolve hostname\n");
        exit(EXIT_FAILURE);
    }

    // Create a socket for communication with the server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Could not create socket\n");
        exit(EXIT_FAILURE);
    }

    // Fill in the server address structure
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(port);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Error: Could not connect to server\n");
        exit(EXIT_FAILURE);
    }

    // Read the welcome message from the server
    bzero(buffer, BUFFER_SIZE + 1);
    if (read(sockfd, buffer, BUFFER_SIZE) < 0) {
        printf("Error: Could not read server response\n");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Send the IMAP login command to the server
    char *login_command = "LOGIN username password";
    if (send(sockfd, login_command, strlen(login_command), 0) < 0) {
        printf("Error: Could not send login command to server\n");
        exit(EXIT_FAILURE);
    }

    // Read the server response to the login command
    bzero(buffer, BUFFER_SIZE + 1);
    if (read(sockfd, buffer, BUFFER_SIZE) < 0) {
        printf("Error: Could not read server response\n");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Send the IMAP logout command to the server
    char *logout_command = "LOGOUT";
    if (send(sockfd, logout_command, strlen(logout_command), 0) < 0) {
        printf("Error: Could not send logout command to server\n");
        exit(EXIT_FAILURE);
    }

    // Read the server response to the logout command
    bzero(buffer, BUFFER_SIZE + 1);
    if (read(sockfd, buffer, BUFFER_SIZE) < 0) {
        printf("Error: Could not read server response\n");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}