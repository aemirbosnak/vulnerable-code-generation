//GEMINI-pro DATASET v1.0 Category: Networking ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP address> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sockfd;
    struct sockaddr_in serveraddr;

    // Create a socket.
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set up the server address.
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(atoi(argv[2]));
    if (inet_aton(argv[1], &serveraddr.sin_addr) == 0) {
        fprintf(stderr, "Invalid IP address: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Connect to the server.
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send a message to the server.
    const char *message = "Hello, world!\n";
    if (send(sockfd, message, strlen(message), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive a response from the server.
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the response.
    printf("%s", buffer);

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}