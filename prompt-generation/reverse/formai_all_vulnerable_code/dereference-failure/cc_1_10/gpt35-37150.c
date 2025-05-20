//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_LEN 1024 // Maximum size of the message

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: smtp_client hostname port mail_from\n");
        exit(1);
    }

    char *hostname = argv[1];
    char *port = argv[2];
    char *mail_from = argv[3];

    // Get server info
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    getaddrinfo(hostname, port, &hints, &res);

    // Create socket
    int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Connect to server
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
        perror("connect");
        exit(1);
    }

    // Receive greeting message
    char buf[MAX_LEN];
    memset(buf, 0, MAX_LEN);
    recv(sockfd, buf, MAX_LEN, 0);
    printf("%s", buf);

    // Send HELO message
    char *helo_msg = "HELO\r\n";
    send(sockfd, helo_msg, strlen(helo_msg), 0);
    memset(buf, 0, MAX_LEN);
    recv(sockfd, buf, MAX_LEN, 0);
    printf("%s", buf);

    // Send MAIL FROM message
    char mail_from_msg[MAX_LEN];
    sprintf(mail_from_msg, "MAIL FROM: <%s>\r\n", mail_from);
    send(sockfd, mail_from_msg, strlen(mail_from_msg), 0);
    memset(buf, 0, MAX_LEN);
    recv(sockfd, buf, MAX_LEN, 0);
    printf("%s", buf);

    // Send RCPT TO message
    char rcpt_to_msg[MAX_LEN];
    printf("Recipient: ");
    char rcpt[MAX_LEN];
    fgets(rcpt, MAX_LEN, stdin);
    rcpt[strlen(rcpt) - 1] = '\0';
    sprintf(rcpt_to_msg, "RCPT TO: <%s>\r\n", rcpt);
    send(sockfd, rcpt_to_msg, strlen(rcpt_to_msg), 0);
    memset(buf, 0, MAX_LEN);
    recv(sockfd, buf, MAX_LEN, 0);
    printf("%s", buf);

    // Send DATA message
    char *data_msg = "DATA\r\n";
    send(sockfd, data_msg, strlen(data_msg), 0);
    memset(buf, 0, MAX_LEN);
    recv(sockfd, buf, MAX_LEN, 0);
    printf("%s", buf);

    // Send message body
    printf("Message: ");
    char body[MAX_LEN];
    fgets(body, MAX_LEN, stdin);
    body[strlen(body) - 1] = '\0';
    char msg[MAX_LEN];
    sprintf(msg, "From: <%s>\r\nTo: <%s>\r\nSubject: Test Message\r\n\r\n%s\r\n.\r\n", mail_from, rcpt, body);
    send(sockfd, msg, strlen(msg), 0);
    memset(buf, 0, MAX_LEN);
    recv(sockfd, buf, MAX_LEN, 0);
    printf("%s", buf);

    // Send QUIT message
    char *quit_msg = "QUIT\r\n";
    send(sockfd, quit_msg, strlen(quit_msg), 0);
    memset(buf, 0, MAX_LEN);
    recv(sockfd, buf, MAX_LEN, 0);
    printf("%s", buf);

    // Close socket
    close(sockfd);

    return 0;
}