//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // Check command line arguments.
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get server address info.
    struct addrinfo hints;
    struct addrinfo *result;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    getaddrinfo(argv[1], argv[2], &hints, &result);

    // Create a socket.
    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the server.
    if (connect(sockfd, result->ai_addr, result->ai_addrlen) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the POP3 USER command.
    char buf[1024];
    snprintf(buf, sizeof(buf), "USER %s\r\n", argv[3]);
    send(sockfd, buf, strlen(buf), 0);

    // Get the POP3 server response.
    recv(sockfd, buf, sizeof(buf), 0);

    // Send the POP3 PASS command.
    snprintf(buf, sizeof(buf), "PASS %s\r\n", argv[4]);
    send(sockfd, buf, strlen(buf), 0);

    // Get the POP3 server response.
    recv(sockfd, buf, sizeof(buf), 0);

    // Send the POP3 LIST command.
    snprintf(buf, sizeof(buf), "LIST\r\n");
    send(sockfd, buf, strlen(buf), 0);

    // Get the POP3 server response.
    while (recv(sockfd, buf, sizeof(buf), 0) > 0) {
        printf("%s", buf);
    }

    // Send the POP3 QUIT command.
    snprintf(buf, sizeof(buf), "QUIT\r\n");
    send(sockfd, buf, strlen(buf), 0);

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}