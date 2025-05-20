//FormAI DATASET v1.0 Category: Port Scanner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_PORT 65535

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s <hostname or IP address>\n", argv[0]);
        exit(1);
    }

    // Resolve hostname or IP address
    struct hostent *host = gethostbyname(argv[1]);

    if(!host)
    {
        fprintf(stderr, "Could not resolve hostname or IP address '%s'\n", argv[1]);
        exit(1);
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0)
    {
        perror("socket() failed");
        exit(1);
    }

    // Set socket options
    int yes = 1;
    if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) < 0)
    {
        perror("setsockopt() failed");
        exit(1);
    }

    // Scan ports
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr = *((struct in_addr *) host->h_addr);

    printf("\nScanning host %s (%s):\n", host->h_name, inet_ntoa(addr.sin_addr));
    printf("|Port       |Status     |\n");
    printf("|-----------|-----------|\n");

    for(int i = 0; i <= MAX_PORT; i++)
    {
        addr.sin_port = htons(i);
        int status = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));

        if(status == 0)
        {
            printf("|%-11d|Open       |\n", i);
            close(sockfd);
            sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if(sockfd < 0)
            {
                perror("socket() failed");
                exit(1);
            }
            if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) < 0)
            {
                perror("setsockopt() failed");
                exit(1);
            }
        }
        else
        {
            printf("|%-11d|Closed     |\n", i);
        }
    }

    return 0;
}