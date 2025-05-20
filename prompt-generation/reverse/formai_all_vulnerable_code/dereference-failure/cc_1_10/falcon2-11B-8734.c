//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: brave
#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error in socket creation");
        exit(1);
    }

    server = gethostbyname("www.google.com");
    if (server == NULL)
    {
        perror("Error in getting host by name");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

    char buffer[1024];
    int n = recv(sockfd, buffer, sizeof(buffer), 0);

    if (n < 0)
    {
        perror("Error in recv");
        exit(1);
    }

    printf("Received %d bytes: %s\n", n, buffer);

    close(sockfd);

    return 0;
}