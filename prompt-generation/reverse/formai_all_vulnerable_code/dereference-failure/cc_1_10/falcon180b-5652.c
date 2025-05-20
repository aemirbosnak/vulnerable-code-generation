//Falcon-180B DATASET v1.0 Category: Networking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    int addrlen;
    char *hostname;
    char *port;
    struct hostent *server;
    struct timeval timeout;

    // Check if the correct number of arguments are provided
    if (argc!= 4) {
        printf("Usage: %s <hostname> <port> <message>\n", argv[0]);
        exit(1);
    }

    // Get the hostname and port from the command line arguments
    hostname = argv[1];
    port = argv[2];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set the timeout for the socket
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    // Get the server address
    server = gethostbyname(hostname);
    if (server == NULL) {
        printf("Error getting host address\n");
        exit(1);
    }

    // Fill in the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    memcpy(&server_addr.sin_addr, server->h_addr, server->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send the message to the server
    bytes_received = send(sockfd, argv[3], strlen(argv[3]), 0);
    if (bytes_received == -1) {
        printf("Error sending message\n");
        exit(1);
    }

    // Receive the response from the server
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        printf("Error receiving response\n");
        exit(1);
    }

    // Print the response
    printf("Response: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}