//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char **argv)
{
    int sockfd;
    struct sockaddr_in servaddr;
    char sendline[BUFSIZE], recvline[BUFSIZE];

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <server IP address> <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
    {
        fprintf(stderr, "inet_pton error for %s\n", argv[1]);
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("connect");
        exit(1);
    }

    while (1)
    {
        printf("ftp> ");
        fgets(sendline, BUFSIZE, stdin);

        if (send(sockfd, sendline, strlen(sendline), 0) < 0)
        {
            perror("send");
            exit(1);
        }

        if (strcmp(sendline, "quit\n") == 0)
        {
            break;
        }

        if (recv(sockfd, recvline, BUFSIZE, 0) < 0)
        {
            perror("recv");
            exit(1);
        }

        printf("%s", recvline);
    }

    close(sockfd);
    return 0;
}