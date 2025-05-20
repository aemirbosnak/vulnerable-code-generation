//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: paranoid
#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char hostname[256];
    printf("Enter the hostname: ");
    fgets(hostname, 256, stdin);

    struct hostent *hp;
    hp = gethostbyname(hostname);

    if (hp == NULL)
    {
        printf("Error getting host information.\n");
        exit(1);
    }

    int sockfd;
    sockfd = socket(AF_INET, SOCK_RAW, htons(8));

    if (sockfd < 0)
    {
        printf("Error creating socket.\n");
        exit(1);
    }

    struct sockaddr_in sin;
    sin.sin_family = htons(AF_INET);
    sin.sin_port = htons(53);
    sin.sin_addr.s_addr = hp->h_addr;

    int n;
    n = sendto(sockfd, "PING", 4, 0, (struct sockaddr *)&sin, sizeof(sin));

    if (n < 0)
    {
        printf("Error sending ping message.\n");
        exit(1);
    }

    char buf[1024];
    n = recvfrom(sockfd, buf, 1024, 0, (struct sockaddr *)&sin, NULL);

    if (n < 0)
    {
        printf("Error receiving ping reply.\n");
        exit(1);
    }

    printf("Reply: %s\n", buf);

    close(sockfd);
    return 0;
}