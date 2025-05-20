//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define MAX_INTERFACES 64 // Maximum number of network interfaces
#define MAX_INTERFACE_NAME_LEN 16 // Maximum length of interface name
#define IPV4_ADDR_LEN 4 // Length of an IPv4 address in bytes

// Struct to represent a network interface and its associated data
typedef struct {
    char name[MAX_INTERFACE_NAME_LEN]; // Interface name
    uint8_t mac[6]; // MAC address
    uint8_t ip[IPV4_ADDR_LEN]; // IPv4 address
    uint8_t netmask[IPV4_ADDR_LEN]; // Network mask for the interface
    uint8_t broadcast[IPV4_ADDR_LEN]; // Broadcast address for the interface
} network_interface_t;

/**
 * Scan the current machine's network interfaces and print information about each interface.
 * This function populates the given interfaces array with the discovered network interfaces.
 * 
 * @param interfaces - Pointer to an array of network_interface_t structs to populate with discovered network interfaces.
 * @param num_interfaces - Pointer to an int to store the number of discovered network interfaces.
 */
void scan_network_interfaces(network_interface_t* interfaces, int* num_interfaces) {
    int sockfd;
    struct ifconf ifc;
    struct ifreq ifr[MAX_INTERFACES];
    int n;
    int i;
    char* p;

    // Open a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Query for network interface information
    ifc.ifc_len = sizeof(ifr);
    ifc.ifc_ifcu.ifcu_buf = (void*) ifr;
    if (ioctl(sockfd, SIOCGIFCONF, &ifc) != 0) {
        perror("ioctl");
        exit(1);
    }

    // Iterate over all network interfaces
    p = ifc.ifc_buf;
    for (i = 0; i < ifc.ifc_len; ) {
        struct ifreq *r = (struct ifreq *) (p+i);
        int len = sizeof *r;

        // Only consider interfaces with valid IPv4 addresses
        if (r->ifr_addr.sa_family == AF_INET) {
            char* name = r->ifr_name;
            struct sockaddr_in* addr = (struct sockaddr_in*) &r->ifr_addr;

            // Get MAC address
            if (ioctl(sockfd, SIOCGIFHWADDR, r) == 0) {
                memcpy(interfaces[*num_interfaces].mac, r->ifr_hwaddr.sa_data, 6);
            } else {
                printf("Failed to get MAC address for interface %s: %s\n", name, strerror(errno));
            }

            // Get IPv4 address
            memcpy(interfaces[*num_interfaces].ip, &addr->sin_addr.s_addr, IPV4_ADDR_LEN);

            // Get netmask
            if (ioctl(sockfd, SIOCGIFNETMASK, r) == 0) {
                struct sockaddr_in* netmask = (struct sockaddr_in*) &r->ifr_netmask;
                memcpy(interfaces[*num_interfaces].netmask, &netmask->sin_addr.s_addr, IPV4_ADDR_LEN);
            } else {
                printf("Failed to get netmask for interface %s: %s\n", name, strerror(errno));
            }

            // Calculate broadcast address
            for (n = 0; n < IPV4_ADDR_LEN; n++) {
                interfaces[*num_interfaces].broadcast[n] = (interfaces[*num_interfaces].ip[n] & interfaces[*num_interfaces].netmask[n]) | (~interfaces[*num_interfaces].netmask[n]);
            }

            // Save interface name
            strncpy(interfaces[*num_interfaces].name, name, MAX_INTERFACE_NAME_LEN-1);

            // Move to next network interface
            (*num_interfaces)++;
            i += len;
        } else {
            // Move to next network interface
            i += sizeof(struct ifreq);
        }
    }

    // Close the socket
    close(sockfd);
}

/**
 * Print the given IPv4 address in dotted-decimal format.
 * 
 * @param ip - Pointer to the IPv4 address to print.
 */
void print_ipv4_addr(uint8_t* ip) {
    printf("%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
}

/**
 * Print the given MAC address in colon-separated hexadecimal format.
 * 
 * @param mac - Pointer to the MAC address to print.
 */
void print_mac_addr(uint8_t* mac) {
    printf("%02x:%02x:%02x:%02x:%02x:%02x", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
}

int main() {
    network_interface_t interfaces[MAX_INTERFACES];
    int num_interfaces = 0;
    int i;

    // Scan for network interfaces
    scan_network_interfaces(interfaces, &num_interfaces);

    // Print information about each network interface
    for (i = 0; i < num_interfaces; i++) {
        printf("Interface %d\n", i+1);
        printf("  Name:       %s\n", interfaces[i].name);
        printf("  MAC:        ");
        print_mac_addr(interfaces[i].mac);
        printf("\n");
        printf("  IPv4 Addr:  ");
        print_ipv4_addr(interfaces[i].ip);
        printf("\n");
        printf("  Netmask:    ");
        print_ipv4_addr(interfaces[i].netmask);
        printf("\n");
        printf("  Broadcast:  ");
        print_ipv4_addr(interfaces[i].broadcast);
        printf("\n");
    }

    return 0;
}