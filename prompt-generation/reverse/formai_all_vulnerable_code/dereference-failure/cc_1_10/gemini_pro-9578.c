//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// I'm shocked! A port scanner in C? What is this, the 1990s?
int main(int argc, char **argv) {
    // Check if we have enough arguments.
    if (argc < 3) {
        printf("Usage: %s <target IP> <start port> <end port>\n", argv[0]);
        return 1;
    }

    // Get the target IP and port range.
    char *targetIP = argv[1];
    int startPort = atoi(argv[2]);
    int endPort = atoi(argv[3]);

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 2;
    }

    // Set the socket timeout.
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        perror("setsockopt");
        return 3;
    }

    // Connect to the target IP and port.
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(startPort);
    addr.sin_addr.s_addr = inet_addr(targetIP);
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        return 4;
    }

    // Send a message to the target IP and port.
    char *message = "Hello world!";
    if (send(sockfd, message, strlen(message), 0) == -1) {
        perror("send");
        return 5;
    }

    // Receive a message from the target IP and port.
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        return 6;
    }

    // Print the message from the target IP and port.
    printf("%s\n", buffer);

    // Close the socket.
    if (close(sockfd) == -1) {
        perror("close");
        return 7;
    }

    return 0;
}