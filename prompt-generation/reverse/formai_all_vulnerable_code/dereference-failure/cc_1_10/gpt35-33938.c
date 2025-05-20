//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

// Define the maximum buffer size
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc != 4) {
        fprintf(stderr, "Usage: %s server_ip server_port recipient_email_address\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Initialize variables
    char buffer[MAX_BUFFER_SIZE];
    int sockfd, n;
    struct sockaddr_in servaddr;

    // Create the socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("Address conversion error");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Connection error");
        exit(EXIT_FAILURE);
    }

    // Initialize the SMTP conversation
    recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Send the HELO command
    char *helo_message = "HELO client\r\n";
    send(sockfd, helo_message, strlen(helo_message), 0);
    recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Send the MAIL FROM command
    char *mail_from_message = "MAIL FROM: <sender_email_address>\r\n";
    send(sockfd, mail_from_message, strlen(mail_from_message), 0);
    recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Send the RCPT TO command
    char rcpt_to_message[MAX_BUFFER_SIZE];
    sprintf(rcpt_to_message, "RCPT TO: <%s>\r\n", argv[3]);
    send(sockfd, rcpt_to_message, strlen(rcpt_to_message), 0);
    recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Send the DATA command
    char *data_message = "DATA\r\n";
    send(sockfd, data_message, strlen(data_message), 0);
    recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Send the mail content
    char mail_content[MAX_BUFFER_SIZE];
    printf("Please enter the mail content: ");
    fgets(mail_content, MAX_BUFFER_SIZE, stdin);
    send(sockfd, mail_content, strlen(mail_content), 0);
    send(sockfd, "\r\n.\r\n", strlen("\r\n.\r\n"), 0);
    recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Send the QUIT command
    char *quit_message = "QUIT\r\n";
    send(sockfd, quit_message, strlen(quit_message), 0);
    recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}