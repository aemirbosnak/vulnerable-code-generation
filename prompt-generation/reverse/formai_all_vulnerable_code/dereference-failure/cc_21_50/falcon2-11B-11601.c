//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <time.h>
#include <ctype.h>

#define MAX_EMAIL_LENGTH 100
#define MAX_RECIPIENT_LENGTH 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 10000

int main(int argc, char *argv[]) {
    int socketfd;
    int port = 25;
    char email[MAX_EMAIL_LENGTH];
    char recipient[MAX_RECIPIENT_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    char from[MAX_EMAIL_LENGTH];
    char to[MAX_RECIPIENT_LENGTH];
    char reply[MAX_EMAIL_LENGTH];
    char smtp_helo[MAX_EMAIL_LENGTH];
    char smtp_mail_from[MAX_EMAIL_LENGTH];
    char smtp_rcpt_to[MAX_RECIPIENT_LENGTH];
    char smtp_data[MAX_EMAIL_LENGTH];
    char smtp_quit[MAX_EMAIL_LENGTH];
    char smtp_mail_error[MAX_EMAIL_LENGTH];
    char smtp_data_error[MAX_EMAIL_LENGTH];
    char smtp_quit_error[MAX_EMAIL_LENGTH];
    struct addrinfo hints, *servinfo, *p;
    int rv;
    int status;
    char *program_name;

    program_name = argv[0];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", program_name);
        exit(1);
    }

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if ((rv = getaddrinfo(NULL, argv[1], &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        socketfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (socketfd == -1) {
            continue;
        }

        if (connect(socketfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(socketfd);
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to connect to server\n");
        exit(1);
    }

    memset(from, 0, sizeof from);
    memset(to, 0, sizeof to);
    memset(reply, 0, sizeof reply);
    memset(smtp_helo, 0, sizeof smtp_helo);
    memset(smtp_mail_from, 0, sizeof smtp_mail_from);
    memset(smtp_rcpt_to, 0, sizeof smtp_rcpt_to);
    memset(smtp_data, 0, sizeof smtp_data);
    memset(smtp_quit, 0, sizeof smtp_quit);
    memset(smtp_mail_error, 0, sizeof smtp_mail_error);
    memset(smtp_data_error, 0, sizeof smtp_data_error);
    memset(smtp_quit_error, 0, sizeof smtp_quit_error);

    strcpy(smtp_helo, "HELO ");
    strcat(smtp_helo, program_name);
    strcpy(smtp_mail_from, "MAIL FROM:");
    strcpy(smtp_rcpt_to, "RCPT TO:");
    strcpy(smtp_data, "DATA");
    strcpy(smtp_quit, "QUIT");

    if (send(socketfd, smtp_helo, strlen(smtp_helo), 0) < 0) {
        fprintf(stderr, "Failed to send HELO command\n");
        exit(1);
    }

    if (send(socketfd, smtp_mail_from, strlen(smtp_mail_from), 0) < 0) {
        fprintf(stderr, "Failed to send MAIL FROM command\n");
        exit(1);
    }

    if (send(socketfd, from, strlen(from), 0) < 0) {
        fprintf(stderr, "Failed to send MAIL FROM command\n");
        exit(1);
    }

    while (1) {
        printf("Enter email address: ");
        fgets(email, MAX_EMAIL_LENGTH, stdin);
        if (strlen(email) > MAX_EMAIL_LENGTH) {
            printf("Email address too long\n");
            continue;
        }
        break;
    }

    while (1) {
        printf("Enter recipient email address: ");
        fgets(recipient, MAX_RECIPIENT_LENGTH, stdin);
        if (strlen(recipient) > MAX_RECIPIENT_LENGTH) {
            printf("Recipient email address too long\n");
            continue;
        }
        break;
    }

    while (1) {
        printf("Enter subject: ");
        fgets(subject, MAX_SUBJECT_LENGTH, stdin);
        if (strlen(subject) > MAX_SUBJECT_LENGTH) {
            printf("Subject too long\n");
            continue;
        }
        break;
    }

    while (1) {
        printf("Enter email message: ");
        fgets(message, MAX_MESSAGE_LENGTH, stdin);
        if (strlen(message) > MAX_MESSAGE_LENGTH) {
            printf("Message too long\n");
            continue;
        }
        break;
    }

    if (send(socketfd, smtp_mail_from, strlen(smtp_mail_from), 0) < 0) {
        fprintf(stderr, "Failed to send MAIL FROM command\n");
        exit(1);
    }

    if (send(socketfd, smtp_rcpt_to, strlen(smtp_rcpt_to), 0) < 0) {
        fprintf(stderr, "Failed to send RCPT TO command\n");
        exit(1);
    }

    if (send(socketfd, to, strlen(to), 0) < 0) {
        fprintf(stderr, "Failed to send RCPT TO command\n");
        exit(1);
    }

    if (send(socketfd, subject, strlen(subject), 0) < 0) {
        fprintf(stderr, "Failed to send DATA command\n");
        exit(1);
    }

    if (send(socketfd, message, strlen(message), 0) < 0) {
        fprintf(stderr, "Failed to send message\n");
        exit(1);
    }

    if (send(socketfd, smtp_data, strlen(smtp_data), 0) < 0) {
        fprintf(stderr, "Failed to send DATA command\n");
        exit(1);
    }

    if (send(socketfd, ".\r\n", strlen(".\\r\\n"), 0) < 0) {
        fprintf(stderr, "Failed to send message end\n");
        exit(1);
    }

    if (send(socketfd, smtp_quit, strlen(smtp_quit), 0) < 0) {
        fprintf(stderr, "Failed to send QUIT command\n");
        exit(1);
    }

    status = 0;

    if (recv(socketfd, reply, MAX_EMAIL_LENGTH, 0) < 0) {
        fprintf(stderr, "Failed to receive response\n");
        exit(1);
    }

    if (strncmp(reply, "250", strlen("250")) == 0) {
        printf("Email sent successfully\n");
        status = 1;
    } else if (strncmp(reply, "554", strlen("554")) == 0) {
        printf("Email rejected\n");
        status = 2;
    } else {
        printf("Unexpected response: %s\n", reply);
        status = 3;
    }

    freeaddrinfo(servinfo);
    close(socketfd);

    return status;
}