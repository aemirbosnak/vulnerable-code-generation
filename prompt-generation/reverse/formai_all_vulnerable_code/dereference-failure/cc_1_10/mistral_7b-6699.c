//MISTRAL-7B DATASET v1.0 Category: Building a SMTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    char *helo_msg = "HELO smtp-client\r\n";
    char *mail_from_msg = "MAIL FROM:<user@example.com>\r\n";
    char *rcpt_to_msg = "RCPT TO:<recipient@example.com>\r\n";
    char *data_msg = "DATA\r\n";
    char *subject = "Test email\r\n";
    char *body = "This is a test email.\r\n.\r\n";

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <user@example.com> <recipient@example.com>\n", argv[0]);
        exit(1);
    }

    portno = SMTP_PORT;
    server = gethostbyname("localhost");
    if (server == NULL) {
        herror("gethostbyname");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = inet_addr(server->h_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    write(sockfd, helo_msg, strlen(helo_msg));
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    write(sockfd, mail_from_msg, strlen(mail_from_msg));
    write(sockfd, argv[1], strlen(argv[1]) + strlen(argv[2]) + 13);

    recv(sockfd, buffer, BUFFER_SIZE, 0);

    write(sockfd, rcpt_to_msg, strlen(rcpt_to_msg));
    write(sockfd, argv[2], strlen(argv[2]) + strlen(argv[1]) + 13);

    recv(sockfd, buffer, BUFFER_SIZE, 0);

    write(sockfd, data_msg, strlen(data_msg));
    write(sockfd, "From: <user@example.com>\r\n", 17);
    write(sockfd, "To: <recipient@example.com>\r\n", 15);
    write(sockfd, "Subject: ", 8);
    write(sockfd, subject, strlen(subject));
    write(sockfd, "\r\n", 2);
    write(sockfd, body, strlen(body));
    write(sockfd, "\r\n.\r\n", 4);

    close(sockfd);

    printf("Email sent successfully!\n");
    return 0;
}