//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    int sockfd, sin_port, i, j, k, flag = 0, r, s, t;
    char hostname[256], buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in sin;

    printf("Enter hostname: ");
    scanf("%s", hostname);

    sin_port = 53;
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(sin_port));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(sin_port);
    strcpy(sin.sin_addr.s_addr, hostname);

    for (i = 0; i < 10; i++)
    {
        r = sendto(sockfd, "PING", 5, 0, (struct sockaddr *)&sin, sizeof(sin));
        if (r == -1)
        {
            perror("Error sending ping");
            exit(1);
        }

        sleep(1);

        s = recvfrom(sockfd, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr *)&sin, NULL);
        if (s == -1)
        {
            perror("Error receiving ping");
            exit(1);
        }

        printf("Reply from %s: %s\n", hostname, buffer);

        if (strcmp(buffer, "PONG") == 0)
        {
            flag = 1;
        }
    }

    if (flag == 0)
    {
        printf("No response from the host.\n");
    }

    close(sockfd);
    return 0;
}