//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 1234
#define MAX_LINE 1024

int main()
{
    struct sockaddr_in addr;
    int sockfd, n;
    char buffer[MAX_LINE];
    char *hostname;
    char *ip_address;
    char *host_name;
    struct hostent *host;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        printf("Error in socket creation\n");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        printf("Error in binding\n");
        exit(1);
    }

    while (1)
    {
        n = recvfrom(sockfd, buffer, MAX_LINE, 0, NULL, NULL);
        if (n < 0)
        {
            printf("Error in receiving\n");
            exit(1);
        }
        else
        {
            host = gethostbyname(buffer);
            if (host == NULL)
            {
                printf("Host not found\n");
                continue;
            }

            ip_address = inet_ntoa(*(struct in_addr *)host->h_addr);
            printf("%s -> %s\n", buffer, ip_address);
        }
    }

    return 0;
}