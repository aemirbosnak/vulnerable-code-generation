//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LINE_SIZE 1024
#define POP3_PORT 110
#define USER_NAME "your_username"
#define USER_PASSWORD "your_password"

int main() {
    int sockfd;
    struct addrinfo *serverinfo;
    char buffer[MAX_LINE_SIZE];
    char *token;
    char *user_name = USER_NAME;
    char *user_password = USER_PASSWORD;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set up the server address
    struct addrinfo hints = {0};
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    if (getaddrinfo("localhost", NULL, &hints, &serverinfo)!= 0) {
        perror("getaddrinfo");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, serverinfo->ai_addr, serverinfo->ai_addrlen) == -1) {
        perror("connect");
        exit(1);
    }

    // Send the USER command
    snprintf(buffer, MAX_LINE_SIZE, "USER %s\r\n", user_name);
    send(sockfd, buffer, strlen(buffer), 0);

    // Send the PASS command
    snprintf(buffer, MAX_LINE_SIZE, "PASS %s\r\n", user_password);
    send(sockfd, buffer, strlen(buffer), 0);

    // Send the STAT command
    snprintf(buffer, MAX_LINE_SIZE, "STAT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive the response
    memset(buffer, 0, MAX_LINE_SIZE);
    if (recv(sockfd, buffer, MAX_LINE_SIZE, 0) == -1) {
        perror("recv");
        exit(1);
    }

    // Print the response
    printf("POP3 server response:\n%s", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}