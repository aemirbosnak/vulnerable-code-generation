//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

#define MAX_DEVICES 1024
#define IP_LENGTH 16

struct device_info {
    char ip_address[IP_LENGTH];
    uint8_t mac_address[6];
    char vendor[64];
};

// function to convert MAC address to string format
char* mac_to_string(const uint8_t* mac) {
    static char mac_string[18];
    snprintf(mac_string, sizeof(mac_string), "%02X:%02X:%02X:%02X:%02X:%02X",
        mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    return mac_string;
}

// function to lookup vendor based on MAC address prefix
char* lookup_vendor(const uint8_t* mac_prefix) {
    static const char* const vendor_list[ ] = {
        "Accton", "Apple", "Cisco", "Dell", "Google", "Hewlett-Packard",
        "Intel", "Juniper", "Lenovo", "Microsoft", "Nokia", "Samsung"
    };
    const uint32_t vendor_codes[ ] = {
        0x0000AC, 0x0000C0, 0x0001C4, 0x0017EE, 0x001A11, 0x001B78,
        0x001CC0, 0x001E37, 0x002128, 0x00248C, 0x0022F0, 0x0024F3
    };
    char* vendor_name = "Unknown";
    uint32_t mac_code = (mac_prefix[0] << 16) | (mac_prefix[1] << 8) | mac_prefix[2];
    for (int i = 0 ; i < 12 ; i++) {
        if (mac_code == vendor_codes[i]) {
            vendor_name = vendor_list[i];
            break;
        }
    }
    return vendor_name;
}

int main(int argc, char* argv[]) {

    int sockfd;
    struct device_info devices[MAX_DEVICES];
    int num_devices = 0;

    // create a UDP socket and bind to port 47808
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in si_me;
    memset(&si_me, 0, sizeof(si_me));
    si_me.sin_family = AF_INET;
    si_me.sin_port = htons(47808);
    si_me.sin_addr.s_addr = htonl(INADDR_ANY);
    int rv = bind(sockfd, (struct sockaddr*)&si_me, sizeof(si_me));
    if (rv == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // receive packets and extract device info
    char buffer[1024];
    struct sockaddr_in si_other;
    socklen_t slen = sizeof(si_other);
    while (1) {
        ssize_t recv_len = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&si_other, &slen);
        if (recv_len == -1) {
            if (errno == EINTR) continue;   // try again if interrupted by signal
            perror("recvfrom");
            exit(EXIT_FAILURE);
        }
        // extract IP and MAC addresses
        char ip_address[IP_LENGTH];
        if (inet_ntop(AF_INET, &si_other.sin_addr, ip_address, sizeof(ip_address)) == NULL) {
            perror("inet_ntop");
            exit(EXIT_FAILURE);
        }
        uint8_t mac_address[6];
        memcpy(mac_address, &buffer[22], 6);
        // record device info
        strncpy(devices[num_devices].ip_address, ip_address, IP_LENGTH);
        memcpy(devices[num_devices].mac_address, mac_address, 6);
        strcpy(devices[num_devices].vendor, lookup_vendor(mac_address));
        num_devices++;
        if (num_devices >= MAX_DEVICES) {
            break;  // too many devices, stop receiving
        }
    }

    // display devices and their info
    printf("%-15s %-17s %s\n", "IP Address", "MAC Address", "Vendor");
    printf("----------------------------------------------\n");
    for (int i = 0 ; i < num_devices ; i++) {
        printf("%-15s %-17s %s\n", devices[i].ip_address, mac_to_string(devices[i].mac_address), devices[i].vendor);
    }

    close(sockfd);
    return 0;
}