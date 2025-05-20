//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<errno.h>
#include<time.h>

#define SERVER "smtp.gmail.com"
#define PORT 587
#define USER "your_email@gmail.com"
#define PASS "your_password"
#define FROM "your_email@gmail.com"
#define TO "recipient_email@gmail.com"
#define SUBJECT "Test Email"
#define MESSAGE "This is a test email sent from a C program."

int main() {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buffer[1024];
    char username[50] = USER;
    char password[50] = PASS;
    char from[50] = FROM;
    char to[50] = TO;
    char subject[50] = SUBJECT;
    char message[200] = MESSAGE;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    char* login = "LOGIN ";
    strcat(login, username);
    strcat(login, "\r\n");
    send(sockfd, login, strlen(login), 0);

    char* pass = "PASS ";
    strcat(pass, password);
    strcat(pass, "\r\n");
    send(sockfd, pass, strlen(pass), 0);

    char* from_header = "From: ";
    strcat(from_header, from);
    strcat(from_header, "\r\n");
    send(sockfd, from_header, strlen(from_header), 0);

    char* to_header = "To: ";
    strcat(to_header, to);
    strcat(to_header, "\r\n");
    send(sockfd, to_header, strlen(to_header), 0);

    char* subject_header = "Subject: ";
    strcat(subject_header, subject);
    strcat(subject_header, "\r\n");
    send(sockfd, subject_header, strlen(subject_header), 0);

    char* message_header = "Content-Type: text/plain; charset=UTF-8\r\n";
    send(sockfd, message_header, strlen(message_header), 0);

    char* message_body = "Message:\r\n";
    strcat(message_body, message);
    strcat(message_body, "\r\n.\r\n");
    send(sockfd, message_body, strlen(message_body), 0);

    char* quit = "QUIT\r\n";
    send(sockfd, quit, strlen(quit), 0);

    close(sockfd);
    return 0;
}