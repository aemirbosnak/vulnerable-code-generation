//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 25
#define MAXLINE 1024

int main(int argc, char *argv[]) {
    struct hostent *server;
    struct sockaddr_in dest_addr;
    int sockfd;
    int status;
    int len;
    char buffer[MAXLINE];
    char msg[MAXLINE];
    char *subject;

    printf("SMTP Client\n");

    if (argc < 3) {
        printf("Usage: %s <hostname> <subject>\n", argv[0]);
        return 1;
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Unknown host\n");
        return 1;
    }

    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(PORT);
    memcpy((char *) &dest_addr.sin_addr.s_addr,
          (char *) server->h_addr, server->h_length);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Failed to create socket\n");
        return 1;
    }

    status = connect(sockfd, (struct sockaddr *) &dest_addr, sizeof(dest_addr));
    if (status < 0) {
        fprintf(stderr, "Connection failed\n");
        return 1;
    }

    sprintf(msg, "HELO localhost\r\n");
    write(sockfd, msg, strlen(msg));
    read(sockfd, buffer, MAXLINE);

    sprintf(msg, "MAIL FROM: %s\r\n", argv[2]);
    write(sockfd, msg, strlen(msg));
    read(sockfd, buffer, MAXLINE);

    sprintf(msg, "RCPT TO: %s\r\n", argv[2]);
    write(sockfd, msg, strlen(msg));
    read(sockfd, buffer, MAXLINE);

    sprintf(msg, "DATA\r\n");
    write(sockfd, msg, strlen(msg));
    read(sockfd, buffer, MAXLINE);

    sprintf(msg, "From: %s\r\n", argv[2]);
    write(sockfd, msg, strlen(msg));
    read(sockfd, buffer, MAXLINE);

    sprintf(msg, "To: %s\r\n", argv[2]);
    write(sockfd, msg, strlen(msg));
    read(sockfd, buffer, MAXLINE);

    sprintf(msg, "Subject: %s\r\n", argv[2]);
    write(sockfd, msg, strlen(msg));
    read(sockfd, buffer, MAXLINE);

    sprintf(msg, "This is the message body.\r\n.\r\n");
    write(sockfd, msg, strlen(msg));
    read(sockfd, buffer, MAXLINE);

    sprintf(msg, "QUIT\r\n");
    write(sockfd, msg, strlen(msg));
    read(sockfd, buffer, MAXLINE);

    close(sockfd);
    return 0;
}