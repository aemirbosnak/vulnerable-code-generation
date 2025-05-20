//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main() {
    int sockfd, newsockfd, portno, clilen, i;
    char buffer[BUF_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    puts("Socket created");

    // Set the server address
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(12345);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    puts("Connected to server");

    // Send data to the server
    send(sockfd, "Hello, world!", strlen("Hello, world! "), 0);

    // Receive data from the server
    if ((newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen)) < 0) {
        perror("accept failed");
        exit(1);
    }

    puts("Connection accepted");

    while (1) {
        bzero(buffer, BUF_SIZE);
        if (recv(newsockfd, buffer, BUF_SIZE, 0) <= 0) {
            puts("Connection closed by client");
            close(newsockfd);
            exit(0);
        }
        printf("Received message: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}