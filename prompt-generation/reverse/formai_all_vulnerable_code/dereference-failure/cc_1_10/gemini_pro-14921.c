//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip-address> <port-number>\n", argv[0]);
        return 1;
    }

    struct sockaddr_in server_addr;
    int sockfd;

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Set the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        close(sockfd);
        return 1;
    }

    // Send a message to the server
    char *message = "Hello from client!\n";
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("send");
        close(sockfd);
        return 1;
    }

    // Receive a message from the server
    char buffer[256];
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        close(sockfd);
        return 1;
    }

    // Print the message received from the server
    printf("Received message from server: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}