//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SMTP_PORT 25

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname email_address\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"Error: No such host\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SMTP_PORT);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    char buffer[1024] = {0};
    int bytes_received = read(sockfd, buffer, 1024);
    printf("%s\n", buffer);

    char helo_command[1024] = {0};
    sprintf(helo_command, "HELO %s\r\n", argv[1]);
    send(sockfd, helo_command, strlen(helo_command), 0);
    bytes_received = read(sockfd, buffer, 1024);
    printf("%s\n", buffer);

    char mail_from[1024] = {0};
    sprintf(mail_from, "MAIL FROM:<%s>\r\n", argv[2]);
    send(sockfd, mail_from, strlen(mail_from), 0);
    bytes_received = read(sockfd, buffer, 1024);
    printf("%s\n", buffer);

    char rcpt_to[1024] = {0};
    printf("Enter recipient email address: ");
    scanf("%s", rcpt_to);
    sprintf(rcpt_to, "RCPT TO:<%s>\r\n", rcpt_to);
    send(sockfd, rcpt_to, strlen(rcpt_to), 0);
    bytes_received = read(sockfd, buffer, 1024);
    printf("%s\n", buffer);

    char data_command[1024] = "DATA\r\n";
    send(sockfd, data_command, strlen(data_command), 0);
    bytes_received = read(sockfd, buffer, 1024);
    printf("%s\n", buffer);

    char subject[1024], message[1024];
    printf("Enter email subject: ");
    scanf("%s", subject);
    printf("Enter email message: ");
    scanf("%s", message);
    char email_body[2048] = {0};
    sprintf(email_body, "From: <%s>\r\nTo: <%s>\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", argv[2], rcpt_to, subject, message);
    send(sockfd, email_body, strlen(email_body), 0);
    bytes_received = read(sockfd, buffer, 1024);
    printf("%s\n", buffer);

    char quit_command[1024] = "QUIT\r\n";
    send(sockfd, quit_command, strlen(quit_command), 0);
    bytes_received = read(sockfd, buffer, 1024);
    printf("%s\n", buffer);

    close(sockfd);

    return 0;
}