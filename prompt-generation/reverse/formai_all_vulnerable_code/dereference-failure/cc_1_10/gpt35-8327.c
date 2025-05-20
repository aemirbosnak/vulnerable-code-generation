//FormAI DATASET v1.0 Category: Port Scanner ; Style: introspective
#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define MAX_PORT 65535 /* maximum port number to scan */

int main(int argc, char *argv[])
{
    struct hostent *host;
    struct sockaddr_in addr;
    int sock, port;

    /* check for correct number of arguments */
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        return 1;
    }

    /* get host by IP address */
    if ((host = gethostbyaddr(argv[1], strlen(argv[1]), AF_INET)) == NULL)
    {
        fprintf(stderr, "Error: Invalid IP address\n");
        return 1;
    }

    /* initialize socket */
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Error");
        return 1;
    }

    /* set up address structure */
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr = *((struct in_addr *) host->h_addr);

    /* scan ports */
    for (port = 1; port <= MAX_PORT; port++)
    {
        addr.sin_port = htons(port);

        /* attempt to connect to port */
        if (connect(sock, (struct sockaddr *) &addr, sizeof(addr)) == 0)
        {
            printf("Port %d open\n", ntohs(addr.sin_port));
            close(sock);
        }
    }

    /* close socket */
    close(sock);

    return 0;
}