//MISTRAL-7B DATASET v1.0 Category: Building a SMTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define SERVER_PORT 25
#define MAX_BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_BUFFER_SIZE];
    char *hello = "HELO Client\r\n";
    char *mailfrom = "MAIL FROM:<sender@example.com>\r\n";
    char *rcptto = "RCPT TO:<recipient@example.com>\r\n";
    char *data = "DATA\r\n";
    char *subject = "Subject: Test Email\r\n";
    char *message = "Hello World! This is a test email.\r\n.\r\n";

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <sender_email> <recipient_email>\n", argv[0]);
        exit(1);
    }

    portno = SERVER_PORT;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        die("ERROR opening socket");

    server = gethostbyname("smtp.gmail.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        die("ERROR connecting");

    write(sockfd, hello, strlen(hello));
    printf("250 [smtp.gmail.com]: HELO Client\r\n");

    write(sockfd, mailfrom, strlen(mailfrom));
    read(sockfd, buffer, MAX_BUFFER_SIZE);
    printf("%s", buffer);

    write(sockfd, rcptto, strlen(rcptto));
    read(sockfd, buffer, MAX_BUFFER_SIZE);
    printf("%s", buffer);

    write(sockfd, data, strlen(data));
    read(sockfd, buffer, MAX_BUFFER_SIZE);
    printf("%s", buffer);

    write(sockfd, subject, strlen(subject));
    write(sockfd, message, strlen(message));
    read(sockfd, buffer, MAX_BUFFER_SIZE);
    printf("%s", buffer);

    write(sockfd, "QUIT\r\n", strlen("QUIT\r\n"));
    read(sockfd, buffer, MAX_BUFFER_SIZE);
    printf("%s", buffer);

    close(sockfd);
    return 0;
}