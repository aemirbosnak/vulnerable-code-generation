//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

int main()
{
    char hostname[256];
    int port = 53;
    int num_tries = 3;
    int i = 0;

    printf("Enter the hostname: ");
    scanf("%s", hostname);

    for (i = 0; i < num_tries; i++)
    {
        int sockfd;
        struct sockaddr_in serv_addr;
        struct hostent *hp;

        if ((sockfd = socket(AF_INET, SOCK_STREAM, htons(port))) < 0)
        {
            perror("Error creating socket");
            exit(1);
        }

        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(port);
        serv_addr.sin_addr.s_addr = inet_addr(hostname);

        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        {
            perror("Error connecting to server");
            close(sockfd);
            continue;
        }

        hp = gethostbyaddr(&serv_addr.sin_addr.s_addr, sizeof(serv_addr.sin_addr), AF_INET);
        printf("Ping to %s (%s) successful!\n", hp->h_name, hostname);

        close(sockfd);
        break;
    }

    if (i == num_tries - 1)
    {
        printf("Error pinging server.\n");
    }

    return 0;
}