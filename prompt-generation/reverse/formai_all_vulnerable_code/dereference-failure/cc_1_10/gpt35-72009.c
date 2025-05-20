//FormAI DATASET v1.0 Category: Networking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int port = 8080;

    // Parse command line arguments
    if (argc < 2) {
        printf("Usage: %s <ip_address> [<port>]\n", argv[0]);
        exit(1);
    }
    if (argc >= 3) {
        port = atoi(argv[2]);
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Set up server address
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        printf("Invalid IP address\n");
        exit(1);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        perror("connection to server failed");
        exit(1);
    }

    char buffer[BUFFER_SIZE];

    while(1) {
        // Prompt user for input
        printf("Enter message: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        // Send message to server
        int bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
        if(bytes_sent == -1) {
            perror("send failed");
            exit(1);
        }

        // Receive response from server
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if(bytes_received == -1) {
            perror("receive failed");
            exit(1);
        }

        // Null-terminate the received message
        buffer[bytes_received] = '\0';

        // Print response from server
        printf("Server response: %s", buffer);
    }

    // Close socket
    close(sockfd);

    return 0;
}