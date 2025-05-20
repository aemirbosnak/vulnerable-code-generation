//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <unistd.h>
#include <netdb.h>
#include <stdbool.h>

#define MAX_SIZE 1024

int main() {
    int sockfd, portno, n;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char buffer[MAX_SIZE], msg[MAX_SIZE], command[MAX_SIZE];
    char sender_email[MAX_SIZE], recipient_email[MAX_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname("smtp.example.com");

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(25);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Connected to SMTP server\n");

    printf("Enter sender's email address: ");
    fgets(sender_email, MAX_SIZE, stdin);
    sender_email[strcspn(sender_email, "\n")] = 0;

    printf("Enter recipient's email address: ");
    fgets(recipient_email, MAX_SIZE, stdin);
    recipient_email[strcspn(recipient_email, "\n")] = 0;

    printf("Enter command (HELO/EHLO/MAIL/RCPT/DATA): ");
    fgets(command, MAX_SIZE, stdin);
    command[strcspn(command, "\n")] = 0;

    if (strcmp(command, "HELO") == 0) {
        snprintf(msg, sizeof(msg), "HELO %s", sender_email);
        send(sockfd, msg, strlen(msg), 0);
    } else if (strcmp(command, "EHLO") == 0) {
        snprintf(msg, sizeof(msg), "EHLO %s", sender_email);
        send(sockfd, msg, strlen(msg), 0);
    } else if (strcmp(command, "MAIL") == 0) {
        snprintf(msg, sizeof(msg), "MAIL FROM: <%s>", sender_email);
        send(sockfd, msg, strlen(msg), 0);
    } else if (strcmp(command, "RCPT") == 0) {
        snprintf(msg, sizeof(msg), "RCPT TO: <%s>", recipient_email);
        send(sockfd, msg, strlen(msg), 0);
    } else if (strcmp(command, "DATA") == 0) {
        printf("Enter the email message:\n");
        fgets(buffer, MAX_SIZE, stdin);
        send(sockfd, buffer, strlen(buffer), 0);
    } else {
        printf("Unknown command: %s\n", command);
        exit(1);
    }

    close(sockfd);

    return 0;
}