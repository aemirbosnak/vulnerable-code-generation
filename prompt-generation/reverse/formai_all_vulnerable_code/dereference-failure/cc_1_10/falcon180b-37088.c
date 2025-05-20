//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main() {
    int sockfd, newsockfd, portno;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    printf("Futuristic Socket Programming Example\n");

    // Set the server address
    server = gethostbyname("localhost");
    bcopy(server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(12345);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    // Receive messages from server
    while (1) {
        bzero(buffer, BUFFER_SIZE);
        read(sockfd, buffer, BUFFER_SIZE);
        printf("%s", buffer);
    }

    // Close socket
    close(sockfd);
    exit(0);
}