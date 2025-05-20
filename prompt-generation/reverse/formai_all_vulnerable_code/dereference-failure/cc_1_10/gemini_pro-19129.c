//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server_address> <server_port> <username>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse the server address and port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_aton(argv[1], &server_addr.sin_addr) == 0) {
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
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the username
    char buf[MAX_BUF_SIZE];
    sprintf(buf, "USER %s\r\n", argv[3]);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response
    if (recv(sockfd, buf, MAX_BUF_SIZE, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check the response
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Invalid response from server: %s\n", buf);
        return EXIT_FAILURE;
    }

    // Print the response
    printf("%s", buf);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}