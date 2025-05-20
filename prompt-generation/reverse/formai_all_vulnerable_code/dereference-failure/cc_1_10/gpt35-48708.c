//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAXLEN 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAXLEN];
    char domain[MAXLEN];
    char from[MAXLEN];
    char to[MAXLEN];
    char subject[MAXLEN];
    char message[MAXLEN];

    if (argc < 2) {
        printf("Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    portno = 25;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server = gethostbyname(argv[1]);
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server.\n");
        exit(1);
    }

    printf("Enter recipient domain: ");
    fgets(domain, MAXLEN, stdin);
    strtok(domain, "\n");
    sprintf(buffer, "HELO %s\n", domain);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        printf("Error writing to socket.\n");
        exit(1);
    }

    printf("Enter sender's email address: ");
    fgets(from, MAXLEN, stdin);
    strtok(from, "\n");
    printf("Enter recipient's email address: ");
    fgets(to, MAXLEN, stdin);
    strtok(to, "\n");

    printf("Enter message subject: ");
    fgets(subject, MAXLEN, stdin);
    strtok(subject, "\n");

    printf("Enter message body: ");
    fgets(message, MAXLEN, stdin);
    strtok(message, "\n");

    sprintf(buffer, "MAIL FROM:<%s>\n", from);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        printf("Error writing to socket.\n");
        exit(1);
    }

    sprintf(buffer, "RCPT TO:<%s>\n", to);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        printf("Error writing to socket.\n");
        exit(1);
    }

    sprintf(buffer, "DATA\nFrom: %s\nTo: %s\nSubject: %s\n\n%s\n.\n", from, to, subject, message);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        printf("Error writing to socket.\n");
        exit(1);
    }

    printf("Email sent successfully.\n");

    close(sockfd);
    return 0;
}