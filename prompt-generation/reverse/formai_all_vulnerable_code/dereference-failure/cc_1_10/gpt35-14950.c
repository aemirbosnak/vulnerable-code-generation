//FormAI DATASET v1.0 Category: Port Scanner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define MAX_PORT 65535
#define TIMEOUT_SEC 1

bool is_valid_ip_address(char *ip_address)
{
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip_address, &(sa.sin_addr));
    return result != 0;
}

void scan_port(char *ip_address, int port)
{
    int sockfd;
    struct sockaddr_in target_addr;
    struct timeval timeout;
    fd_set socket_fds;
    int select_result;
    char message[] = "HELLO\n";
    char buffer[256] = {0};

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        perror("socket()");
        return;
    }

    timeout.tv_sec = TIMEOUT_SEC;
    timeout.tv_usec = 0;

    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(ip_address);
    target_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr)) != 0)
    {
        if (errno == ECONNREFUSED)
        {
            return;
        }
        else
        {
            perror("connect()");
            return;
        }
    }

    FD_ZERO(&socket_fds);
    FD_SET(sockfd, &socket_fds);

    if (send(sockfd, message, strlen(message), 0) == -1)
    {
        perror("send()");
        return;
    }

    select_result = select(sockfd + 1, &socket_fds, NULL, NULL, &timeout);

    if (select_result < 0)
    {
        perror("select()");
        return;
    }
    else if (select_result == 0)
    {
        return;
    }
    else
    {
        recv(sockfd, buffer, 256, 0);
        printf("Port %d is open on %s with message: %s", port, ip_address, buffer);
    }

    close(sockfd);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <IP Address>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];

    if (!is_valid_ip_address(ip_address))
    {
        printf("Invalid IP Address provided\n");
        return 1;
    }

    printf("Scanning ports on %s\n", ip_address);

    for (int port = 1; port <= MAX_PORT; port++)
    {
        scan_port(ip_address, port);
    }

    printf("Port scanning complete\n");

    return 0;
}