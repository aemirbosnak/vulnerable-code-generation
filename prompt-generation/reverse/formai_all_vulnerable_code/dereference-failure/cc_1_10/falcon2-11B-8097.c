//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_CONNECT_TRIES 3

int main(int argc, char *argv[])
{
    if(argc!= 3)
    {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    char hostname[100];
    char port[10];
    char buf[1024];
    int sockfd, retval, n;
    struct sockaddr_in server;

    strncpy(hostname, argv[1], 100);
    strncpy(port, argv[2], 10);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        perror("socket");
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(port));
    server.sin_addr.s_addr = inet_addr(hostname);

    retval = connect(sockfd, (struct sockaddr *)&server, sizeof(server));
    if(retval < 0)
    {
        perror("connect");
        exit(1);
    }

    printf("Connected to %s:%s\n", hostname, port);

    while(1)
    {
        retval = recv(sockfd, buf, sizeof(buf), 0);
        if(retval < 0)
        {
            perror("recv");
            exit(1);
        }
        else if(retval == 0)
        {
            printf("Connection closed by server\n");
            exit(1);
        }

        n = strlen(buf);
        if(n > 0)
        {
            printf("%s\n", buf);
        }
    }

    return 0;
}