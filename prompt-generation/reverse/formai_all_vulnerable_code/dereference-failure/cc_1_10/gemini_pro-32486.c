//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 1024
#define MAX_MSG 1024

struct email {
    char from[MAX_LINE];
    char to[MAX_LINE];
    char subject[MAX_LINE];
    char body[MAX_MSG];
};

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the server address and port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid server address: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Create an email message
    struct email email;
    strcpy(email.from, "sender@example.com");
    strcpy(email.to, "recipient@example.com");
    strcpy(email.subject, "Test email");
    strcpy(email.body, "This is a test email.");

    // Send the email message to the server
    if (send(sockfd, &email, sizeof(email), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Wait for a response from the server
    char response[MAX_LINE];
    if (recv(sockfd, response, MAX_LINE, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the response from the server
    printf("Response: %s\n", response);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}