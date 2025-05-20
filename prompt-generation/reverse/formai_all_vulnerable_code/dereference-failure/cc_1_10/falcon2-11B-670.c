//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 25

int main() {
    int sockfd, numbytes;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256], email[256], password[256];

    // Connect to the SMTP server
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error opening socket");
        exit(1);
    }

    server = gethostbyname("smtp.gmail.com");

    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    memcpy((char *) &serv_addr.sin_addr.s_addr,
          (char *)server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    // Authentication
    printf("Enter your email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = 0;
    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;

    // Send HELO command
    numbytes = write(sockfd, "HELO ", 4);
    if (numbytes!= 4) {
        perror("Error writing to socket");
        exit(1);
    }

    // Send MAIL FROM command
    numbytes = write(sockfd, "MAIL FROM:<your_email_address>", 32);
    if (numbytes!= 32) {
        perror("Error writing to socket");
        exit(1);
    }

    // Send RCPT TO command
    numbytes = write(sockfd, "RCPT TO:<recipient_email_address>", 32);
    if (numbytes!= 32) {
        perror("Error writing to socket");
        exit(1);
    }

    // Send DATA command
    numbytes = write(sockfd, "DATA", 4);
    if (numbytes!= 4) {
        perror("Error writing to socket");
        exit(1);
    }

    // Send the message
    numbytes = write(sockfd, "From: your_email_address\r\nTo: recipient_email_address\r\nSubject: Test Message\r\n\r\nThis is a test message.\r\n.\r\n.", 77);
    if (numbytes!= 77) {
        perror("Error writing to socket");
        exit(1);
    }

    // Send QUIT command
    numbytes = write(sockfd, "QUIT", 4);
    if (numbytes!= 4) {
        perror("Error writing to socket");
        exit(1);
    }

    close(sockfd);

    return 0;
}