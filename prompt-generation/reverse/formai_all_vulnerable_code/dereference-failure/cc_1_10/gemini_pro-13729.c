//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    struct hostent *host = gethostbyname(hostname);
    if (!host)
    {
        printf("Error: Could not resolve hostname %s\n", hostname);
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        perror("Error: Could not create socket");
        exit(1);
    }

    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(33434);
    memcpy(&dest_addr.sin_addr, host->h_addr, host->h_length);

    char *message = "PING";
    int message_len = strlen(message);

    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

    int num_pings = 10;
    int num_responses = 0;
    for (int i = 0; i < num_pings; i++)
    {
        if (sendto(sockfd, message, message_len, 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0)
        {
            perror("Error: Could not send ping");
            continue;
        }

        char buffer[1024];
        socklen_t addr_len = sizeof(dest_addr);
        int n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&dest_addr, &addr_len);
        if (n < 0)
        {
            perror("Error: Could not receive ping response");
            continue;
        }

        if (strncmp(buffer, message, message_len) == 0)
        {
            num_responses++;
        }
    }

    printf("Ping statistics for %s:\n", hostname);
    printf("  Packets transmitted: %d\n", num_pings);
    printf("  Packets received: %d\n", num_responses);
    printf("  Packet loss: %%%d\n", (num_pings - num_responses) * 100 / num_pings);

    close(sockfd);
    return 0;
}