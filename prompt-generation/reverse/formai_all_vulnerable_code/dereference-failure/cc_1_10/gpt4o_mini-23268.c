//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: innovative
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/ip.h>

#define MAXPACKETSIZE 65536

// Structure to hold packet information
struct packet_info {
    struct pcap_pkthdr header;
    const u_char *data;
};

// Function to parse IP packets
void process_ip_packet(const u_char *packet, struct packet_info *info) {
    struct ip *ip_header = (struct ip *)(packet + 14);  // Skip Ethernet header

    printf("Packet Number: %d\n", info->header.ts.tv_sec);
    printf("Packet Length: %d bytes\n", info->header.len);
    printf("Source IP: %s\n", inet_ntoa(ip_header->ip_src));
    printf("Destination IP: %s\n", inet_ntoa(ip_header->ip_dst));
    printf("Protocol: %d\n\n", ip_header->ip_p);
}

// Callback function to handle captured packets
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct packet_info info;

    info.header = *header;
    info.data = packet;

    // Process only IP packets
    if (header->caplen >= 14) {  // Ensure Ethernet header is present
        process_ip_packet(packet, &info);
    } else {
        printf("Packet too small to analyze.\n");
    }
}

int main(int argc, char *argv[]) {
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    char *dev;
    int packet_count = 10; // Number of packets to capture

    // Get the list of available devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return 1;
    }

    // Print available devices
    printf("Available devices:\n");
    for (device = alldevs; device != NULL; device = device->next) {
        printf(" - %s\n", device->name);
    }

    // Get the first device
    dev = alldevs->name;
    printf("Using device: %s\n", dev);

    // Open the device for capturing
    handle = pcap_open_live(dev, MAXPACKETSIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", dev, errbuf);
        return 1;
    }

    // Start capturing packets
    printf("Capturing packets...\n");
    pcap_loop(handle, packet_count, packet_handler, NULL);

    // Cleanup and close the device
    pcap_close(handle);
    pcap_freealldevs(alldevs);

    printf("Packet capture finished.\n");
    return 0;
}