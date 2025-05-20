//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ifaddrs.h>

#define MAX_IP_LENGTH 16
#define MAX_NAME_LENGTH 256
#define MAX_DEVICES 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char ip_address[MAX_IP_LENGTH];
} Device;

typedef struct {
    int num_devices;
    Device devices[MAX_DEVICES];
} Network;

/**
 * Get all IP addresses associated with the current machine
 */
void get_machine_ips(char ips[][MAX_IP_LENGTH], int* num_ips) {
    struct ifaddrs *ifaddr, *ifa;
    int family, s, n;
    char host[MAX_NAME_LENGTH];
    
    *num_ips = 0;
    
    if (getifaddrs(&ifaddr) == -1) {
        fprintf(stderr, "Could not get IP addresses\n");
        exit(EXIT_FAILURE);
    }
    
    // Iterate through all network interfaces
    for (ifa = ifaddr, n = 0; ifa != NULL; ifa = ifa->ifa_next, n++) {
        if (ifa->ifa_addr == NULL) {
            continue;
        }
        
        family = ifa->ifa_addr->sa_family;
        
        // We only care about IPv4 and IPv6 addresses
        if (family != AF_INET && family != AF_INET6) {
            continue;
        }
        
        // Get the host name associated with the interface
        s = getnameinfo(ifa->ifa_addr,
                        (family == AF_INET) ? sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6),
                        host, MAX_NAME_LENGTH, NULL, 0, NI_NUMERICHOST);
        
        if (s != 0) {
            fprintf(stderr, "Could not get IP address for interface %s\n", ifa->ifa_name);
            exit(EXIT_FAILURE);
        }
        
        // Copy the IP address into the ips array
        strncpy(ips[*num_ips], host, MAX_IP_LENGTH);
        (*num_ips)++;
    }
    
    freeifaddrs(ifaddr);
}

/**
 * Map the network topology by discovering all connected devices
 */
void map_network(Network* network) {
    struct sockaddr_in addr;
    struct hostent* host_info;
    int fd, i;
    char ips[MAX_DEVICES][MAX_IP_LENGTH];
    int num_ips = 0;
    
    // Get all IP addresses associated with the machine
    get_machine_ips(ips, &num_ips);
    
    network->num_devices = 0;
    
    // Iterate through all IP addresses
    for (i = 0; i < num_ips; i++) {
        // Skip any IP addresses associated with the loopback interface
        if (strncmp(ips[i], "127.0.0.", 9) == 0) {
            continue;
        }
        
        // Attempt to resolve the hostname associated with the IP address
        if ((host_info = gethostbyaddr(&ips[i], sizeof ips[i], AF_INET)) == NULL) {
            continue;
        }
        
        // Copy the hostname and IP address into a device struct
        Device device;
        strncpy(device.name, host_info->h_name, MAX_NAME_LENGTH);
        strncpy(device.ip_address, ips[i], MAX_IP_LENGTH);
        
        // Add the device struct to the network array
        network->devices[network->num_devices] = device;
        network->num_devices++;
    }
}

/**
 * Print the discovered network topology
 */
void print_network(Network* network) {
    int i;
    
    printf("%d devices discovered:\n", network->num_devices);
    
    for (i = 0; i < network->num_devices; i++) {
        printf("%s (%s)\n", network->devices[i].name, network->devices[i].ip_address);
    }
}

int main() {
    Network network;
    
    map_network(&network);
    print_network(&network);
    
    return 0;
}