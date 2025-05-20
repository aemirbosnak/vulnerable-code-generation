//FormAI DATASET v1.0 Category: System administration ; Style: scientific
/*
 * Program: network_util.c
 * Purpose: Example system administration program to perform analysis on network data.
 * Author: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <net/if.h>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netdb.h>

#define ERROR -1

struct if_data *ifdt;

// Function to get the IP address of the local machine
void get_my_ip() {
    struct ifaddrs *addrs, *tmp;
    getifaddrs(&addrs);
    tmp = addrs;

    while (tmp) {
        if (tmp->ifa_addr && tmp->ifa_addr->sa_family == AF_INET) {
            struct sockaddr_in *pAddr = (struct sockaddr_in *)tmp->ifa_addr;
            printf("Interface Name: %s\n", tmp->ifa_name);
            printf("My IP Address: %s\n", inet_ntoa(pAddr->sin_addr));
        }

        tmp = tmp->ifa_next;
    }

    freeifaddrs(addrs);
}

// Function to scan for open ports on a remote machine
void scan_ports(const char *host, int start_port, int end_port) {
    struct hostent *he;
    struct sockaddr_in addr;
    int sock, i;

    if ((he = gethostbyname(host)) == NULL) {
        herror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    for (i = start_port; i <= end_port; i++) {
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(i);
        addr.sin_addr = *((struct in_addr*)he->h_addr);

        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == ERROR) {
            perror("socket");
            exit(EXIT_FAILURE);
        }

        if (connect(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr)) == ERROR) {
            printf("Port %d is closed\n", i);
        } else {
            printf("Port %d is open\n", i);
        }

        close(sock);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <local> <start port> <end port>\n", argv[0]);
        printf("Usage: %s <remote> <hostname> <start port> <end port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "local") == 0) {
        get_my_ip();
    } else if (strcmp(argv[1], "remote") == 0) {
        scan_ports(argv[2], atoi(argv[3]), atoi(argv[4]));
    } else {
        printf("Invalid argument\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}