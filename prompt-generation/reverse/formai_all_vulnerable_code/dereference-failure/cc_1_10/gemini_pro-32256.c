//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server> <port> <message>\n", argv[0]);
        exit(1);
    }

    // Get the server address and port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid server address: %s\n", argv[1]);
        exit(1);
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send the message to the server
    char *message = argv[3];
    int len = strlen(message);
    if (send(sockfd, message, len, 0) != len) {
        perror("send");
        exit(1);
    }

    // Receive the response from the server
    char buf[MAX_LINE];
    memset(buf, 0, MAX_LINE);
    int n = recv(sockfd, buf, MAX_LINE - 1, 0);
    if (n < 0) {
        perror("recv");
        exit(1);
    }

    // Print the response from the server
    printf("Received: %s\n", buf);

    // Close the socket
    close(sockfd);

    return 0;
}