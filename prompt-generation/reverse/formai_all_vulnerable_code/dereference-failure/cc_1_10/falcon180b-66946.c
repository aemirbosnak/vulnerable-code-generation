//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define TRUE 1
#define FALSE 0
#define PORT "12345"
#define MAX 100

int main(int argc, char *argv[])
{
    int sockfd, n, len, ret;
    struct sockaddr_in servaddr;
    char buffer[MAX];
    char *ip;
    int port;

    if(argc!= 3)
    {
        printf("Usage :./a.out <ip> <port>\n");
        exit(0);
    }

    ip = argv[1];
    port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0)
    {
        printf("socket failed : %s\n", strerror(errno));
        exit(0);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &servaddr.sin_addr);

    ret = connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

    if(ret < 0)
    {
        printf("connect failed : %s\n", strerror(errno));
        exit(0);
    }

    printf("connected\n");

    do
    {
        memset(buffer, 0, sizeof(buffer));
        n = recv(sockfd, buffer, MAX, 0);

        if(n <= 0)
        {
            printf("recv failed : %s\n", strerror(errno));
            exit(0);
        }

        printf("recv : %s\n", buffer);

        len = send(sockfd, "ping", strlen("ping"), 0);

        if(len <= 0)
        {
            printf("send failed : %s\n", strerror(errno));
            exit(0);
        }

        printf("send : %s\n", "ping");

    }while(TRUE);

    close(sockfd);

    return 0;
}