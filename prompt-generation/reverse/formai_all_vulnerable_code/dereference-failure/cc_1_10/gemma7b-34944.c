//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#define MAX_PINGS 10

int main()
{
    char **servers = malloc(MAX_PINGS * sizeof(char *));
    for (int i = 0; i < MAX_PINGS; i++)
    {
        servers[i] = malloc(256);
    }

    int numPings = 0;
    for (int i = 0; i < MAX_PINGS; i++)
    {
        printf("Enter the IP address of the server: ");
        scanf("%s", servers[i]);

        int sockfd = socket(AF_INET, SOCK_DGRAM, htons(53));
        struct sockaddr_in serverAddr;
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(53);
        inet_pton(AF_INET, servers[i], &serverAddr.sin_addr);

        char pingMessage[] = "PING";
        sendto(sockfd, pingMessage, strlen(pingMessage), 0, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

        char responseMessage[256];
        recvfrom(sockfd, responseMessage, sizeof(responseMessage), 0, (struct sockaddr *)&serverAddr, NULL);

        printf("Server: %s, Response: %s\n", servers[i], responseMessage);

        numPings++;
    }

    printf("Total number of pings: %d\n", numPings);

    for (int i = 0; i < MAX_PINGS; i++)
    {
        free(servers[i]);
    }
    free(servers);

    return 0;
}