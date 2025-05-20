//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <ip address> <port>\n", argv[0]);
        return 1;
    }

    // Get the IP address and port number from the command line arguments
    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    // Create a socket descriptor
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Set the socket options
    int optval = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
        perror("setsockopt");
        return 1;
    }

    // Create a sockaddr_in structure
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip_address);
    server_addr.sin_port = htons(port_number);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Send a message to the server
    char *message = "Hello, world!\n";
    if (send(sockfd, message, strlen(message), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive a message from the server
    char buffer[1024];
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        return 1;
    }

    // Print the message from the server
    printf("%s", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}