//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: secure
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

void error_handling(char *message) {
    perror(message);
    exit(1);
}

int main() {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    socklen_t clilen;
    struct hostent *server;

    portno = 8080;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0) {
        error_handling("Error opening socket");
    }

    // Set the server address
    server = gethostbyname("localhost");
    if (server == NULL) {
        error_handling("Error getting host by name");
    }
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error_handling("Error connecting");
    }

    // Send data to the server
    strcpy(buffer, "Hello, world!");
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive data from the server
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0) {
        error_handling("Error accepting");
    }

    while (1) {
        bzero(buffer, BUFFER_SIZE);
        read(newsockfd, buffer, BUFFER_SIZE);
        printf("Received message: %s\n", buffer);

        if (strcmp(buffer, "quit") == 0) {
            break;
        }
    }

    // Close sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}