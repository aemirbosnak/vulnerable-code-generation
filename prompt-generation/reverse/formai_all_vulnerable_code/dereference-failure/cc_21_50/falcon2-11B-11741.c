//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    struct hostent *server;
    struct sockaddr_in server_address;
    int sockfd, portno;
    char buffer[1024];

    if ( (server = gethostbyname("localhost")) == NULL ) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    portno = htons(25);
    bzero((char *)&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = portno;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Connected to SMTP server\n");

    if (send(sockfd, "HELO localhost\r\n", 13, 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }

    if (send(sockfd, "MAIL FROM: <sender@example.com>\r\n", 31, 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }

    if (send(sockfd, "RCPT TO: <recipient@example.com>\r\n", 28, 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }

    if (send(sockfd, "DATA\r\n", 7, 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }

    if (send(sockfd, "Subject: Test mail\r\n", 21, 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }

    if (send(sockfd, "From: sender@example.com\r\n", 23, 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }

    if (send(sockfd, "To: recipient@example.com\r\n", 24, 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }

    if (send(sockfd, "Date: Mon, 3 Jun 2021 10:05:03 +0000\r\n", 39, 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }

    if (send(sockfd, "Message-Id: <1234567890@example.com>\r\n", 39, 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }

    if (send(sockfd, "MIME-Version: 1.0\r\n", 19, 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }

    if (send(sockfd, "Content-Type: text/plain; charset=\"US-ASCII\"\r\n", 38, 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }

    if (send(sockfd, "Content-Transfer-Encoding: 8bit\r\n", 27, 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }

    if (send(sockfd, "Content-Length: 100\r\n", 16, 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }

    if (send(sockfd, "This is a test email.\r\n.\r\n", 35, 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }

    if (send(sockfd, "\r\n.\r\n", 7, 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }

    if (send(sockfd, "QUIT\r\n", 8, 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }

    if (close(sockfd) < 0) {
        perror("ERROR closing socket");
        exit(1);
    }

    return 0;
}