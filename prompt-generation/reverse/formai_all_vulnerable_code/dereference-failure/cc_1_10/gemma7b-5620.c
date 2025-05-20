//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: detailed
#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PINGS 10
#define TIMEOUT 2

int main()
{
    int sockfd, i, j, n, port = 53000;
    char host[256];
    struct sockaddr_in serv_addr;
    struct hostent *hp;

    printf("Enter the host name: ");
    scanf("%s", host);

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, htons(port))) < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    hp = gethostbyname(host);
    serv_addr.sin_addr.s_addr = hp->h_addr;

    n = 0;
    for (i = 0; i < MAX_PINGS; i++)
    {
        clock_t start_time = clock();
        if (sendto(sockfd, "ping", 4, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        {
            perror("Error sending ping");
            exit(1);
        }

        clock_t end_time = clock();
        int time_taken = end_time - start_time;

        printf("Ping %d: Time taken = %d ms\n", n, time_taken);
        n++;
    }

    close(sockfd);
    return 0;
}