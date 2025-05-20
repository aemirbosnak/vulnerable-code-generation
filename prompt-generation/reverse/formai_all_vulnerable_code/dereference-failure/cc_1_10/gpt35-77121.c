//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: protected
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1024

int main(int argc, char **argv) {
    char *from, *to, *subject, *message;
    char buf[MAXLINE];
    int sockfd, n;
    struct sockaddr_in servaddr;

    // Check command line input
    if (argc != 5) {
        printf("Usage: %s <from email> <to email> <subject> <message>\n", argv[0]);
        exit(1);
    }

    // Set email details
    from = argv[1];
    to = argv[2];
    subject = argv[3];
    message = argv[4];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Set the IP address and port of the SMTP server
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(25);
    inet_pton(AF_INET, "SMTP_SERVER_IP", &servaddr.sin_addr);

    // Connect to the SMTP server
    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    // Receive initial greeting
    n = read(sockfd, buf, MAXLINE);

    // Send HELO command
    snprintf(buf, MAXLINE, "HELO %s\r\n", "localhost");
    write(sockfd, buf, strlen(buf));

    // Receive HELO response
    n = read(sockfd, buf, MAXLINE);

    // Send MAIL FROM command
    snprintf(buf, MAXLINE, "MAIL FROM:<%s>\r\n", from);
    write(sockfd, buf, strlen(buf));

    // Receive MAIL FROM response
    n = read(sockfd, buf, MAXLINE);

    // Send RCPT TO command
    snprintf(buf, MAXLINE, "RCPT TO:<%s>\r\n", to);
    write(sockfd, buf, strlen(buf));

    // Receive RCPT TO response
    n = read(sockfd, buf, MAXLINE);

    // Send DATA command
    snprintf(buf, MAXLINE, "DATA\r\n");
    write(sockfd, buf, strlen(buf));

    // Receive DATA response
    n = read(sockfd, buf, MAXLINE);

    // Set email headers and message
    snprintf(buf, MAXLINE, "Subject: %s\r\n", subject);
    write(sockfd, buf, strlen(buf));
    snprintf(buf, MAXLINE, "From: <%s>\r\n", from);
    write(sockfd, buf, strlen(buf));
    snprintf(buf, MAXLINE, "To: <%s>\r\n", to);
    write(sockfd, buf, strlen(buf));
    snprintf(buf, MAXLINE, "\r\n%s\r\n.\r\n", message);
    write(sockfd, buf, strlen(buf));

    // Receive email sent confirmation
    n = read(sockfd, buf, MAXLINE);

    // Send QUIT command
    snprintf(buf, MAXLINE, "QUIT\r\n");
    write(sockfd, buf, strlen(buf));

    // Close the connection
    close(sockfd);

    return 0;
}