//FormAI DATASET v1.0 Category: Port Scanner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define MIN_PORT 1
#define MAX_PORT 65535

int main(int argc, char *argv[])
{
    int sockfd, i;
    struct sockaddr_in target_addr;
    char *target_ip, ip_str[INET_ADDRSTRLEN];

    if (argc < 2 || argc > 3)
    {
        printf("Usage: %s <ip_address> [port]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    target_ip = argv[1];

    if (argc == 3)
    {
        i = atoi(argv[2]);
        if (i < MIN_PORT || i > MAX_PORT)
        {
            printf("Invalid port number\n");
            exit(EXIT_FAILURE);
        }
    }

    printf("Scanning ports on %s\n", target_ip);

    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(i);

    if (inet_pton(AF_INET, target_ip, &target_addr.sin_addr) != 1)
    {
        printf("Error: invalid IP address %s\n", target_ip);
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    for (i = MIN_PORT; i <= MAX_PORT; i++)
    {
        target_addr.sin_port = htons(i);
        if (connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr)) == 0)
        {
            inet_ntop(AF_INET, &target_addr.sin_addr, ip_str, sizeof(ip_str));
            printf("Port %d on %s is open\n", i, ip_str);
        }
    }

    close(sockfd);

    return 0;
}