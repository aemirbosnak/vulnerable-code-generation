//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    int opt = 1;
    char buffer[BUFFER_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed: %s\n", strerror(errno));
        exit(1);
    }

    // Set socket options
    if (setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, &opt, sizeof(opt))) {
        printf("Error setting socket option: %s\n", strerror(errno));
        exit(1);
    }

    // Connect to server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Connection failed: %s\n", strerror(errno));
        exit(1);
    }

    // Send data to server
    while (1) {
        printf("Enter message to send: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
            printf("Send failed: %s\n", strerror(errno));
            exit(1);
        }
    }

    // Close socket
    close(sockfd);
    return 0;
}