//MISTRAL-7B DATASET v1.0 Category: TCP/IP Programming ; Style: enthusiastic
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd, new_sockfd, numbytes;
    struct sockaddr_in server_addr;
    struct hostent *server;

    // Initialize socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    printf("Socket created\n");

    // Get server address
    server = gethostbyname("localhost"); // Replace with the server IP address
    if (server == NULL) {
        fprintf(stderr, "Error: Unknown host\n");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(SERVER_PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting");
        exit(EXIT_FAILURE);
    }

    printf("Connected to the server\n");

    // Send request for current time
    char request[32] = "TIME\0";
    send(sockfd, request, strlen(request), 0);
    printf("Sent request for current time to server\n");

    // Receive response
    char response[BUFFER_SIZE];
    numbytes = recv(sockfd, response, BUFFER_SIZE, 0);
    if (numbytes <= 0) {
        perror("Error receiving data");
        exit(EXIT_FAILURE);
    }

    response[numbytes] = '\0';
    printf("Received response from server:\n%s\n", response);

    // Close connection
    close(sockfd);
    printf("Connection closed\n");

    return EXIT_SUCCESS;
}