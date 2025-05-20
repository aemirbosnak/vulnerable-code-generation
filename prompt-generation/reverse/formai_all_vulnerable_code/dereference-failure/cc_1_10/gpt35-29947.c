//FormAI DATASET v1.0 Category: Network Ping Test ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    struct addrinfo hints, *result, *curr;
    struct timeval tv;
    int sockfd;
    char buffer[BUF_SIZE];
    int status;
    char ipstr[INET6_ADDRSTRLEN];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(argv[1], NULL, &hints, &result)) != 0)
    {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }

    for (curr = result; curr != NULL; curr = curr->ai_next)
    {
        void *addr;
        char *ipver;

        if (curr->ai_family == AF_INET) // IPv4
        {
            struct sockaddr_in *ipv4 = (struct sockaddr_in *)curr->ai_addr;
            addr = &(ipv4->sin_addr);
            ipver = "IPv4";
        }
        else // IPv6
        {
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)curr->ai_addr;
            addr = &(ipv6->sin6_addr);
            ipver = "IPv6";
        }

        inet_ntop(curr->ai_family, addr, ipstr, sizeof(ipstr));
        printf("Ping %s address: %s\n", ipver, ipstr);

        sockfd = socket(curr->ai_family, curr->ai_socktype, curr->ai_protocol);
        if (sockfd == -1)
        {
            perror("socket");
            continue;
        }

        if (connect(sockfd, curr->ai_addr, curr->ai_addrlen) == -1)
        {
            close(sockfd);
            perror("connect");
            continue;
        }

        break;
    }

    freeaddrinfo(result);

    if (curr == NULL)
    {
        fprintf(stderr, "Failed to connect to any of the addresses.\n");
        exit(1);
    }

    memset(buffer, 0, BUF_SIZE);
    strcpy(buffer, "ping");

    if (send(sockfd, buffer, strlen(buffer), 0) == -1)
    {
        perror("send");
        exit(1);
    }

    printf("Ping sent to %s\n", ipstr);

    memset(buffer, 0, BUF_SIZE);
    tv.tv_sec = 2;
    tv.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&tv, sizeof(tv));

    if (recv(sockfd, buffer, BUF_SIZE, 0) == -1)
    {
        printf("Ping timed out.\n");
    }
    else
    {
        printf("Ping response received.\n");
    }

    close(sockfd);

    return 0;
}