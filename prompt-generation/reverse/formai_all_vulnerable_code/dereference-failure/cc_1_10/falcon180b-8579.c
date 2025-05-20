//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000
#define PORT 8080
#define SERVER_NAME "127.0.0.1"
#define INTERVAL 5

int main()
{
    int sockfd, newsockfd, addrlen, ret;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[MAX_SIZE];
    struct timeval timeout;
    fd_set masterfds, readfds;
    int maxfd;
    double throughput;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket failed");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(SERVER_NAME);
    servaddr.sin_port = htons(PORT);

    ret = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (ret == -1)
    {
        perror("connect failed");
        exit(2);
    }

    FD_ZERO(&masterfds);
    FD_SET(sockfd, &masterfds);
    maxfd = sockfd;

    timeout.tv_sec = INTERVAL;
    timeout.tv_usec = 0;

    while (1)
    {
        readfds = masterfds;
        ret = select(maxfd + 1, &readfds, NULL, NULL, &timeout);

        if (ret == -1)
        {
            perror("select failed");
            exit(3);
        }

        if (FD_ISSET(sockfd, &readfds))
        {
            memset(buffer, 0, MAX_SIZE);
            ret = recv(sockfd, buffer, MAX_SIZE, 0);
            if (ret == -1)
            {
                perror("recv failed");
                exit(4);
            }

            printf("Received: %s\n", buffer);

            throughput = ret * 8.0 / INTERVAL;
            printf("Throughput: %lf bps\n", throughput);
        }
    }

    close(sockfd);
    return 0;
}