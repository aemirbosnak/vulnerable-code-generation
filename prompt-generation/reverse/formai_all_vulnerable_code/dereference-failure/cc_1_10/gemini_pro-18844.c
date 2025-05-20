//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <ifaddrs.h>
#include <netdb.h>

#define MAX_INTERFACES 16
#define MAX_HOSTS 256

struct interface {
    char name[16];
    struct sockaddr_in addr;
    struct sockaddr_in mask;
};

struct host {
    char name[256];
    struct sockaddr_in addr;
};

int main() {
    struct interface interfaces[MAX_INTERFACES];
    int num_interfaces = 0;

    struct host hosts[MAX_HOSTS];
    int num_hosts = 0;

    // Get the list of network interfaces
    struct ifaddrs *addrs;
    if (getifaddrs(&addrs) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    // Iterate over the list of interfaces
    struct ifaddrs *addr;
    for (addr = addrs; addr != NULL; addr = addr->ifa_next) {
        // Skip non-IPv4 interfaces
        if (addr->ifa_addr->sa_family != AF_INET) {
            continue;
        }

        // Get the interface name
        strncpy(interfaces[num_interfaces].name, addr->ifa_name, sizeof(interfaces[num_interfaces].name) - 1);

        // Get the interface address
        interfaces[num_interfaces].addr = *(struct sockaddr_in *)addr->ifa_addr;

        // Get the interface mask
        interfaces[num_interfaces].mask = *(struct sockaddr_in *)addr->ifa_netmask;

        num_interfaces++;
    }

    freeifaddrs(addrs);

    // Print the list of interfaces
    printf("Interfaces:\n");
    for (int i = 0; i < num_interfaces; i++) {
        printf("  %s %s/%d\n", interfaces[i].name, inet_ntoa(interfaces[i].addr.sin_addr), ntohl(interfaces[i].mask.sin_addr.s_addr));
    }

    // Get the list of hosts
    struct hostent *host;
    for (int i = 0; i < 256; i++) {
        char hostname[256];
        sprintf(hostname, "192.168.1.%d", i);

        host = gethostbyname(hostname);
        if (host == NULL) {
            continue;
        }

        strncpy(hosts[num_hosts].name, hostname, sizeof(hosts[num_hosts].name) - 1);
        hosts[num_hosts].addr = *(struct sockaddr_in *)host->h_addr_list[0];

        num_hosts++;
    }

    // Print the list of hosts
    printf("\nHosts:\n");
    for (int i = 0; i < num_hosts; i++) {
        printf("  %s %s\n", hosts[i].name, inet_ntoa(hosts[i].addr.sin_addr));
    }

    return 0;
}