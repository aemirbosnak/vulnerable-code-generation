//FormAI DATASET v1.0 Category: Port Scanner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <ip_address>\n", argv[0]);
        return 1;
    }

    struct hostent *hostinfo;
    hostinfo = gethostbyname(argv[1]);
    if (hostinfo == NULL)
    {
        printf("Error resolving host %s\n", argv[1]);
        return 1;
    }

    int sockfd;
    int port;
    struct sockaddr_in target_addr;
    int err;

    for (port = 1; port < 65536; port++)
    {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0)
        {
            perror("Error opening socket");
            exit(1);
        }

        target_addr.sin_family = AF_INET;
        target_addr.sin_port = htons(port);
        target_addr.sin_addr = *((struct in_addr*) hostinfo -> h_addr);
        memset(&(target_addr.sin_zero), '\0', 8);

        err = connect(sockfd, (struct sockaddr*)&target_addr, sizeof(struct sockaddr));
        if (err < 0)
        {
            //printf("Port %d is closed.\n", port);
            close(sockfd);
        }
        else
        {
            printf("Port %d is open!\n", port);
            close(sockfd);
        }
    }

    return 0;
}