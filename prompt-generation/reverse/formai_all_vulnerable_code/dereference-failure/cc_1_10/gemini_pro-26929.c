//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Error handling
#define DIE(msg) { perror(msg); exit(EXIT_FAILURE); }

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        DIE("socket");
    }

    // Set up the address of the server
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) != 1) {
        DIE("inet_pton");
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        DIE("connect");
    }

    // Send data to the server
    const char *data = "Hello from client!";
    ssize_t sent_bytes = send(sockfd, data, strlen(data), 0);
    if (sent_bytes == -1) {
        DIE("send");
    }

    // Receive data from the server
    char buffer[1024];
    ssize_t received_bytes = recv(sockfd, buffer, sizeof(buffer), 0);
    if (received_bytes == -1) {
        DIE("recv");
    }

    // Print the data received from the server
    printf("Received from server: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}