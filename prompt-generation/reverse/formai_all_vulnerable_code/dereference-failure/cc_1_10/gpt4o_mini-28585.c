//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ether.h>
#include <linux/wireless.h>
#include <errno.h>
#include <ifaddrs.h>

// Define maximum number of networks
#define MAX_NETWORKS 100
#define BUFFER_SIZE 1024

// Structure to hold network details
typedef struct {
    char ssid[32];
    int signal_level;
} Network;

void scan_networks(Network networks[], int *network_count) {
    struct iwreq wrq;
    struct ifreq ifr;
    int sock, i;
    char buffer[BUFFER_SIZE];

    // Open a socket to query wireless interfaces
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Loop through available interfaces
    struct ifaddrs *ifaddr, *ifa;
    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Reset network count
    *network_count = 0;

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_flags & IFF_RUNNING && ifa->ifa_addr->sa_family == AF_PACKET) {
            // Use only wireless interfaces (adjust to your specific network interface)
            strcpy(ifr.ifr_name, ifa->ifa_name);
            strncpy(wrq.ifr_name, ifr.ifr_name, IFNAMSIZ);
            wrq.u.data.length = sizeof(buffer);
            wrq.u.data.pointer = buffer;

            // Perform the scan (a mockup command here; this may vary)
            if (ioctl(sock, SIOCGIWSCAN, &wrq) >= 0) {
                // Here you would parse the output and fill networks
                // Simulated just for demonstration
                if (*network_count < MAX_NETWORKS) {
                    snprintf(networks[*network_count].ssid, sizeof(networks[*network_count].ssid), "Network_%d", *network_count);
                    networks[*network_count].signal_level = rand() % 100; // Dummy signal level
                    (*network_count)++;
                }
            }
        }
    }

    freeifaddrs(ifaddr);
    close(sock);
}

void display_networks(Network networks[], int network_count) {
    printf("\n----- SHOCKING WIRELESS NETWORK SCANNER -----\n");
    printf("Found %d Networks in Your Area! 😱\n", network_count);
    printf("==============================================\n");
    for (int i = 0; i < network_count; i++) {
        printf("SSID: %s | Signal Level: %d dBm\n", networks[i].ssid, networks[i].signal_level);
    }
    printf("==============================================\n");
}

int main() {
    Network networks[MAX_NETWORKS];
    int network_count = 0;
    
    srand(time(0)); // Initialize random seed for signal level

    printf("🌐 Scanning for Wireless Networks...\n");

    // Start scanning networks
    scan_networks(networks, &network_count);

    // Display found networks in a shocking manner
    display_networks(networks, network_count);

    return 0;
}