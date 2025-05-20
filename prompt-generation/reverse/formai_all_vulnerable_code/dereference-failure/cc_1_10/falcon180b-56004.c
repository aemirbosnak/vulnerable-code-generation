//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    char *hostname;
    int sockfd, retval, timeval;
    struct hostent *hostinfo;
    struct sockaddr_in target;
    char buffer[BUFFER_SIZE];

    if (argc!= 2)
    {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    hostname = argv[1];
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    hostinfo = gethostbyname(hostname);

    if (hostinfo == NULL)
    {
        printf("Error resolving hostname\n");
        exit(1);
    }

    memset(&target, 0, sizeof(struct sockaddr_in));
    target.sin_family = AF_INET;
    target.sin_port = htons(7);
    target.sin_addr = *(struct in_addr *)hostinfo->h_addr;

    retval = connect(sockfd, (struct sockaddr *)&target, sizeof(struct sockaddr_in));

    if (retval == -1)
    {
        printf("Error connecting to host\n");
        exit(1);
    }

    timeval = 5;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeval, sizeof(int));

    send(sockfd, "PING", strlen("PING"), 0);

    while (1)
    {
        memset(buffer, 0, BUFFER_SIZE);
        retval = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (retval <= 0)
        {
            printf("Host is down\n");
            break;
        }

        if (strcmp(buffer, "PONG") == 0)
        {
            printf("Host is up\n");
            break;
        }
    }

    close(sockfd);

    return 0;
}