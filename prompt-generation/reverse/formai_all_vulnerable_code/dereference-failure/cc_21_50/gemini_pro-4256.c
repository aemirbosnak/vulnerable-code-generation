//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    int sockfd, port;
    struct sockaddr_in servaddr;
    char *host, *user, *pass, *from, *to, *subject, *body;
    char buf[1024];

    if (argc != 9) {
        fprintf(stderr, "Usage: %s host port user pass from to subject body\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    port = atoi(argv[2]);
    user = argv[3];
    pass = argv[4];
    from = argv[5];
    to = argv[6];
    subject = argv[7];
    body = argv[8];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid host address: %s\n", host);
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Read and print the welcome banner.
    if (fgets(buf, sizeof(buf), sockfd) == NULL) {
        fprintf(stderr, "Error reading welcome banner\n");
        exit(1);
    }
    printf("Server: %s\n", buf);

    // Send the HELO command.
    if (snprintf(buf, sizeof(buf), "HELO %s\n", host) < 0) {
        fprintf(stderr, "Error formatting HELO command\n");
        exit(1);
    }
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Read and print the HELO response.
    if (fgets(buf, sizeof(buf), sockfd) == NULL) {
        fprintf(stderr, "Error reading HELO response\n");
        exit(1);
    }
    printf("Server: %s\n", buf);

    // Send the AUTH LOGIN command.
    if (snprintf(buf, sizeof(buf), "AUTH LOGIN\n") < 0) {
        fprintf(stderr, "Error formatting AUTH LOGIN command\n");
        exit(1);
    }
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Read and print the AUTH LOGIN response.
    if (fgets(buf, sizeof(buf), sockfd) == NULL) {
        fprintf(stderr, "Error reading AUTH LOGIN response\n");
        exit(1);
    }
    printf("Server: %s\n", buf);

    // Send the base64-encoded username.
    if (snprintf(buf, sizeof(buf), "%s\n", user) < 0) {
        fprintf(stderr, "Error formatting username\n");
        exit(1);
    }
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Read and print the base64-encoded password response.
    if (fgets(buf, sizeof(buf), sockfd) == NULL) {
        fprintf(stderr, "Error reading password response\n");
        exit(1);
    }
    printf("Server: %s\n", buf);

    // Send the base64-encoded password.
    if (snprintf(buf, sizeof(buf), "%s\n", pass) < 0) {
        fprintf(stderr, "Error formatting password\n");
        exit(1);
    }
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Read and print the MAIL FROM response.
    if (fgets(buf, sizeof(buf), sockfd) == NULL) {
        fprintf(stderr, "Error reading MAIL FROM response\n");
        exit(1);
    }
    printf("Server: %s\n", buf);

    // Send the MAIL FROM command.
    if (snprintf(buf, sizeof(buf), "MAIL FROM:<%s>\n", from) < 0) {
        fprintf(stderr, "Error formatting MAIL FROM command\n");
        exit(1);
    }
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Read and print the RCPT TO response.
    if (fgets(buf, sizeof(buf), sockfd) == NULL) {
        fprintf(stderr, "Error reading RCPT TO response\n");
        exit(1);
    }
    printf("Server: %s\n", buf);

    // Send the RCPT TO command.
    if (snprintf(buf, sizeof(buf), "RCPT TO:<%s>\n", to) < 0) {
        fprintf(stderr, "Error formatting RCPT TO command\n");
        exit(1);
    }
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Read and print the DATA response.
    if (fgets(buf, sizeof(buf), sockfd) == NULL) {
        fprintf(stderr, "Error reading DATA response\n");
        exit(1);
    }
    printf("Server: %s\n", buf);

    // Send the DATA command.
    if (snprintf(buf, sizeof(buf), "DATA\n") < 0) {
        fprintf(stderr, "Error formatting DATA command\n");
        exit(1);
    }
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Send the email message.
    if (snprintf(buf, sizeof(buf), "From: %s\nTo: %s\nSubject: %s\n\n%s\n", from, to, subject, body) < 0) {
        fprintf(stderr, "Error formatting email message\n");
        exit(1);
    }
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Read and print the QUIT response.
    if (fgets(buf, sizeof(buf), sockfd) == NULL) {
        fprintf(stderr, "Error reading QUIT response\n");
        exit(1);
    }
    printf("Server: %s\n", buf);

    // Send the QUIT command.
    if (snprintf(buf, sizeof(buf), "QUIT\n") < 0) {
        fprintf(stderr, "Error formatting QUIT command\n");
        exit(1);
    }
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(1);
    }

    close(sockfd);

    return 0;
}