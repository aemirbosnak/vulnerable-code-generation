//GEMINI-pro DATASET v1.0 Category: Networking ; Style: brave
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

#define PORT 8080
#define MAX_LINE 1024

void print_usage() {
    printf("Usage: ./networking_example [host] [message]\n");
}

int main(int argc, char **argv) {
    if (argc < 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    // Initialize the socket.
    int sockfd = 0;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        return EXIT_FAILURE;
    }

    // Connect to the server.
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton failed");
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect failed");
        return EXIT_FAILURE;
    }

    // Send the message to the server.
    char *message = argv[2];
    int len = strlen(message);
    if (send(sockfd, message, len, 0) != len) {
        perror("send failed");
        return EXIT_FAILURE;
    }

    // Receive the response from the server.
    char buffer[MAX_LINE];
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, MAX_LINE, 0) <= 0) {
        perror("recv failed");
        return EXIT_FAILURE;
    }

    // Print the response.
    printf("%s\n", buffer);

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}