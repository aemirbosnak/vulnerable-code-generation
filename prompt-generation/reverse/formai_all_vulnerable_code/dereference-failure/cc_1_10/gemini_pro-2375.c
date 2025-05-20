//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_INTERFACES 32

struct interface_info {
    char name[IFNAMSIZ];
    char ip_address[INET_ADDRSTRLEN];
    char mac_address[18];
    int is_up;
};

int main() {
    // Get the number of network interfaces
    int num_interfaces;
    if (ioctl(0, SIOCGIFCOUNT, &num_interfaces) == -1) {
        perror("ioctl(SIOCGIFCOUNT)");
        return EXIT_FAILURE;
    }

    // Allocate memory for the interface info array
    struct interface_info *interfaces = malloc(sizeof(struct interface_info) * num_interfaces);
    if (interfaces == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    // Get the interface information
    for (int i = 0; i < num_interfaces; i++) {
        struct ifreq ifr;
        strncpy(ifr.ifr_name, "eth", sizeof(ifr.ifr_name));

        // Get the interface name
        if (ioctl(0, SIOCGIFNAME, &ifr) == -1) {
            perror("ioctl(SIOCGIFNAME)");
            return EXIT_FAILURE;
        }
        strcpy(interfaces[i].name, ifr.ifr_name);

        // Get the IP address
        if (ioctl(0, SIOCGIFADDR, &ifr) == -1) {
            perror("ioctl(SIOCGIFADDR)");
            return EXIT_FAILURE;
        }
        struct sockaddr_in *addr = (struct sockaddr_in *)&ifr.ifr_addr;
        inet_ntop(AF_INET, &addr->sin_addr, interfaces[i].ip_address, sizeof(interfaces[i].ip_address));

        // Get the MAC address
        if (ioctl(0, SIOCGIFHWADDR, &ifr) == -1) {
            perror("ioctl(SIOCGIFHWADDR)");
            return EXIT_FAILURE;
        }
        memcpy(interfaces[i].mac_address, ifr.ifr_hwaddr.sa_data, sizeof(interfaces[i].mac_address));

        // Check if the interface is up
        if (ioctl(0, SIOCGIFFLAGS, &ifr) == -1) {
            perror("ioctl(SIOCGIFFLAGS)");
            return EXIT_FAILURE;
        }
        interfaces[i].is_up = (ifr.ifr_flags & IFF_UP) != 0;
    }

    // Print the interface information
    printf("Network Topology Map:\n");
    for (int i = 0; i < num_interfaces; i++) {
        printf("Interface: %s\n", interfaces[i].name);
        printf("IP Address: %s\n", interfaces[i].ip_address);
        printf("MAC Address: %s\n", interfaces[i].mac_address);
        printf("Status: %s\n", interfaces[i].is_up ? "Up" : "Down");
        printf("\n");
    }

    // Free the memory for the interface info array
    free(interfaces);

    return EXIT_SUCCESS;
}