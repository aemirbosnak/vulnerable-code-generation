//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>

#define MAX_INTERFACES 64

// Define a struct for storing network interfaces information
struct network_interface {
    int index;
    char name[IFNAMSIZ];
    char ip_address[INET_ADDRSTRLEN];
};

int main() {
    // Declare a char array for storing error messages
    char error_buffer[256];

    // Declare a struct for storing network interfaces information and initialize it to null
    struct network_interface interfaces[MAX_INTERFACES] = {0};

    // Open a socket to get network interfaces information
    int socket_descriptor = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);
    if (socket_descriptor == -1) {
        strerror_r(errno, error_buffer, sizeof(error_buffer));
        fprintf(stderr, "Error: Failed to create a socket. %s\n", error_buffer);
        exit(EXIT_FAILURE);
    }

    // Get a list of network interfaces and their index from the socket
    struct ifreq ifaces[MAX_INTERFACES];
    struct ifconf ifc;
    ifc.ifc_len = sizeof(ifaces);
    ifc.ifc_req = ifaces;
    if (ioctl(socket_descriptor, SIOCGIFCONF, &ifc) == -1) {
        strerror_r(errno, error_buffer, sizeof(error_buffer));
        fprintf(stderr, "Error: Failed to get the list of network interfaces. %s\n", error_buffer);
        close(socket_descriptor);
        exit(EXIT_FAILURE);
    }

    // Iterate through the network interfaces and store information about each interface
    int num_interfaces = ifc.ifc_len / sizeof(struct ifreq);
    struct ifreq *iface;
    int interface_index = 0;
    for (int i = 0; i < num_interfaces; i++) {
        iface = &ifc.ifc_req[i];

        // Get the interface flags
        if (ioctl(socket_descriptor, SIOCGIFFLAGS, iface) == -1) {
            strerror_r(errno, error_buffer, sizeof(error_buffer));
            fprintf(stderr, "Error: Failed to get the flags of the network interface %s. %s\n", iface->ifr_name, error_buffer);
            continue;
        }

        // Skip loopback and non-up interfaces
        if ((iface->ifr_flags & IFF_LOOPBACK) || !(iface->ifr_flags & IFF_UP)) {
            continue;
        }

        // Get the IP address of the network interface
        if (ioctl(socket_descriptor, SIOCGIFADDR, iface) == -1) {
            strerror_r(errno, error_buffer, sizeof(error_buffer));
            fprintf(stderr, "Error: Failed to get the IP address of the network interface %s. %s\n", iface->ifr_name, error_buffer);
            continue;
        }
        struct sockaddr_in *interface_address = (struct sockaddr_in*) &iface->ifr_addr;
        char ip_address[INET_ADDRSTRLEN];
        if (inet_ntop(AF_INET, &interface_address->sin_addr, ip_address, sizeof(ip_address)) == NULL) {
            strerror_r(errno, error_buffer, sizeof(error_buffer));
            fprintf(stderr, "Error: Failed to convert the IP address of the network interface %s to a string. %s\n", iface->ifr_name, error_buffer);
            continue;
        }

        // Store the interface information in the struct array
        strncpy(interfaces[interface_index].name, iface->ifr_name, IFNAMSIZ - 1);
        interfaces[interface_index].name[IFNAMSIZ - 1] = '\0';
        interfaces[interface_index].index = interface_index;
        strncpy(interfaces[interface_index].ip_address, ip_address, INET_ADDRSTRLEN - 1);
        interfaces[interface_index].ip_address[INET_ADDRSTRLEN - 1] = '\0';
        interface_index++;

    }

    // Close the socket
    close(socket_descriptor);

    // Print the list of network interfaces and their IP addresses
    printf("Found %d network interfaces:\n", interface_index);
    for (int i = 0; i < interface_index; i++) {
        printf("%s (index %d): %s\n", interfaces[i].name, interfaces[i].index, interfaces[i].ip_address);
    }

    return 0;
}