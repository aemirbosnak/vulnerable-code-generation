//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

void die(const char *s) {
    perror(s);
    exit(1);
}

int main(int argc, char **argv) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[BUF_SIZE];
    const char *message =
        "To: postmaster@example.com\r\n"
        "From: sender@example.com\r\n"
        "Subject: Test message\r\n"
        "\r\n"
        "This is a test message.\r\n";

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
        die("socket failed");

    // Set server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
        die("connect failed");

    // Send message
    send(sockfd, message, strlen(message), 0);

    // Receive response
    memset(buffer, '\0', BUF_SIZE);
    recv(sockfd, buffer, BUF_SIZE, 0);

    printf("Response:\n%s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}