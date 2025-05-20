//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 8192

void performRequest(const char *host, const char *path) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];

    // Prepare the socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Oh! The socket creation failed, Watson.\n");
        exit(EXIT_FAILURE);
    }

    // Identify the server by its name
    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "The game is afoot, but I cannot find the server!\n");
        exit(EXIT_FAILURE);
    }

    // Configure the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(80);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Alas! The connection to the server failed.\n");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Prepare the HTTP GET request
    snprintf(buffer, sizeof(buffer), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);

    // Send the request
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        fprintf(stderr, "Oh dear! The sending of the request failed.\n");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive the response
    printf("Watson, let us analyze the server's response:\n");
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        ssize_t bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);

        if (bytes_received < 0) {
            fprintf(stderr, "We have been thwarted by a communication failure!\n");
            break;
        } else if (bytes_received == 0) {
            // Connection has been closed
            break;
        }

        // Output the received data
        printf("%s", buffer);
    }

    // Close the socket
    close(sockfd);
    printf("The case is solved, Watson. We have received the information!\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *host = argv[1];
    const char *path = argv[2];

    printf("Elementary, my dear Watson! We shall fetch information from '%s' at path '%s'.\n", host, path);

    performRequest(host, path);

    return 0;
}