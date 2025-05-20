//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Connect to the server
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send a login command
    char buf[BUF_SIZE];
    snprintf(buf, BUF_SIZE, "LOGIN \"username\" \"password\"\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the response from the server
    memset(buf, 0, BUF_SIZE);
    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
        perror("recv");
        return 1;
    }

    // Print the response
    printf("%s", buf);

    // Send a SELECT command
    snprintf(buf, BUF_SIZE, "SELECT \"INBOX\"\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the response from the server
    memset(buf, 0, BUF_SIZE);
    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
        perror("recv");
        return 1;
    }

    // Print the response
    printf("%s", buf);

    // Send a QUIT command
    snprintf(buf, BUF_SIZE, "QUIT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}