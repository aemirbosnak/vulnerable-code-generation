//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <target_ip> <target_port>\n", argv[0]);
        return 1;
    }

    int sockfd;
    struct sockaddr_in server_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 2;
    }

    // Set the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 3;
    }

    // Send a message to the server
    char *message = "Hello from the port scanner!\n";
    if (send(sockfd, message, strlen(message), 0) == -1) {
        perror("send");
        return 4;
    }

    // Receive a message from the server
    char *buffer = malloc(1024);
    if (recv(sockfd, buffer, 1024, 0) == -1) {
        perror("recv");
        return 5;
    }

    // Print the message from the server
    printf("Received from the server: %s\n", buffer);

    // Close the socket
    close(sockfd);
    free(buffer);

    return 0;
}