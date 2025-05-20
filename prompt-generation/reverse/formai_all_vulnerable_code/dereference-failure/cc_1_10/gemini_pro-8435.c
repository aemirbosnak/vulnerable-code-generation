//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 587
#define MAXLINE 1024

struct mail {
    char *sender;
    char *recipient;
    char *subject;
    char *body;
};

struct mail *create_mail(char *sender, char *recipient, char *subject, char *body) {
    struct mail *mail = malloc(sizeof(struct mail));
    mail->sender = strdup(sender);
    mail->recipient = strdup(recipient);
    mail->subject = strdup(subject);
    mail->body = strdup(body);
    return mail;
}

void free_mail(struct mail *mail) {
    free(mail->sender);
    free(mail->recipient);
    free(mail->subject);
    free(mail->body);
    free(mail);
}

int send_mail(struct mail *mail) {
    int sockfd, n;
    struct sockaddr_in servaddr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        return -1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0) {
        return -1;
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        return -1;
    }

    char buf[MAXLINE];

    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (send(sockfd, buf, strlen(buf), 0) < 0) {
            return -1;
        }
        if (strcmp(buf, "QUIT\r\n") == 0) {
            break;
        }
    }
    close(sockfd);
    return 0;
}

int main() {
    struct mail *mail = create_mail("sender@example.com", "recipient@example.com", "Subject: Test", "Body: This is a test email.\n");
    send_mail(mail);
    free_mail(mail);
    return 0;
}