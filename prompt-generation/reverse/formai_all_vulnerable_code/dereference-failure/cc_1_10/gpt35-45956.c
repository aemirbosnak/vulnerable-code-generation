//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 25

void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char const *argv[]) {
    int sockfd, connfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[1024];
    char username[50], password[50], to[50], subject[50], message[200];

    if (argc < 2) {
        fprintf(stderr,"usage %s hostname\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        error("ERROR, no such host");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    printf("Please enter your email username: ");
    scanf("%s", username);

    printf("Please enter your email password: ");
    scanf("%s", password);

    printf("Please enter the recipient email address: ");
    scanf("%s", to);

    printf("Please enter the email subject: ");
    scanf("%s", subject);

    printf("Please enter the email message: ");
    scanf("%s", message);

    sprintf(buffer, "EHLO %s\r\n", argv[1]);
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);
    printf("%s", buffer);
    if (n < 0) {
        error("ERROR reading from socket");
    }

    sprintf(buffer, "AUTH LOGIN\r\n");
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);
    printf("%s", buffer);
    if (n < 0) {
        error("ERROR reading from socket");
    }

    sprintf(buffer, "%s\r\n", username);
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);
    printf("%s", buffer);
    if (n < 0) {
        error("ERROR reading from socket");
    }

    sprintf(buffer, "%s\r\n", password);
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);
    printf("%s", buffer);
    if (n < 0) {
        error("ERROR reading from socket");
    }

    sprintf(buffer, "MAIL FROM: <%s>\r\n", username);
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);
    printf("%s", buffer);
    if (n < 0) {
        error("ERROR reading from socket");
    }

    sprintf(buffer, "RCPT TO: <%s>\r\n", to);
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);
    printf("%s", buffer);
    if (n < 0) {
        error("ERROR reading from socket");
    }

    sprintf(buffer, "DATA\r\n");
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);
    printf("%s", buffer);
    if (n < 0) {
        error("ERROR reading from socket");
    }

    sprintf(buffer, "Subject: %s\n\n%s\n", subject, message);
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);
    printf("%s", buffer);
    if (n < 0) {
        error("ERROR reading from socket");
    }

    sprintf(buffer, ".\r\n");
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);
    printf("%s", buffer);
    if (n < 0) {
        error("ERROR reading from socket");
    }

    sprintf(buffer, "QUIT\r\n");
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);
    printf("%s", buffer);
    if (n < 0) {
        error("ERROR reading from socket");
    }

    close(sockfd);

    return EXIT_SUCCESS;
}