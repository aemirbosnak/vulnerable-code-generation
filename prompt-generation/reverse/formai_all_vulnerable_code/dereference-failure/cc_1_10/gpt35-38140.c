//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_IFACE_NAME_LEN 40
#define MAX_IP_ADDR_LEN 16
#define MAX_DEVICES 100

/* Struct to store information about a network device */
typedef struct {
    char name[MAX_IFACE_NAME_LEN];
    char ip_addr[MAX_IP_ADDR_LEN];
} network_device_t;

/* Function that returns an array of all network devices on the system */
int get_network_devices(network_device_t* devices) {
    struct ifaddrs* ifaddr, *ifa;
    int family, s, n;
    char host[MAX_IP_ADDR_LEN];

    // Get all network interfaces on the system
    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        return -1;
    }

    // Loop through all network interfaces
    n = 0;
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL) {
            continue;
        }

        family = ifa->ifa_addr->sa_family;

        // Only consider IPv4 network interfaces
        if (family == AF_INET) {
            s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), host, MAX_IP_ADDR_LEN, NULL, 0, NI_NUMERICHOST);

            if (s != 0) {
                fprintf(stderr, "getnameinfo() failed: %s\n", gai_strerror(s));
                return -1;
            }

            // Add device to array
            strncpy(devices[n].name, ifa->ifa_name, MAX_IFACE_NAME_LEN);
            strncpy(devices[n].ip_addr, host, MAX_IP_ADDR_LEN);
            n++;
        }
    }

    freeifaddrs(ifaddr);

    return n;
}

int main() {
    network_device_t devices[MAX_DEVICES];
    int num_devices = get_network_devices(devices);

    if (num_devices < 0) {
        fprintf(stderr, "Failed to get network devices\n");
        return -1;
    }

    printf("Network Devices:\n");
    printf("%-10s %-15s\n", "Name", "IP Address");
    printf("-------------------------\n");
    for (int i = 0; i < num_devices; i++) {
        printf("%-10s %-15s\n", devices[i].name, devices[i].ip_addr);
    }

    return 0;
}