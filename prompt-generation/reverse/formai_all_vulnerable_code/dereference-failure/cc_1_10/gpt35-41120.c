//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER 1024
#define SMTP_PORT 25

bool send_mail(int sockfd, char *from, char *to, char *subject, char *body);

int main(int argc, char *argv[]) {
    int sockfd;
    char *hostname, *from, *to, *subject, *body;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc != 6) {
        fprintf(stderr, "Usage: %s hostname from to subject body\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    hostname = argv[1];
    from = argv[2];
    to = argv[3];
    subject = argv[4];
    body = argv[5];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Failed to lookup hostname\n");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SMTP_PORT);
    serv_addr.sin_addr = *(struct in_addr*)server->h_addr;

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }

    if (send_mail(sockfd, from, to, subject, body)) {
        printf("Email sent successfully.\n");
    } else {
        printf("Failed to send email.\n");
    }

    close(sockfd);
    return 0;
}

bool send_mail(int sockfd, char *from, char *to, char *subject, char *body) {
    char buffer[MAX_BUFFER];
    int len;

    // Wait for server to send 220 greeting
    if ((len = read(sockfd, buffer, MAX_BUFFER)) <= 0) {
        return false;
    }

    buffer[len] = '\0';
    printf("%s", buffer);

    // Say hello
    sprintf(buffer, "EHLO example.com\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        return false;
    }

    // Wait for server to send 250 response
    if ((len = read(sockfd, buffer, MAX_BUFFER)) <= 0) {
        return false;
    }

    buffer[len] = '\0';
    printf("%s", buffer);

    // Set sender
    sprintf(buffer, "MAIL FROM: <%s>\r\n", from);
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        return false;
    }

    // Wait for server to send 250 response
    if ((len = read(sockfd, buffer, MAX_BUFFER)) <= 0) {
        return false;
    }

    buffer[len] = '\0';
    printf("%s", buffer);

    // Set recipient
    sprintf(buffer, "RCPT TO: <%s>\r\n", to);
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        return false;
    }

    // Wait for server to send 250 response
    if ((len = read(sockfd, buffer, MAX_BUFFER)) <= 0) {
        return false;
    }

    buffer[len] = '\0';
    printf("%s", buffer);

    // Start data
    sprintf(buffer, "DATA\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        return false;
    }

    // Wait for server to send 354 response
    if ((len = read(sockfd, buffer, MAX_BUFFER)) <= 0) {
        return false;
    }

    buffer[len] = '\0';
    printf("%s", buffer);

    // Send message headers and body
    sprintf(buffer, "From: <%s>\r\n", from);
    write(sockfd, buffer, strlen(buffer));
    sprintf(buffer, "To: <%s>\r\n", to);
    write(sockfd, buffer, strlen(buffer));
    sprintf(buffer, "Subject: %s\r\n", subject);
    write(sockfd, buffer, strlen(buffer));
    sprintf(buffer, "\r\n");
    write(sockfd, buffer, strlen(buffer));
    sprintf(buffer, "%s\r\n", body);
    write(sockfd, buffer, strlen(buffer));

    // End data
    sprintf(buffer, "\r\n.\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        return false;
    }

    // Wait for server to send 250 response
    if ((len = read(sockfd, buffer, MAX_BUFFER)) <= 0) {
        return false;
    }

    buffer[len] = '\0';
    printf("%s", buffer);

    // Say goodbye
    sprintf(buffer, "QUIT\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        return false;
    }

    // Wait for server to send 221 response
    if ((len = read(sockfd, buffer, MAX_BUFFER)) <= 0) {
        return false;
    }

    buffer[len] = '\0';
    printf("%s", buffer);

    return true;
}