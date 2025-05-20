//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Recursive function to send a message to a remote host
int send_message(int sockfd, struct sockaddr_in *servaddr, char *msg, int len) {
    // Base case: if the message is empty, return
    if (len == 0) {
        return 0;
    }

    // Send the first byte of the message
    int n = sendto(sockfd, msg, 1, 0, (struct sockaddr *) servaddr, sizeof(*servaddr));
    if (n < 0) {
        perror("sendto");
        return -1;
    }

    // Recursively send the rest of the message
    return send_message(sockfd, servaddr, msg + 1, len - 1);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set the server address
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    // Send a message to the server
    char *msg = "Hello, world!";
    int len = strlen(msg);
    if (send_message(sockfd, &servaddr, msg, len) < 0) {
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}