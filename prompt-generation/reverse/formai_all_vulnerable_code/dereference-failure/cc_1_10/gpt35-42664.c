//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 100

int main(int argc, char *argv[]) {
    // Initialize variables
    int sockfd;
    struct sockaddr_in server_address;
    char line[MAX_LINE_LENGTH];

    // Verify correct number of arguments
    if (argc != 3) {
        printf("Usage: %s <server_address> <port>\n", argv[0]);
        return 1;
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Set server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    // Send mail header
    char *from_address = "me@mail.com";
    char *to_address = "you@mail.com";
    char *subject = "Testing SMTP Client";
    sprintf(line, "MAIL FROM:<%s>\r\n", from_address);
    send(sockfd, line, strlen(line), 0);
    sprintf(line, "RCPT TO:<%s>\r\n", to_address);
    send(sockfd, line, strlen(line), 0);
    sprintf(line, "DATA\r\n");
    send(sockfd, line, strlen(line), 0);
    sprintf(line, "Subject: %s\r\n", subject);
    send(sockfd, line, strlen(line), 0);

    // Send mail body
    char *body = "Hello there!";
    sprintf(line, "%s\r\n.\r\n", body);
    send(sockfd, line, strlen(line), 0);

    // Close connection
    sprintf(line, "QUIT\r\n");
    send(sockfd, line, strlen(line), 0);
    close(sockfd);

    return 0;
}