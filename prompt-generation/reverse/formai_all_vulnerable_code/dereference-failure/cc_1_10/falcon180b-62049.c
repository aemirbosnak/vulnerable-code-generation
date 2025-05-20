//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <net/if.h>
#include <ifaddrs.h>

#define BUFFER_SIZE 1024

int main() {
    int sock = -1;
    struct ifaddrs *ifaddr = NULL, *ifa = NULL;
    void *tmp = NULL;
    char buffer[BUFFER_SIZE];
    const char *dev = "wlan0"; // Change to your wireless interface name

    if (getifaddrs(&ifaddr) == -1) {
        fprintf(stderr, "getifaddrs() failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    for (ifa = ifaddr; ifa!= NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL)
            continue;

        if (ifa->ifa_addr->sa_family == AF_INET) {
            struct sockaddr_in *sin = (struct sockaddr_in *) ifa->ifa_addr;
            if (strcmp(ifa->ifa_name, dev) == 0) {
                sock = socket(AF_INET, SOCK_DGRAM, 0);
                if (sock == -1) {
                    fprintf(stderr, "socket() failed: %s\n", strerror(errno));
                    exit(EXIT_FAILURE);
                }

                char ip[INET_ADDRSTRLEN];
                inet_ntop(AF_INET, &sin->sin_addr, ip, INET_ADDRSTRLEN);
                printf("Wireless interface %s with IP address %s\n", dev, ip);

                close(sock);
                break;
            }
        }
    }

    freeifaddrs(ifaddr);
    return 0;
}