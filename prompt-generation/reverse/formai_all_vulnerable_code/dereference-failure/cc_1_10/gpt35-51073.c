//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: puzzling
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check for correct number of command line arguments
    if (argc != 4) {
        printf("Missing arguments: ./puzzle_server <ip> <port> <msg>\n");
        return 1;
    }

    // Create socket file descriptor
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        return 1;
    }

    // Convert IP address string to network byte order
    struct sockaddr_in server_addr;
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("inet_pton failed");
        return 1;
    }

    // Set port and address family
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_family = AF_INET;

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        return 1;
    }

    // Send message to server
    char *msg = argv[3];
    if (write(sockfd, msg, strlen(msg)) < 0) {
        perror("write failed");
        return 1;
    }

    // Receive message from server
    char buffer[1024] = {0};
    if (read(sockfd, buffer, 1024) < 0) {
        perror("read failed");
        return 1;
    }

    // Print server's response
    printf("%s\n", buffer);

    // Close socket file descriptor
    close(sockfd);

    return 0;
}