//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[256];
    char *hello = "Hello, server!";

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    if (inet_aton(argv[2], &serv_addr.sin_addr) == 0) {
        perror("inet_aton");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Send greeting message
    if (send(sockfd, hello, strlen(hello), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // Receive reply message
    bzero(buffer, sizeof(buffer));
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }

    // Print reply message
    printf("%s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}