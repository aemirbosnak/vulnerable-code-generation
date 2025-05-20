//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, ret;
    struct addrinfo *addrinfo;
    struct addrinfo hints;
    char buffer[BUFFER_SIZE];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if ((ret = getaddrinfo(argv[1], NULL, &hints, &addrinfo))!= 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
        return EXIT_FAILURE;
    }

    sockfd = socket(addrinfo->ai_family, addrinfo->ai_socktype, addrinfo->ai_protocol);
    if (sockfd == -1)
    {
        perror("socket");
        return EXIT_FAILURE;
    }

    if (connect(sockfd, addrinfo->ai_addr, addrinfo->ai_addrlen) == -1)
    {
        perror("connect");
        close(sockfd);
        return EXIT_FAILURE;
    }

    send(sockfd, "PING", strlen("PING"), 0);

    while (1)
    {
        memset(buffer, 0, BUFFER_SIZE);
        ret = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (ret <= 0)
        {
            if (ret == 0)
                printf("Connection closed by server\n");
            else
                perror("recv");
            break;
        }
        printf("Received: %s\n", buffer);
    }

    close(sockfd);
    freeaddrinfo(addrinfo);
    return EXIT_SUCCESS;
}