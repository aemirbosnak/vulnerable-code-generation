//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 1024

// Function to send an email
void send_email(char *host, char *port, char *sender, char *recipient, char *subject, char *body) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Connect to the server
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(port));
    serv_addr.sin_addr.s_addr = inet_addr(host);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send the HELO command
    char buffer[MAX_BUFFER_SIZE];
    sprintf(buffer, "HELO %s\r\n", host);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive the server response
    if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    // Send the MAIL FROM command
    sprintf(buffer, "MAIL FROM: <%s>\r\n", sender);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive the server response
    if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    // Send the RCPT TO command
    sprintf(buffer, "RCPT TO: <%s>\r\n", recipient);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive the server response
    if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    // Send the DATA command
    sprintf(buffer, "DATA\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive the server response
    if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    // Send the email body
    sprintf(buffer, "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive the server response
    if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    // Send the QUIT command
    sprintf(buffer, "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Close the socket
    close(sockfd);
}

// Main function
int main(int argc, char **argv) {
    // Check if the correct number of arguments were passed
    if (argc != 8) {
        printf("Usage: %s host port sender recipient subject body\n", argv[0]);
        exit(1);
    }

    // Send the email
    send_email(argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);

    return 0;
}