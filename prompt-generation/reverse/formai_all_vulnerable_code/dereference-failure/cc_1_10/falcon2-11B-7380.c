//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct hostent *server;
    struct sockaddr_in serv_addr;

    if (argc!= 3) {
        fprintf(stderr, "usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "no such host\n");
        exit(1);
    }

    portno = atoi(argv[2]);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    printf("SMTP client connected to %s on port %d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

    printf("helo localhost\r\n");
    fflush(stdout);

    printf("mail from: <sender@domain.com>\r\n");
    fflush(stdout);

    printf("rcpt to: <receiver@domain.com>\r\n");
    fflush(stdout);

    printf("data\r\n");
    fflush(stdout);

    printf("Subject: Test Email\r\n");
    fflush(stdout);

    printf("This is a test email.\r\n.\r\n");
    fflush(stdout);

    printf("quit\r\n");
    fflush(stdout);

    printf("Bye!\n");
    close(sockfd);

    return 0;
}