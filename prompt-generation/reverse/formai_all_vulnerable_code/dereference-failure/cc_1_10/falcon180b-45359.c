//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT 8080
#define SERVER_ADDRESS "localhost"
#define SERVER_PORT "8080"

int main() {
    int sockfd, newsockfd, portno, clilen, ret, sd;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char *message;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set server address and port
    server = gethostbyname(SERVER_ADDRESS);
    if (server == NULL) {
        fprintf(stderr, "No such host. ");
        exit(EXIT_FAILURE);
    }
    bcopy(server->h_addr, &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Send message to server
    message = "Hello, server!";
    send(sockfd, message, strlen(message), 0);

    // Receive message from server
    bzero(buffer, BUFFER_SIZE);
    ret = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (ret < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    printf("Received message: %s\n", buffer);

    // Close socket
    close(sockfd);
    exit(EXIT_SUCCESS);
}