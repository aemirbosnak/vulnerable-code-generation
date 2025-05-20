//FormAI DATASET v1.0 Category: Port Scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void scan_port(const char *ip_address, int port)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip_address);
    serv_addr.sin_port = htons(port);

    int status = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    if (status == 0) {
        printf("[*] Port %d is open\n", port);
    }
    close(sockfd);
}

void recursive_scan(const char *ip_address, int start_port, int end_port)
{
    if (start_port > end_port) {
        return;
    }
    scan_port(ip_address, start_port);
    recursive_scan(ip_address, start_port + 1, end_port);
}

int main(int argc, char *argv[])
{
    if (argc != 4) {
        printf("[*] Usage: %s <IP address> <starting port> <ending port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    printf("[*] Starting port scan on %s\n", ip_address);

    recursive_scan(ip_address, start_port, end_port);

    printf("[*] Port scan complete\n");

    return 0;
}