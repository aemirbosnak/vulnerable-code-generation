//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define PORT "8080"
#define MAXDATASIZE 1024

// function to get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET)
    {
        return &(((struct sockaddr_in *)sa)->sin_addr);
    }
    return &(((struct sockaddr_in6 *)sa)->sin6_addr);
}

void set_socket_blocking(int sockfd)
{
    int flags = fcntl(sockfd, F_GETFL, 0);
    fcntl(sockfd, F_SETFL, flags & ~O_NONBLOCK);
}

int main(int argc, char *argv[])
{
    int sockfd, numbytes;
    char buf[MAXDATASIZE];
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[INET6_ADDRSTRLEN];

    if (argc != 2)
    {
        fprintf(stderr, "usage: client hostname\n");
        exit(1);
    }

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(argv[1], PORT, &hints, &servinfo)) != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for (p = servinfo; p != NULL; p = p->ai_next)
    {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
        {
            perror("client: socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1)
        {
            close(sockfd);
            perror("client: connect");
            continue;
        }

        break;
    }

    if (p == NULL)
    {
        fprintf(stderr, "client: failed to connect\n");
        return 2;
    }

    inet_ntop(p->ai_family, get_in_addr((struct sockaddr *)p->ai_addr), s, sizeof s);
    printf("client: connecting to %s\n", s);

    freeaddrinfo(servinfo);

    set_socket_blocking(sockfd);

    // secure protocol to exchange messages
    int authenticated = 0;

    while (1)
    {
        if (!authenticated)
        {
            printf("Enter username: ");
            fgets(buf, sizeof(buf), stdin);
            buf[strcspn(buf, "\n")] = 0;

            if (send(sockfd, buf, strlen(buf), 0) == -1)
            {
                perror("send");
                close(sockfd);
                exit(1);
            }

            printf("Enter password: ");
            fgets(buf, sizeof(buf), stdin);
            buf[strcspn(buf, "\n")] = 0;

            if (send(sockfd, buf, strlen(buf), 0) == -1)
            {
                perror("send");
                close(sockfd);
                exit(1);
            }

            authenticated = 1;

            printf("Successfully authenticated\n");
        }
        else
        {
            printf("Enter a message: ");
            fgets(buf, sizeof(buf), stdin);
            buf[strcspn(buf, "\n")] = 0;

            if (send(sockfd, buf, strlen(buf), 0) == -1)
            {
                perror("send");
                close(sockfd);
                exit(1);
            }

            if ((numbytes = recv(sockfd, buf, MAXDATASIZE - 1, 0)) == -1)
            {
                perror("recv");
                close(sockfd);
                exit(1);
            }

            buf[numbytes] = '\0';
            printf("Received message: '%s'\n", buf);
        }
    }

    close(sockfd);
    return 0;
}