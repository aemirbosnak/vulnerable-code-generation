//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <fcntl.h>

#define PORT_MIN 1
#define PORT_MAX 65535

void scan(char *host, int port)
{
    int sockfd, connfd, err;
    struct sockaddr_in srv_addr;
    struct hostent *hp;

    hp = gethostbyname(host);
    if (hp == NULL)
    {
        perror("gethostbyname");
        return;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0)
    {
        perror("socket");
        return;
    }

    srv_addr.sin_family = AF_INET;
    srv_addr.sin_port = htons(port);
    srv_addr.sin_addr.s_addr = inet_addr(hp->h_addr);

    connfd = connect(sockfd, (struct sockaddr *)&srv_addr, sizeof(srv_addr));
    if (connfd < 0)
    {
        perror("connect");
        return;
    }

    printf("Port %d: Open\n", port);

    close(connfd);
    close(sockfd);
}

int main()
{
    char host[256];
    int port;

    printf("Enter host name: ");
    scanf("%s", host);

    printf("Enter port number: ");
    scanf("%d", &port);

    scan(host, port);

    return 0;
}