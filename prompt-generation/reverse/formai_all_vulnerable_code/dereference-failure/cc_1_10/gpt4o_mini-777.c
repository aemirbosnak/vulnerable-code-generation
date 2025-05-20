//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <linux/wireless.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_SSID_LENGTH 32
#define MAX_NETWORKS 100

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} WiFiNetwork;

WiFiNetwork networks[MAX_NETWORKS];
int network_count = 0;

void scan_networks() {
    struct ifaddrs *ifaddr, *ifa;
    int family, s;
    
    // Retrieving the list of network interfaces
    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    // Iterating through the interfaces
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL || (ifa->ifa_flags & IFF_UP) == 0)
            continue;

        // Checking for wireless interfaces
        if (ifa->ifa_addr->sa_family == AF_PACKET) {
            printf("Scanning for WiFi networks..\n");
            struct iwreq wrq;
            memset(&wrq, 0, sizeof(wrq)); // Clear the structure
            strncpy(wrq.ifr_name, ifa->ifa_name, IFNAMSIZ);

            // Opening a socket for ioctl
            s = socket(AF_INET, SOCK_DGRAM, 0);
            if (s < 0) {
                perror("Socket creation failed");
                continue;
            }

            // Performing the scan
            if (ioctl(s, SIOCGIWSCAN, &wrq) == -1) {
                perror("ioctl");
                close(s);
                continue;
            }

            // Assuming that networks were found and indexed
            int num_networks = rand() % 15 + 1; // Just for demonstration
            
            // Populate network data for demonstration
            for (int i = 0; i < num_networks && network_count < MAX_NETWORKS; i++) {
                snprintf(networks[network_count].ssid, MAX_SSID_LENGTH, "Network_%d", network_count + 1);
                networks[network_count].signal_strength = rand() % 100; // Mock signal strength
                network_count++;
            }

            close(s);
        }
    }

    freeifaddrs(ifaddr);
}

void display_networks() {
    printf("Found Networks:\n");
    printf("%-35s %-15s\n", "SSID", "Signal Strength (%)");
    printf("------------------------------------------------------\n");

    for (int i = 0; i < network_count; i++) {
        printf("%-35s %-15d\n", networks[i].ssid, networks[i].signal_strength);
    }
}

int main() {
    printf("Elementary! A C Wireless Network Scanner.\n");
    printf("By Sherlock Holmes.\n\n");

    scan_networks();
    display_networks();

    printf("End of scan. Good day!");

    return 0;
}