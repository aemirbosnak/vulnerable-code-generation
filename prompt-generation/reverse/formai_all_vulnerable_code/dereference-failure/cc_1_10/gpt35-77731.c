//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include <ifaddrs.h>
#include <netdb.h>
#include <net/if.h>

#define MAX_DEVICES 100
#define MAX_NAME_LEN 50

struct network_device {
    char device_name[MAX_NAME_LEN];
    char ip_address[INET6_ADDRSTRLEN];
    char mac_address[18];
};

int device_count = 0;
struct network_device devices[MAX_DEVICES];

void get_devices() {
    struct ifaddrs *ifaddr, *ifa;
    int family, s, n;
    char host[NI_MAXHOST];

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    for (ifa = ifaddr, n = 0; ifa != NULL && n < MAX_DEVICES; ifa = ifa->ifa_next, n++) {
        if (ifa->ifa_addr == NULL)
            continue;

        family = ifa->ifa_addr->sa_family;

        if ((family == AF_INET || family == AF_INET6) && (ifa->ifa_flags & IFF_LOOPBACK) == 0) {
            if (getnameinfo(ifa->ifa_addr, (family == AF_INET) ? sizeof(struct sockaddr_in) :
                sizeof(struct sockaddr_in6), host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST) == 0) {
                strcpy(devices[device_count].device_name, ifa->ifa_name);
                strcpy(devices[device_count].ip_address, host);
                device_count++;
            }
        }
    }

    freeifaddrs(ifaddr);
}

void print_devices() {
    int i;

    for (i = 0; i < device_count; i++) {
        printf("%s %s\n", devices[i].device_name, devices[i].ip_address);
    }
}

int main() {
    get_devices();
    print_devices();

    return 0;
}