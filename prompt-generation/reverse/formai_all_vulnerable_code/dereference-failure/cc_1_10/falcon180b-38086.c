//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXLINE 4096
#define PORT "8080"

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAXLINE];
    struct hostent *server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set the reuse address option
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "No such host.\n");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    portno = atoi(PORT);
    serv_addr.sin_port = htons(portno);

    // Connect
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server...\n");

    // Listen for incoming connections
    listen(sockfd, 5);
    printf("Waiting for incoming connections...\n");

    while (1) {
        // Accept a connection
        newsockfd = accept(sockfd, (struct sockaddr *)NULL, NULL);
        if (newsockfd < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("New connection...\n");

        // Send welcome message to client
        send(newsockfd, "Welcome to the server!\n", 24, 0);

        // Receive message from client
        n = recv(newsockfd, buffer, MAXLINE, 0);
        if (n < 0) {
            perror("recv");
            exit(EXIT_FAILURE);
        }

        printf("Received message: %s\n", buffer);

        // Send message back to client
        send(newsockfd, buffer, n, 0);

        // Close connection
        close(newsockfd);
    }

    return 0;
}