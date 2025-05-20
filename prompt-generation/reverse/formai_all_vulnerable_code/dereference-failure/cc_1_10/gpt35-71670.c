//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n, port;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    // Check command line arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server-address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get port number
    port = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        perror("Error setting server address");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    while (1) {
        // Read user input
        printf("ftp> ");
        fgets(buffer, BUFFER_SIZE, stdin);

        // Send command to server
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            perror("Error writing to socket");
            exit(EXIT_FAILURE);
        }

        // Process response from server
        memset(buffer, 0, BUFFER_SIZE);
        n = read(sockfd, buffer, BUFFER_SIZE - 1);
        if (n < 0) {
            perror("Error reading from socket");
            exit(EXIT_FAILURE);
        }

        printf("%s", buffer);
    }

    // Close socket
    close(sockfd);

    return 0;
}