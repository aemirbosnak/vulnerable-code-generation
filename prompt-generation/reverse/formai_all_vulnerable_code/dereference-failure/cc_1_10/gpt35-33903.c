//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define SMTP_PORT 25

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];
    if (argc < 3) {
        error("usage: ./smtp_client hostname sender_email recipient_email");
    }

    portno = SMTP_PORT;
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
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    printf("Connected to SMTP server\n");

    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("%s\n", buffer);

    char *sender_email = argv[2];
    char *recipient_email = argv[3];

    char *message = "Hello World!\r\n";
    char from_buffer[BUFFER_SIZE];
    char to_buffer[BUFFER_SIZE];

    sprintf(from_buffer, "MAIL FROM: <%s>\r\n", sender_email);
    sprintf(to_buffer, "RCPT TO: <%s>\r\n", recipient_email);

    n = write(sockfd, "EHLO example.com\r\n", strlen("EHLO example.com\r\n"));

    if (n < 0) {
        error("ERROR writing to socket");
    }

    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("%s\n", buffer);

    n = write(sockfd, from_buffer, strlen(from_buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("%s\n", buffer);

    n = write(sockfd, to_buffer, strlen(to_buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("%s\n", buffer);

    n = write(sockfd, "DATA\r\n", strlen("DATA\r\n"));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("%s\n", buffer);

    n = write(sockfd, message, strlen(message));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    n = write(sockfd, "\r\n.\r\n", strlen("\r\n.\r\n"));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("%s\n", buffer);

    n = write(sockfd, "QUIT\r\n", strlen("QUIT\r\n"));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("%s\n", buffer);

    close(sockfd);
    return 0;
}