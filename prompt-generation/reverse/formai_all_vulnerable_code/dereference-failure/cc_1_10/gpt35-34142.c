//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Sherlock Holmes
//The case of the Missing Email - A Sherlock Holmes style SMTP Client program
//By your bot assistant

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

// Function to print error message and exit
void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[1024];
    if (argc < 3) {
        fprintf(stderr,"ERROR, usage %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    printf("Connected to server!\n");

    // SMTP communication

    // receive greeting
    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);

    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("%s\n", buffer);

    // send HELO command to identify ourselves to the server
    char helo[50];
    sprintf(helo, "HELO %s\r\n", argv[1]);
    n = write(sockfd, helo, strlen(helo));

    if (n < 0) {
        error("ERROR writing to socket");
    }

    // receive response from HELO
    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);

    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("%s\n", buffer);

    // send MAIL command to initiate sending email
    char mailfrom[] = "MAIL FROM:<sender@example.com>\r\n";
    n = write(sockfd, mailfrom, strlen(mailfrom));

    if (n < 0) {
        error("ERROR writing to socket");
    }

    // receive response from MAIL
    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);

    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("%s\n", buffer);

    // send RCPT command to specify recipient
    char rcpt[] = "RCPT TO:<recipient@example.com>\r\n";
    n = write(sockfd, rcpt, strlen(rcpt));

    if (n < 0) {
        error("ERROR writing to socket");
    }

    // receive response from RCPT
    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);

    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("%s\n", buffer);

    // send DATA command to start email data transfer
    char data[] = "DATA\r\n";
    n = write(sockfd, data, strlen(data));

    if (n < 0) {
        error("ERROR writing to socket");
    }

    // receive response from DATA
    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);

    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("%s\n", buffer);

    // send text of email
    char emailbody[] = "From: sender@example.com\nTo: recipient@example.com\nSubject: Test Email\n\nThis is a test email from my SMTP client program!\n.\r\n";
    n = write(sockfd, emailbody, strlen(emailbody));

    if (n < 0) {
        error("ERROR writing to socket");
    }

    // receive response after email sent
    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);

    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("%s\n", buffer);

    // send QUIT command to terminate connection
    char quit[] = "QUIT\r\n";
    n = write(sockfd, quit, strlen(quit));

    if (n < 0) {
        error("ERROR writing to socket");
    }

    // receive response from QUIT
    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);

    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("%s\n", buffer);

    // close connection
    close(sockfd);

    printf("Email Sent successfully!\n");

    return 0;
}