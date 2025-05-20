//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: single-threaded
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server IP> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sockfd;
    struct sockaddr_in server_addr;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send LOGIN command
    char buf[MAX_LINE];
    snprintf(buf, MAX_LINE, "LOGIN myusername mypassword\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response
    if (recv(sockfd, buf, MAX_LINE, 0) == 0) {
        fprintf(stderr, "Server disconnected unexpectedly\n");
        return EXIT_FAILURE;
    }

    // Print the response
    printf("%s", buf);

    // Close the socket
    close(sockfd);
    return EXIT_SUCCESS;
}