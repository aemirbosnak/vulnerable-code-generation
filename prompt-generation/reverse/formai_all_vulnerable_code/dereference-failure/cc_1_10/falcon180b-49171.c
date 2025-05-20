//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, ret;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUF_SIZE];

    if (argc!= 2) {
        fprintf(stderr, "Usage:./server <port>\n");
        exit(1);
    }

    portno = atoi(argv[1]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error_handling("socket failed");
    }

    puts("Socket created");

    // Set up the server address structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind the server address to the socket
    ret = bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret == -1) {
        error_handling("bind failed");
    }

    puts("Server address bound to socket");

    // Listen for incoming connections
    ret = listen(sockfd, 10);
    if (ret == -1) {
        error_handling("listen");
    }

    puts("Server is listening");

    // Accept a connection
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd == -1) {
        error_handling("accept");
    }

    puts("Connection accepted");

    // Send a welcome message to the client
    send(newsockfd, "Welcome to the server\n", strlen("Welcome to the server\n"), 0);

    // Receive a message from the client
    ret = recv(newsockfd, buffer, BUF_SIZE, 0);
    if (ret == -1) {
        error_handling("recv");
    }

    puts("Message received from client:");
    printf("%s\n", buffer);

    // Close the sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}

void error_handling(char *message) {
    perror(message);
    exit(1);
}