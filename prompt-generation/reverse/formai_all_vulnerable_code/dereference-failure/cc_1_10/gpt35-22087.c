//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/types.h>
#include <ifaddrs.h>

#define MAX_HOSTNAME_LENGTH 256

int main(int argc, char *argv[])
{
    struct ifaddrs *ifaddr, *ifa;
    int family, s, n;
    char host[MAX_HOSTNAME_LENGTH];

    if(getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    printf("Network Topology Mapper:\n\n");
    printf("IP Address \t Network Interface\n\n");

    for(ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if(ifa->ifa_addr == NULL || strcmp(ifa->ifa_name,"lo")==0) 
            continue;

        family = ifa->ifa_addr->sa_family;

        if(family == AF_INET || family == AF_INET6) {

            s = getnameinfo(ifa->ifa_addr,
                    (family == AF_INET) ? sizeof(struct sockaddr_in) :
                    sizeof(struct sockaddr_in6),
                    host, MAX_HOSTNAME_LENGTH,
                    NULL, 0, NI_NUMERICHOST);

            if(s != 0) {
                printf("getnameinfo() failed: %s\n", gai_strerror(s));
                exit(EXIT_FAILURE);
            }

            printf("%-16s \t %s\n", host, ifa->ifa_name);
        }
    }

    freeifaddrs(ifaddr);
    return 0;
}