//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(1);
    }

    // Set up the address struct
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    // Send data
    char message[100];
    snprintf(message, sizeof(message), "Hello, world!");
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("send failed");
        exit(1);
    }

    // Receive data
    char buffer[100];
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv failed");
        exit(1);
    }

    // Print the received data
    printf("Received: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}