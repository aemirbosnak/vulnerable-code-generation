//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <netinet/ether.h>

#define BUFFER_SIZE 1024
#define NETWORK_MASK 24

void print_mac_address(unsigned char *mac) {
    printf("%02x:%02x:%02x:%02x:%02x:%02x\n", 
           mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
}

void scan_network(const char *ip_base) {
    char command[BUFFER_SIZE];
    printf("Scanning the network base: %s...\n", ip_base);
    for (int i = 1; i < 255; i++) {
        sprintf(command, "ping -c 1 %s.%d > /dev/null 2>&1", ip_base, i);
        if (system(command) == 0) {
            printf("Device found at: %s.%d\n", ip_base, i);
            sprintf(command, "arp -an | grep %s.%d", ip_base, i);
            system(command);
        }
    }
}

char* get_ip_base() {
    struct ifaddrs *ifaddr, *ifa;
    char *ip_base = malloc(BUFFER_SIZE);
    memset(ip_base, 0, BUFFER_SIZE);
    
    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        return NULL;
    }
    
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET) {
            struct sockaddr_in *addr = (struct sockaddr_in *)ifa->ifa_addr;
            strcpy(ip_base, inet_ntoa(addr->sin_addr));
            char *last_dot = strrchr(ip_base, '.');
            if (last_dot) {
                *last_dot = '\0';  // Null terminate after last dot
                break;
            }
        }
    }
    freeifaddrs(ifaddr);
    
    return ip_base;
}

int main() {
    printf("!!! Welcome to the Network Topology Mapper !!!\n");
    // Fetch the base IP address of the local network
    char *ip_base = get_ip_base();
    
    if (ip_base == NULL) {
        fprintf(stderr, "Error obtaining IP base.\n");
        return EXIT_FAILURE;
    }

    scan_network(ip_base);

    free(ip_base);
    printf("!!! Network Scan Complete! !!!\n");
    return EXIT_SUCCESS;
}