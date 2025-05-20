//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAXLINE 1024

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    // Get the host and port numbers.
    char *host = argv[1];
    int port = atoi(argv[2]);

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Connect to the server.
    struct hostent *he = gethostbyname(host);
    if (he == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    memcpy(&servaddr.sin_addr, he->h_addr, he->h_length);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Send a message to the server.
    char *message = "Hello, world!";
    if (send(sockfd, message, strlen(message), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive a message from the server.
    char buffer[MAXLINE];
    if (recv(sockfd, buffer, MAXLINE, 0) == -1) {
        perror("recv");
        exit(1);
    }

    // Print the message from the server.
    printf("%s\n", buffer);

    // Close the socket.
    close(sockfd);

    return 0;
}