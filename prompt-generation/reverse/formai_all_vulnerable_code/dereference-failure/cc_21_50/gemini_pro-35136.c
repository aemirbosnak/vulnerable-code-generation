//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_LINE];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: could not resolve hostname %s\n", argv[1]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: could not create socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error: could not connect to server");
        exit(1);
    }

    bzero(buffer, MAX_LINE);
    strcpy(buffer, "HELO mydomain.com\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("Error: could not send HELO command");
        exit(1);
    }

    bzero(buffer, MAX_LINE);
    if (read(sockfd, buffer, MAX_LINE) < 0) {
        perror("Error: could not read response to HELO command");
        exit(1);
    }

    if (strncmp(buffer, "250", 3) != 0) {
        fprintf(stderr, "Error: unexpected response to HELO command: %s\n", buffer);
        exit(1);
    }

    bzero(buffer, MAX_LINE);
    strcpy(buffer, "MAIL FROM: <sender@mydomain.com>\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("Error: could not send MAIL FROM command");
        exit(1);
    }

    bzero(buffer, MAX_LINE);
    if (read(sockfd, buffer, MAX_LINE) < 0) {
        perror("Error: could not read response to MAIL FROM command");
        exit(1);
    }

    if (strncmp(buffer, "250", 3) != 0) {
        fprintf(stderr, "Error: unexpected response to MAIL FROM command: %s\n", buffer);
        exit(1);
    }

    bzero(buffer, MAX_LINE);
    strcpy(buffer, "RCPT TO: <recipient@theirdomain.com>\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("Error: could not send RCPT TO command");
        exit(1);
    }

    bzero(buffer, MAX_LINE);
    if (read(sockfd, buffer, MAX_LINE) < 0) {
        perror("Error: could not read response to RCPT TO command");
        exit(1);
    }

    if (strncmp(buffer, "250", 3) != 0) {
        fprintf(stderr, "Error: unexpected response to RCPT TO command: %s\n", buffer);
        exit(1);
    }

    bzero(buffer, MAX_LINE);
    strcpy(buffer, "DATA\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("Error: could not send DATA command");
        exit(1);
    }

    bzero(buffer, MAX_LINE);
    if (read(sockfd, buffer, MAX_LINE) < 0) {
        perror("Error: could not read response to DATA command");
        exit(1);
    }

    if (strncmp(buffer, "354", 3) != 0) {
        fprintf(stderr, "Error: unexpected response to DATA command: %s\n", buffer);
        exit(1);
    }

    bzero(buffer, MAX_LINE);
    strcpy(buffer, "Subject: This is a test message\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("Error: could not send email subject");
        exit(1);
    }

    bzero(buffer, MAX_LINE);
    strcpy(buffer, "From: sender@mydomain.com\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("Error: could not send email From address");
        exit(1);
    }

    bzero(buffer, MAX_LINE);
    strcpy(buffer, "To: recipient@theirdomain.com\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("Error: could not send email To address");
        exit(1);
    }

    bzero(buffer, MAX_LINE);
    strcpy(buffer, "\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("Error: could not send email body");
        exit(1);
    }

    bzero(buffer, MAX_LINE);
    strcpy(buffer, "This is the body of the email.\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("Error: could not send email body");
        exit(1);
    }

    bzero(buffer, MAX_LINE);
    strcpy(buffer, ".\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("Error: could not send email end-of-data marker");
        exit(1);
    }

    bzero(buffer, MAX_LINE);
    if (read(sockfd, buffer, MAX_LINE) < 0) {
        perror("Error: could not read response to DATA command");
        exit(1);
    }

    if (strncmp(buffer, "250", 3) != 0) {
        fprintf(stderr, "Error: unexpected response to DATA command: %s\n", buffer);
        exit(1);
    }

    bzero(buffer, MAX_LINE);
    strcpy(buffer, "QUIT\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("Error: could not send QUIT command");
        exit(1);
    }

    bzero(buffer, MAX_LINE);
    if (read(sockfd, buffer, MAX_LINE) < 0) {
        perror("Error: could not read response to QUIT command");
        exit(1);
    }

    if (strncmp(buffer, "221", 3) != 0) {
        fprintf(stderr, "Error: unexpected response to QUIT command: %s\n", buffer);
        exit(1);
    }

    close(sockfd);

    return 0;
}