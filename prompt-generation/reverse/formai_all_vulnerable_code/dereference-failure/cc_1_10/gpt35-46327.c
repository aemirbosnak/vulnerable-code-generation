//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 1024

int main(int argc, char *argv[])
{
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;

    if (argc != 3)
    {
        printf("Usage: %s <IP address> <Port>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket Error");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
    {
        printf("Inet_pton error for %s\n", argv[1]);
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("Connect error");
        exit(1);
    }

    printf("Connected to IMAP Server\n");
    printf("Type command: ");
    fflush(stdout);

    while (fgets(recvline, MAXLINE, stdin) != NULL)
    {
        if (write(sockfd, recvline, strlen(recvline)) < 0)
        {
            printf("Write error to socket");
            exit(1);
        }

        if ((n = read(sockfd, recvline, MAXLINE)) < 0)
        {
            printf("Read error from socket");
            exit(1);
        }

        recvline[n] = 0;
        printf("%s\n", recvline);
        printf("Type command: ");
        fflush(stdout);
    }

    exit(0);
}