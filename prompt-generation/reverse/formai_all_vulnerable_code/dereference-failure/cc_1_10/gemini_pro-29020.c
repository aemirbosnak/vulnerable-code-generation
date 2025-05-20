//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[1024];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server_ip> <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    write(sockfd, "HELO world\r\n", 12);
    read(sockfd, buffer, 1024);
    printf("%s", buffer);

    write(sockfd, "MAIL FROM:<sender@example.com>\r\n", 32);
    read(sockfd, buffer, 1024);
    printf("%s", buffer);

    write(sockfd, "RCPT TO:<recipient@example.com>\r\n", 32);
    read(sockfd, buffer, 1024);
    printf("%s", buffer);

    write(sockfd, "DATA\r\n", 6);
    read(sockfd, buffer, 1024);
    printf("%s", buffer);

    write(sockfd, "Subject: This is a test email\r\n\r\n", 34);
    write(sockfd, "This is the body of the email.\r\n", 32);
    write(sockfd, ".\r\n", 3);
    read(sockfd, buffer, 1024);
    printf("%s", buffer);

    write(sockfd, "QUIT\r\n", 6);
    close(sockfd);

    return 0;
}