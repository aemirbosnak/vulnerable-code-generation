//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/tcp.h>

int main()
{
    int sockfd, n;
    struct sockaddr_in serveraddr;
    struct hostent *server;
    struct sockaddr_in clientaddr;
    socklen_t clilen;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket failed");
        exit(1);
    }

    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(8888);
    server = gethostbyname("localhost");
    if (server == NULL)
    {
        fprintf(stderr, "gethostbyname failed\n");
        exit(1);
    }
    bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0)
    {
        perror("connect failed");
        exit(1);
    }

    clilen = sizeof(clientaddr);
    n = recvfrom(sockfd, (char *)&clientaddr, sizeof(clientaddr), 0, NULL, &clilen);
    printf("Client IP: %s\n", inet_ntoa(clientaddr.sin_addr));
    printf("Client Port: %d\n", ntohs(clientaddr.sin_port));
    printf("Message: %s\n", (char *)&clientaddr);

    sendto(sockfd, "Hello, world!", 13, 0, (struct sockaddr *)&clientaddr, clilen);

    close(sockfd);
    return 0;
}