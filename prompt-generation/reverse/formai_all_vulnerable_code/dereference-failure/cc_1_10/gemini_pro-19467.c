//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_EMAIL_SIZE 1024

typedef struct {
    char *to;
    char *from;
    char *subject;
    char *body;
} email;

void create_email(email *e, char *to, char *from, char *subject, char *body) {
    e->to = strdup(to);
    e->from = strdup(from);
    e->subject = strdup(subject);
    e->body = strdup(body);
}

void send_email(email *e) {
    int sockfd;
    struct sockaddr_in servaddr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Connect to the server
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(25);
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Send the email
    char *buffer = malloc(MAX_EMAIL_SIZE);
    sprintf(buffer, "MAIL FROM: %s\r\nRCPT TO: %s\r\nDATA\r\n%s\r\n.\r\n", e->from, e->to, e->body);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Close the socket
    close(sockfd);
}

int main() {
    email e;
    create_email(&e, "to@example.com", "from@example.com", "Subject: Test email", "This is a test email.");
    send_email(&e);
    return 0;
}