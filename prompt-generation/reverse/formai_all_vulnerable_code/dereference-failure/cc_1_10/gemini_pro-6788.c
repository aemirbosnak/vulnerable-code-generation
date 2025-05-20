//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 100

int main(int argc, char *argv[])
{
    char *host;
    int port;
    int sockfd;
    struct sockaddr_in servaddr;

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    host = argv[1];
    port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    inet_pton(AF_INET, host, &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
    {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s:%d\n", host, port);

    for (int i = 0; i < PORT_RANGE; i++)
    {
        struct sockaddr_in sin;
        socklen_t len = sizeof(sin);
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1)
        {
            perror("socket");
            continue;
        }

        sin.sin_family = AF_INET;
        sin.sin_port = htons(port + i);
        inet_pton(AF_INET, host, &sin.sin_addr);

        if (connect(sock, (struct sockaddr *)&sin, len) == -1)
        {
            perror("connect");
            close(sock);
            continue;
        }

        printf("Port %d is open\n", port + i);
        close(sock);
    }

    close(sockfd);
    return 0;
}