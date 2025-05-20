//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: active
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int send_email(char* recipient, char* subject) {
    int sockfd;
    struct sockaddr_in server;
    int status;
    int portno = 25;

    // Convert the server address and port number to network format
    server.sin_family = AF_INET;
    server.sin_port = htons(portno);
    status = inet_pton(AF_INET, "smtp.gmail.com", &server.sin_addr);
    if (status == 0) {
        fprintf(stderr, "inet_pton() failed\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "socket() failed\n");
        exit(1);
    }

    connect(sockfd, (struct sockaddr*)&server, sizeof(server));
    if (connect(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        fprintf(stderr, "Connection failed\n");
        exit(1);
    }

    char command[100];
    sprintf(command, "HELO %s\r\n", "your_domain_name");
    if (send(sockfd, command, strlen(command), 0) < 0) {
        fprintf(stderr, "send() failed\n");
        exit(1);
    }

    if (recv(sockfd, command, 100, 0) < 0) {
        fprintf(stderr, "recv() failed\n");
        exit(1);
    }

    char message[100];
    sprintf(message, "MAIL FROM:<%s>\r\n", "your_email_address");
    if (send(sockfd, message, strlen(message), 0) < 0) {
        fprintf(stderr, "send() failed\n");
        exit(1);
    }

    if (recv(sockfd, command, 100, 0) < 0) {
        fprintf(stderr, "recv() failed\n");
        exit(1);
    }

    sprintf(message, "RCPT TO:<%s>\r\n", recipient);
    if (send(sockfd, message, strlen(message), 0) < 0) {
        fprintf(stderr, "send() failed\n");
        exit(1);
    }

    if (recv(sockfd, command, 100, 0) < 0) {
        fprintf(stderr, "recv() failed\n");
        exit(1);
    }

    sprintf(message, "DATA\r\n");
    if (send(sockfd, message, strlen(message), 0) < 0) {
        fprintf(stderr, "send() failed\n");
        exit(1);
    }

    sprintf(message, "Subject: %s\r\n\r\n", subject);
    if (send(sockfd, message, strlen(message), 0) < 0) {
        fprintf(stderr, "send() failed\n");
        exit(1);
    }

    if (recv(sockfd, command, 100, 0) < 0) {
        fprintf(stderr, "recv() failed\n");
        exit(1);
    }

    sprintf(message, ".\r\n");
    if (send(sockfd, message, strlen(message), 0) < 0) {
        fprintf(stderr, "send() failed\n");
        exit(1);
    }

    if (recv(sockfd, command, 100, 0) < 0) {
        fprintf(stderr, "recv() failed\n");
        exit(1);
    }

    sprintf(message, "QUIT\r\n");
    if (send(sockfd, message, strlen(message), 0) < 0) {
        fprintf(stderr, "send() failed\n");
        exit(1);
    }

    close(sockfd);
    return 0;
}

int main() {
    send_email("recipient@example.com", "Subject of the email");
    printf("Email sent successfully\n");
    return 0;
}