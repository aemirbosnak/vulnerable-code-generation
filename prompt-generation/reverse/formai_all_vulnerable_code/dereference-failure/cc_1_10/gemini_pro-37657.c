//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <time.h>

void sighandler(int signo)
{
    exit(1);
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s <hostname/ip>\n", argv[0]);
        exit(1);
    }

    signal(SIGINT, sighandler);

    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL)
    {
        printf("Invalid hostname/ip: %s\n", argv[1]);
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);
    servaddr.sin_addr = *(struct in_addr *) host->h_addr;

    char sendbuf[1024] = "PING";
    char recvbuf[1024];
    socklen_t servaddrlen = sizeof(servaddr);

    while (1)
    {
        ssize_t sent = sendto(sockfd, sendbuf, strlen(sendbuf), 0, (struct sockaddr *) &servaddr, servaddrlen);
        if (sent == -1)
        {
            perror("sendto");
            exit(1);
        }

        struct timeval tv = {1, 0};
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);

        int ret = select(sockfd + 1, &readfds, NULL, NULL, &tv);
        if (ret == -1)
        {
            perror("select");
            exit(1);
        }
        else if (ret == 0)
        {
            printf("Request timed out.\n");
        }
        else if (FD_ISSET(sockfd, &readfds))
        {
            ssize_t received = recvfrom(sockfd, recvbuf, sizeof(recvbuf), 0, (struct sockaddr *) &servaddr, &servaddrlen);
            if (received == -1)
            {
                perror("recvfrom");
                exit(1);
            }
            else if (strcmp(recvbuf, "PONG") == 0)
            {
                printf("Response received: PONG\n");
            }
        }
    }

    close(sockfd);
    return 0;
}