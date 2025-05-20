//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <server IP address> <port> <message>\n", argv[0]);
        return 1;
    }

    int sockfd;
    struct sockaddr_in servaddr;

    // Create a socket for connecting to the server
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return 1;
    }

    // Set up the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send the message to the server
    int len = strlen(argv[3]);
    if (send(sockfd, argv[3], len, 0) != len) {
        perror("send");
        return 1;
    }

    // Receive the response from the server
    char buf[MAX_LINE];
    int n;
    if ((n = recv(sockfd, buf, MAX_LINE, 0)) < 0) {
        perror("recv");
        return 1;
    }

    // Print the response from the server
    buf[n] = '\0';
    printf("Received: %s\n", buf);

    // Close the socket
    close(sockfd);

    return 0;
}