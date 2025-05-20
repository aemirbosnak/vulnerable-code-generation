//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <time.h>

#define PORT 25
#define SERVER "smtp.example.com"

int main() {
    int sockfd, portno, n;
    struct sockaddr_in servaddr;
    struct hostent *server;
    char buf[256], msg[256], sendbuf[256];

    printf("Enter email address: ");
    scanf("%s", msg);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server = gethostbyname(SERVER);

    memset((char *)&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(portno);

    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    time_t t = time(NULL);
    strftime(buf, sizeof(buf), "From: %s\r\n", localtime(&t));

    printf("Sending email: %s\n", msg);

    strcat(buf, "Subject: Test Email\r\n");
    strcat(buf, "To: ");
    strcat(buf, msg);
    strcat(buf, "\r\n");
    strcat(buf, "MIME-Version: 1.0\r\n");
    strcat(buf, "Content-Type: text/html; charset=\"iso-8859-1\"\r\n");
    strcat(buf, "Content-Transfer-Encoding: 7bit\r\n");
    strcat(buf, "\r\n");

    send(sockfd, buf, strlen(buf), 0);

    close(sockfd);

    return 0;
}