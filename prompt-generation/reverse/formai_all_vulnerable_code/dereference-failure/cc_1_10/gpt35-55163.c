//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define MAX_INTERFACES 128
#define BUFFER_SIZE 4096

struct interface_info {
    int index;
    char name[IF_NAMESIZE];
    char ip_address[INET_ADDRSTRLEN];
    char netmask[INET_ADDRSTRLEN];
};

int get_network_interfaces(struct interface_info *interfaces, int max_interfaces) {
    struct ifreq ifaces[MAX_INTERFACES];
    int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    int num_interfaces, i;

    if (socket_fd < 0) {
        fprintf(stderr, "Failed to create socket: %s\n", strerror(errno));
        return -1;
    }

    if (ioctl(socket_fd, SIOCGIFCONF, &ifaces) < 0) {
        fprintf(stderr, "Failed to get interfaces: %s\n", strerror(errno));
        close(socket_fd);
        return -1;
    }

    num_interfaces = sizeof(ifaces) / sizeof(struct ifreq);
    if (num_interfaces > max_interfaces) {
        num_interfaces = max_interfaces;
    }

    for (i = 0; i < num_interfaces; i++) {
        struct ifreq *iface = &ifaces[i];
        struct interface_info *info = &interfaces[i];
        struct sockaddr_in *addr;

        strcpy(info->name, iface->ifr_name);
        ioctl(socket_fd, SIOCGIFINDEX, iface);
        info->index = iface->ifr_ifindex;
        ioctl(socket_fd, SIOCGIFADDR, iface);
        addr = (struct sockaddr_in *) &(iface->ifr_addr);
        inet_ntop(AF_INET, &addr->sin_addr, info->ip_address, INET_ADDRSTRLEN);
        ioctl(socket_fd, SIOCGIFNETMASK, iface);
        addr = (struct sockaddr_in *) &(iface->ifr_netmask);
        inet_ntop(AF_INET, &addr->sin_addr, info->netmask, INET_ADDRSTRLEN);
    }

    close(socket_fd);
    return num_interfaces;
}

int main() {
    struct interface_info interfaces[MAX_INTERFACES];
    char buffer[BUFFER_SIZE];
    int num_interfaces, i, j, k;

    num_interfaces = get_network_interfaces(interfaces, MAX_INTERFACES);
    if (num_interfaces < 0) {
        fprintf(stderr, "Failed to get network interfaces.\n");
        exit(1);
    }

    printf("Found %d network interfaces:\n", num_interfaces);
    for (i = 0; i < num_interfaces; i++) {
        struct interface_info *info = &interfaces[i];
        printf("Interface #%d: %s\n", info->index, info->name);
        printf("  IP Address: %s\n", info->ip_address);
        printf("  Netmask:    %s\n", info->netmask);
    }

    printf("\nScanning for wireless networks...\n");

    for (i = 0; i < num_interfaces; i++) {
        struct interface_info *info = &interfaces[i];
        if (strncmp(info->name, "wlan", 4) == 0) {
            sprintf(buffer, "iwlist %s scan", info->name);
            printf("\nUsing interface %s...\n", info->name);
            printf("Executing command: %s\n", buffer);
            system(buffer);
        }
    }

    return 0;
}