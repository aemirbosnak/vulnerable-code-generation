//FormAI DATASET v1.0 Category: Port Scanner ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define TIMEOUT_SEC 2

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1)
    {
        perror("Error in creating socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in srvr;
    srvr.sin_family = AF_INET;
    srvr.sin_addr.s_addr = inet_addr(argv[1]);

    for(int port=1; port<65536; port++)
    {
        srvr.sin_port = htons(port);
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);
        struct timeval timeout;
        timeout.tv_sec = TIMEOUT_SEC;
        timeout.tv_usec = 0;

        int status = connect(sockfd, (struct sockaddr*)&srvr, sizeof(srvr));
        if(status == 0)
        {
            printf("Port %d open\n", port);
            close(sockfd);
            sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if(sockfd == -1)
            {
                perror("Error in creating socket");
                exit(EXIT_FAILURE);
            }
            continue;
        }
        else if(status == -1 && FD_ISSET(sockfd, &readfds))
        {
            printf("Port %d closed\n", port);
            close(sockfd);
            sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if(sockfd == -1)
            {
                perror("Error in creating socket");
                exit(EXIT_FAILURE);
            }
            continue;
        }
        else
        {
            close(sockfd);
            sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if(sockfd == -1)
            {
                perror("Error in creating socket");
                exit(EXIT_FAILURE);
            }
            continue;
        }
    }

    return 0;
}