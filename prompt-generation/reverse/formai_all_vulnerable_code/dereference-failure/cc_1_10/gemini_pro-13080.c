//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    // Resolving host name to IP address
    struct hostent *host_info = gethostbyname(host);
    if (host_info == NULL) {
        fprintf(stderr, "Error resolving hostname %s\n", host);
        exit(EXIT_FAILURE);
    }

    // Creating a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Initializing server address structure
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *(struct in_addr *)host_info->h_addr;

    // Connecting to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Sending data to the server
    char *message = "Hello from client";
    int len = strlen(message);
    if (send(sockfd, message, len, 0) == -1) {
        perror("Error sending data to server");
        exit(EXIT_FAILURE);
    }

    // Receiving data from the server
    char buffer[1024];
    int recv_len = recv(sockfd, buffer, sizeof(buffer), 0);
    if (recv_len == -1) {
        perror("Error receiving data from server");
        exit(EXIT_FAILURE);
    }

    // Printing the received data
    printf("Received from server: %s\n", buffer);

    // Closing the socket
    close(sockfd);

    return EXIT_SUCCESS;
}