//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define IMAP_PORT 143

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the greeting
    char *greeting = "I AM A TEST CLIENT\r\n";
    if (send(sockfd, greeting, strlen(greeting), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the server's response
    char *response = malloc(1024);
    if (recv(sockfd, response, 1024, 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the server's response
    printf("%s", response);

    // Clean up
    free(response);
    close(sockfd);

    return EXIT_SUCCESS;
}