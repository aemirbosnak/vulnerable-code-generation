//GEMINI-pro DATASET v1.0 Category: Networking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the host and port number from the command line arguments
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Create a socket for communication
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Setup the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send a message to the server
    char buffer[MAX_BUFFER_SIZE];
    strcpy(buffer, "Hello world!");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive a message from the server
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the received message
    printf("Received: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}