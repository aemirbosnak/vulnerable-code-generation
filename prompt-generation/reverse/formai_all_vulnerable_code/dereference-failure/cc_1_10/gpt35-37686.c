//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define PORT_START 1
#define PORT_END 65535

void scan_port(char *ip_address, int port)
{
    struct sockaddr_in sa;
    memset(&sa, 0, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr(ip_address);
    sa.sin_port = htons(port);
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket creation failed");
        return;
    }
    int result = connect(sockfd, (struct sockaddr *)&sa, sizeof(sa));
    if (result < 0 && errno != ECONNREFUSED)
    {
        perror("connection failure");
    }
    else if (result == 0)
    {
        printf("Port %d is open on IP %s\n", port, ip_address);
    }
    close(sockfd);
}

void scan_ip(char *ip_prefix, int port)
{
    char ip_address[16];
    for (int i = 1; i < 255; i++)
    {
        snprintf(ip_address, 16, "%s.%d", ip_prefix, i);
        scan_port(ip_address, port);
    }
}

void scan_network(char *network, int port)
{
    char *ip_prefix = strtok(network, "/");
    int netmask = atoi(strtok(NULL, "/"));
    struct in_addr addr;
    inet_aton(ip_prefix, &addr);
    uint32_t start_address = ntohl(addr.s_addr);
    uint32_t end_address = start_address ^ ((1 << (32 - netmask)) - 1);
    for (uint32_t i = start_address; i <= end_address; i++)
    {
        addr.s_addr = htonl(i);
        char *ip_address = inet_ntoa(addr);
        scan_ip(ip_address, port);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: ./wireless_scanner network port\n");
        return 0;
    }
    int port = atoi(argv[2]);
    if (port < PORT_START || port > PORT_END)
    {
        printf("Port must be between %d and %d\n", PORT_START, PORT_END);
        return 0;
    }
    scan_network(argv[1], port);
    return 0;
}