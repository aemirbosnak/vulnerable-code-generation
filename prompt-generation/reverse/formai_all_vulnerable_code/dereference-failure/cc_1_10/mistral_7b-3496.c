//MISTRAL-7B DATASET v1.0 Category: Building a SMTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define SERVER_PORT 25
#define BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serveraddr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        die("ERROR opening socket");

    server = gethostbyname("smtp.gmail.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serveraddr, sizeof(serveraddr));
    portno = SERVER_PORT;
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr,
         server->h_length);
    serveraddr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0)
        die("ERROR connecting");

    // EHLO command
    send(sockfd, "HELO Client\r\n", strlen("HELO Client\r\n"), 0);

    // Mail From: command
    char mailFrom[100] = "sender@example.com";
    send(sockfd, "MAIL FROM:<", strlen("MAIL FROM:<"), 0);
    send(sockfd, mailFrom, strlen(mailFrom), 0);
    send(sockfd, ">\r\n", strlen(">\r\n"), 0);

    // Rcpt To: command
    char rcptTo[100] = "recipient@example.com";
    send(sockfd, "RCPT TO:<", strlen("RCPT TO:<"), 0);
    send(sockfd, rcptTo, strlen(rcptTo), 0);
    send(sockfd, ">\r\n", strlen(">\r\n"), 0);

    // Data command
    send(sockfd, "DATA\r\n", strlen("DATA\r\n"), 0);

    // Message body
    char message[BUFFER_SIZE] = "Subject: Test SMTP Client\r\n\r\nThis is a test message.\r\n.";
    send(sockfd, message, strlen(message), 0);

    // Quit command
    send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0);

    close(sockfd);

    return 0;
}