//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define MAXLINE 1024

int sockfd;
char read_buffer[MAXLINE];

void error(char *msg) {
    fprintf(stderr, "%s", msg);
    exit(1);
}

void send_cmd(char *cmd) {
    bzero(read_buffer, MAXLINE);
    write(sockfd, cmd, strlen(cmd));
    read(sockfd, read_buffer, MAXLINE);
    printf("%s\n", read_buffer);
}

void send_data(char *data) {
    bzero(read_buffer, MAXLINE);
    write(sockfd, data, strlen(data));
    read(sockfd, read_buffer, MAXLINE);
}

int main(int argc, char **argv) {
    struct sockaddr_in servaddr;
    struct hostent *server;

    if (argc != 3) {
        error("Usage: ./smtp_client <server_ip> <port>\n");
    }
    int portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error("Error opening socket\n");
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        error("Error: no such host\n");
    }

    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        error("Error connecting to server\n");
    }
    bzero(read_buffer, MAXLINE);
    read(sockfd, read_buffer, MAXLINE);
    printf("%s\n", read_buffer);

    send_cmd("EHLO smtp.example.com\r\n");
    send_cmd("MAIL FROM:<example@example.com>\r\n");
    send_cmd("RCPT TO:<receiver@example.com>\r\n");
    send_cmd("DATA\r\n");
    send_data("From: example@example.com\r\n"
               "To: receiver@example.com\r\n"
               "Subject: SMTP Test\r\n"
               "\r\n"
               "This is a test email.\r\n"
               ".\r\n");

    send_cmd("QUIT\r\n");
    close(sockfd);

    return 0;
}