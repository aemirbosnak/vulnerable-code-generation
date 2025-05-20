//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    // Get the host name
    char hostname[256];
    gethostname(hostname, sizeof(hostname));

    // Get the host IP addresses
    struct hostent *he = gethostbyname(hostname);
    if (he == NULL)
    {
        printf("Error: Could not resolve hostname %s\n", hostname);
        return -1;
    }

    // Iterate over all the host IP addresses
    for (int i = 0; he->h_addr_list[i] != NULL; i++)
    {
        printf("Scanning host %s (%s)\n", hostname, inet_ntoa(*((struct in_addr *) he->h_addr_list[i])));

        // Create a socket
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0)
        {
            printf("Error: Could not create socket\n");
            return -1;
        }

        // Connect to the host on each port
        for (int port = 1; port <= 65535; port++)
        {
            struct sockaddr_in addr;
            addr.sin_family = AF_INET;
            addr.sin_addr.s_addr = *((in_addr_t *) he->h_addr_list[i]);
            addr.sin_port = htons(port);

            if (connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)) == 0)
            {
                printf("Port %d is open\n", port);
            }
        }

        // Close the socket
        close(sockfd);
    }

    return 0;
}