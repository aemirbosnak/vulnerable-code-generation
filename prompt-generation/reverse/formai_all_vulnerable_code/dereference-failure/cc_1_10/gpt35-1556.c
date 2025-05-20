//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>

#define WLAN_INTERFACE "wlan0"

typedef struct wireless_network {
    char ssid[32];
    int signal_strength;
    char channel[5];
} wireless_network;

typedef struct system_wireless {
    wireless_network *networks;
    int num_networks;
} system_wireless;

// Scans for wireless networks and returns an array of wireless network objects
system_wireless scan_for_wireless_networks() {
    system_wireless system_wifi = {
        .networks = (wireless_network*) malloc(sizeof(wireless_network) * 10), // Allocate memory for 10 networks
        .num_networks = 0
    };

    // Open Socket
    int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock_fd < 0) {
        printf("Error opening datagram socket.\n");
        return system_wifi;
    }
    
    // Get Interface Information
    struct ifreq ifr;
    memset(&ifr, 0, sizeof(struct ifreq));
    strncpy(ifr.ifr_name, WLAN_INTERFACE, IFNAMSIZ-1);
    if (ioctl(sock_fd, SIOCGIFFLAGS, &ifr) < 0) {
        printf("Failed to get interface '%s' status.\n", WLAN_INTERFACE);
        close(sock_fd);
        return system_wifi;
    }

    // Enable Promiscuous Mode
    ifr.ifr_flags |= IFF_PROMISC;
    if (ioctl(sock_fd, SIOCSIFFLAGS, &ifr) < 0) {
        printf("Failed to enable promiscuous mode on interface '%s'.\n", WLAN_INTERFACE);
        close(sock_fd);
        return system_wifi;
    }

    // Scan for Wireless Networks
    char buf[1024];
    while(1) {
        memset(buf, 0, sizeof(buf));
        struct sockaddr_in addr;
        socklen_t addr_len = sizeof(addr);
        if (recvfrom(sock_fd, buf, sizeof(buf), 0, (struct sockaddr*) &addr, &addr_len) < 0) {
            break;
        }
        char ssid[32];
        int signal_strength;
        char channel[5] = "";
        if (strstr(buf, "Beacon (SSID")) {
            sscanf(buf, "Beacon (SSID='%[^\n']')", ssid);
        }
        if (strstr(buf, "Signal level=")) {
            sscanf(buf, "Signal level=%d dBm ", &signal_strength);
        }
        if (strstr(buf, "DS Parameter set: channel ")) {
            sscanf(buf, "DS Parameter set: channel %s", channel);
        }
        if (ssid[0] != '\0' && signal_strength != 0) {
            wireless_network network = {
                .signal_strength = signal_strength,
            };
            strncpy(network.ssid, ssid, strlen(ssid));
            strncpy(network.channel, channel, strlen(channel));
            system_wifi.networks[system_wifi.num_networks++] = network;
        }
        if (system_wifi.num_networks >= 10) { // Maximum number of networks
            break;
        }
    }

    // Disable Promiscuous Mode
    ifr.ifr_flags &= ~IFF_PROMISC;
    if (ioctl(sock_fd, SIOCSIFFLAGS, &ifr) < 0) {
        printf("Failed to disable promiscuous mode on interface '%s'.\n", WLAN_INTERFACE);
    }

    close(sock_fd);

    return system_wifi;
}

int main() {
    system_wireless system_wifi = scan_for_wireless_networks();
    printf("Wireless Network Scanner:\n");
    for (int i=0; i<system_wifi.num_networks; i++) {
        printf("\tSSID: %s\n", system_wifi.networks[i].ssid);
        printf("\tSignal Strength: %d dBm\n", system_wifi.networks[i].signal_strength);
        printf("\tChannel: %s\n\n", system_wifi.networks[i].channel); 
    }

    return 0;
}