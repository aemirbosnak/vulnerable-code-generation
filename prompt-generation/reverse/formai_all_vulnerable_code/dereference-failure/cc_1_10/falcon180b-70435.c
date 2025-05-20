//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <time.h>

#define MAX 1000
#define PORT 8080
#define SA struct sockaddr

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, addrlen, bytes, valread = 0;
    char buffer[MAX];
    struct sockaddr_in serv_addr, cli_addr;
    fd_set readfds;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if(bind(sockfd, (SA*)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    while(1)
    {
        addrlen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (SA*)&cli_addr, &addrlen);

        FD_SET(newsockfd, &readfds);

        if(newsockfd > sockfd)
            sockfd = newsockfd;
    }

    close(sockfd);

    return 0;
}