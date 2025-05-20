//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    int sockfd, portno, newsockfd, addrlen;
    struct sockaddr_in serv_addr, cli_addr;
    char buf[1024];

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);
    if (portno < 1 || portno > 65535)
    {
        fprintf(stderr, "Invalid port number\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("bind");
        exit(1);
    }

    listen(sockfd, 5);

    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &addrlen);
    if (newsockfd < 0)
    {
        perror("accept");
        exit(1);
    }

    while (1)
    {
        bzero(buf, sizeof(buf));
        read(newsockfd, buf, sizeof(buf));
        if (strcmp(buf, "exit") == 0)
        {
            break;
        }
        write(newsockfd, buf, strlen(buf));
    }

    close(newsockfd);
    close(sockfd);
    return 0;
}