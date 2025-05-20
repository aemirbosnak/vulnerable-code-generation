//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[256];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send HELO command
    bzero(buffer, 256);
    strcpy(buffer, "HELO localhost\r\n");
    write(sockfd, buffer, strlen(buffer));

    // Receive server response
    bzero(buffer, 256);
    read(sockfd, buffer, 255);
    printf("%s", buffer);

    // Send MAIL FROM command
    bzero(buffer, 256);
    strcpy(buffer, "MAIL FROM: <sender@localhost>\r\n");
    write(sockfd, buffer, strlen(buffer));

    // Receive server response
    bzero(buffer, 256);
    read(sockfd, buffer, 255);
    printf("%s", buffer);

    // Send RCPT TO command
    bzero(buffer, 256);
    strcpy(buffer, "RCPT TO: <recipient@localhost>\r\n");
    write(sockfd, buffer, strlen(buffer));

    // Receive server response
    bzero(buffer, 256);
    read(sockfd, buffer, 255);
    printf("%s", buffer);

    // Send DATA command
    bzero(buffer, 256);
    strcpy(buffer, "DATA\r\n");
    write(sockfd, buffer, strlen(buffer));

    // Receive server response
    bzero(buffer, 256);
    read(sockfd, buffer, 255);
    printf("%s", buffer);

    // Send email message
    bzero(buffer, 256);
    strcpy(buffer, "Subject: Test email\r\n");
    write(sockfd, buffer, strlen(buffer));
    strcpy(buffer, "From: sender@localhost\r\n");
    write(sockfd, buffer, strlen(buffer));
    strcpy(buffer, "To: recipient@localhost\r\n");
    write(sockfd, buffer, strlen(buffer));
    strcpy(buffer, "\r\n");
    write(sockfd, buffer, strlen(buffer));
    strcpy(buffer, "This is a test email.\r\n");
    write(sockfd, buffer, strlen(buffer));
    strcpy(buffer, ".\r\n");
    write(sockfd, buffer, strlen(buffer));

    // Receive server response
    bzero(buffer, 256);
    read(sockfd, buffer, 255);
    printf("%s", buffer);

    // Send QUIT command
    bzero(buffer, 256);
    strcpy(buffer, "QUIT\r\n");
    write(sockfd, buffer, strlen(buffer));

    // Receive server response
    bzero(buffer, 256);
    read(sockfd, buffer, 255);
    printf("%s", buffer);

    close(sockfd);

    return 0;
}