//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>

#define MAX_LINE 1024

int main(int argc, char *argv[])
{
    int sockfd, numbytes, addrlen, port;
    struct sockaddr_in serv_addr;
    char buffer[MAX_LINE];
    char hostname[MAX_LINE];

    if (argc!= 3)
    {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    strcpy(hostname, argv[1]);
    port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(hostname);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connect");
        exit(1);
    }

    printf("Connected to %s:%d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

    numbytes = read(sockfd, buffer, MAX_LINE);
    if (numbytes < 0)
    {
        perror("read");
        exit(1);
    }

    printf("Received %d bytes from %s:%d\n", numbytes, inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

    printf("Pinging %s:%d (%d bytes of data)\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port), numbytes);

    write(sockfd, "PING ", 5);
    write(sockfd, buffer, numbytes);
    write(sockfd, "\r\n", 2);

    numbytes = read(sockfd, buffer, MAX_LINE);
    if (numbytes < 0)
    {
        perror("read");
        exit(1);
    }

    printf("Received %d bytes from %s:%d\n", numbytes, inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

    close(sockfd);

    return 0;
}