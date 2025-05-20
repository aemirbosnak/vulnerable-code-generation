//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Check input arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_address> <server_port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get server address and port
    char *serverAddress = argv[1];
    int serverPort = atoi(argv[2]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to server
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(serverPort);
    if (inet_pton(AF_INET, serverAddress, &serverAddr.sin_addr) <= 0) {
        perror("inet_pton");
        close(sockfd);
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("connect");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Get user input
    char buffer[MAX_BUFFER_SIZE];
    printf("Enter your email address: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);
    strtok(buffer, "\n");

    // Send email address to server
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive response from server
    memset(buffer, 0, MAX_BUFFER_SIZE);
    if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) == -1) {
        perror("recv");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Print response from server
    printf("%s\n", buffer);

    // Close socket
    close(sockfd);

    return EXIT_SUCCESS;
}