//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_PINGS 10
#define TIMEOUT 5

int main()
{
    int i, j, ping_cnt = 0, status;
    struct hostent *hp;
    struct sockaddr_in sin;

    sin.sin_family = AF_INET;
    sin.sin_port = htons(53);

    for (i = 0; i < MAX_PINGS; i++)
    {
        char hostname[256];

        printf("Enter hostname: ");
        scanf("%s", hostname);

        hp = gethostbyname(hostname);
        sin.sin_addr.s_addr = hp->h_addr;

        status = ping(sin, TIMEOUT);

        if (status == 0)
        {
            printf("Ping successful!\n");
            ping_cnt++;
        }
        else
        {
            printf("Ping failed.\n");
        }
    }

    printf("Total number of successful pings: %d\n", ping_cnt);

    return 0;
}

int ping(struct sockaddr_in sin, int timeout)
{
    int sockfd, bytes_sent, bytes_received, status;
    char msg[1024];

    sockfd = socket(AF_INET, SOCK_DGRAM, htons(123));
    sendto(sockfd, msg, 1024, NULL, (struct sockaddr *)&sin, sizeof(sin));

    bytes_received = recvfrom(sockfd, msg, 1024, NULL, (struct sockaddr *)&sin, NULL);

    status = bytes_received > 0;

    close(sockfd);

    return status;
}