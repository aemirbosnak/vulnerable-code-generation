//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXLINE 1000
#define MAXHOST 100

int main(int argc, char *argv[])
{
    if (argc!= 3)
    {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        return 1;
    }

    int sockfd;
    struct hostent *host;
    struct sockaddr_in serveraddr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket");
        exit(1);
    }

    host = gethostbyname(argv[1]);
    if (host == NULL)
    {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *)&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&serveraddr.sin_addr.s_addr, host->h_length);
    serveraddr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1)
    {
        perror("connect");
        exit(1);
    }

    char buffer[MAXLINE];
    int n;

    printf("SMTP Client\n");
    printf("Enter the email address to send to: ");
    fgets(buffer, MAXLINE, stdin);
    printf("Enter the email subject: ");
    fgets(buffer, MAXLINE, stdin);
    printf("Enter the email body: ");
    fgets(buffer, MAXLINE, stdin);

    if (send(sockfd, buffer, strlen(buffer), 0) == -1)
    {
        perror("send");
        exit(1);
    }

    n = recv(sockfd, buffer, MAXLINE, 0);
    printf("Received %d bytes: %s\n", n, buffer);

    close(sockfd);
    return 0;
}