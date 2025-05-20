//FormAI DATASET v1.0 Category: Firewall ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 256
#define ALLOWED_IP "192.168.0.5"
#define BLOCKED_IP "192.168.0.10"

int main(int argc, char *argv[]) {
    char buffer[MAX_BUFFER_SIZE];
    int sockfd, connfd, msg_len;
    struct sockaddr_in servaddr, cliaddr;

    // Creating socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Clearing memory of the server address structure
    memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8080);

    // Binding the socket with server address
    if ((bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) {
        perror("Socket bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening and accepting incoming connections
    if ((listen(sockfd, 5)) != 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    while(1) {
        socklen_t len = sizeof(cliaddr);

        connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len);
        if (connfd < 0) {
            perror("Connection accept failed");
            exit(EXIT_FAILURE);
        }

        // Convert IP address of client to string for easier handling
        char *ip_str = inet_ntoa(cliaddr.sin_addr);

        // Check if client IP is allowed or blocked
        if (strcmp(ip_str, ALLOWED_IP) == 0) {
            printf("Allowed connection from %s\n", ip_str);
            msg_len = snprintf(buffer, MAX_BUFFER_SIZE, "Welcome to my server, %s\n", ip_str);
        } else if (strcmp(ip_str, BLOCKED_IP) == 0) {
            printf("Blocked connection from %s\n", ip_str);
            msg_len = snprintf(buffer, MAX_BUFFER_SIZE, "Your IP is blocked, %s\n", ip_str);
        } else {
            printf("Blocked connection from %s\n", ip_str);
            msg_len = snprintf(buffer, MAX_BUFFER_SIZE, "Access denied, %s\n", ip_str);
        }

        // Send message to client
        send(connfd, buffer, msg_len, 0);

        // Close current connection
        close(connfd);
    }

    // Close socket
    close(sockfd);

    return 0;
}