//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <arpa/inet.h>

// Define structure for Ethernet header
struct ethhdr {
    u_char h_dest[6];  // Destination MAC address
    u_char h_source[6]; // Source MAC address
    u_short h_proto;    // Protocol type
};

// Define structure for IPv4 header
struct iphdr {
    u_char ihl: 4, version: 4;    // IP header length and version
    u_char tos;                   // Type of service
    u_short tot_len;              // Total length of packet
    u_short id;                   // Identification
    u_short frag_off;             // Fragment offset field
    u_char ttl;                   // Time to live
    u_char protocol;              // Protocol (TCP, UDP, ICMP)
    u_short check;                // IP checksum
    struct in_addr saddr;         // Source address
    struct in_addr daddr;         // Destination address
};

// Packet handler function
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ethhdr *eth = (struct ethhdr *)packet;
    struct iphdr *ip = (struct iphdr *)(packet + sizeof(struct ethhdr));

    // Display MAC addresses
    printf("Source MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
           eth->h_source[0], eth->h_source[1], eth->h_source[2],
           eth->h_source[3], eth->h_source[4], eth->h_source[5]);
    printf("Destination MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
           eth->h_dest[0], eth->h_dest[1], eth->h_dest[2],
           eth->h_dest[3], eth->h_dest[4], eth->h_dest[5]);

    // Display IP addresses
    printf("Source IP: %s\n", inet_ntoa(ip->saddr));
    printf("Destination IP: %s\n", inet_ntoa(ip->daddr));
    printf("Protocol: %d\n", ip->protocol);
    printf("==============================================\n");
}

int main(int argc, char *argv[]) {
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Check for device arguments
    if (argc != 2) {
        fprintf(stderr, "usage: %s <device>\n", argv[0]);
        return 1;
    }

    // Get network devices list
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Could not find devices: %s\n", errbuf);
        return 1;
    }

    // Find the selected device
    for (device = alldevs; device != NULL; device = device->next) {
        if (strcmp(device->name, argv[1]) == 0) {
            break;
        }
    }

    // If device is not found
    if (device == NULL) {
        fprintf(stderr, "Device not found.\n");
        pcap_freealldevs(alldevs);
        return 1;
    }

    // Open the device for capturing
    handle = pcap_open_live(device->name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device->name, errbuf);
        pcap_freealldevs(alldevs);
        return 1;
    }

    // Start capturing packets
    printf("Listening on %s...\n", device->name);
    pcap_loop(handle, 0, packet_handler, NULL);

    // Clean up and exit
    pcap_freealldevs(alldevs);
    pcap_close(handle);
    return 0;
}