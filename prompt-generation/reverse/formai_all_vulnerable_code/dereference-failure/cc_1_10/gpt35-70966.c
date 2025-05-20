//FormAI DATASET v1.0 Category: Port Scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>

#define START_PORT 1
#define END_PORT 65535

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <ip address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd, connfd, err;
    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);
    char *ip = argv[1];

    printf("Scanning ports on %s....\n\n", ip);

    for (int i = START_PORT; i <= END_PORT; i++)
    {
        sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (sockfd == -1)
        {
            fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        memset(&addr, 0, len);
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = inet_addr(ip);
        addr.sin_port = htons(i);

        err = connect(sockfd, (struct sockaddr *)&addr, len);
        if (err == 0)
        {
            printf("Port %d is open!\n", i);
        }
        close(sockfd);
    }

    printf("\nPort Scan Complete!\n");

    return EXIT_SUCCESS;
}