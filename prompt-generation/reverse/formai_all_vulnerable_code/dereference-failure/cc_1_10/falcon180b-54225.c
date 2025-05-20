//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define TRUE 1
#define FALSE 0
#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd;
    int newsockfd;
    int portno;
    char *ip;
    struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;
    socklen_t clilen;
    char buffer[BUF_SIZE];

    if (argc < 3)
    {
        printf("Usage: %s <IP> <port>\n", argv[0]);
        exit(0);
    }

    ip = argv[1];
    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Error opening socket\n");
        exit(0);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Error connecting to server\n");
        exit(0);
    }

    while (TRUE)
    {
        bzero(buffer, BUF_SIZE);
        read(sockfd, buffer, BUF_SIZE);
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}