//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_HOST_LEN 1024
#define MAX_PORT_LEN 6
#define MAX_DATA_LEN 1024

int main(int argc, char *argv[])
{
    char *host = argv[1];
    char *port = argv[2];
    char *data = argv[3];
    int sockfd, n;
    struct addrinfo hints, *servinfo, *p;
    struct sockaddr *sa;
    char s[MAX_HOST_LEN];
    char sport[MAX_PORT_LEN];
    char d[MAX_DATA_LEN];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((n = getaddrinfo(host, port, &hints, &servinfo))!= 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(n));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next)
    {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
        {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1)
        {
            perror("connect");
            close(sockfd);
            continue;
        }

        break;
    }

    if (p == NULL)
    {
        fprintf(stderr, "failed to connect\n");
        exit(1);
    }

    snprintf(s, MAX_HOST_LEN, "GET / HTTP/1.1\r\nHost: %s\r\n", host);
    snprintf(sport, MAX_PORT_LEN, "%s", port);
    snprintf(d, MAX_DATA_LEN, "%s", data);

    send(sockfd, s, strlen(s), 0);
    send(sockfd, sport, strlen(sport), 0);
    send(sockfd, d, strlen(d), 0);

    close(sockfd);

    return 0;
}