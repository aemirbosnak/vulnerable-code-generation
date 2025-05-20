//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/if_ether.h>
#include <string.h>

#define SNAP_LEN 1518

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ether_header *eth_header;
    struct ip *ip_header;
    
    // Ensure packet has enough length for an Ethernet header
    if (header->len < sizeof(struct ether_header)) {
        printf("Packet too short to have an Ethernet header!\n");
        return;
    }
    
    eth_header = (struct ether_header *)packet;
    
    // Check if the packet is IPv4
    if (ntohs(eth_header->ether_type) == ETHERTYPE_IP) {
        // Move to the IP header
        ip_header = (struct ip *)(packet + sizeof(struct ether_header));

        // Convert source IP to human-readable form
        char src_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &ip_header->ip_src, src_ip, sizeof(src_ip));
        
        // Print packet information
        printf("Captured an IP packet from: %s, Size: %d bytes\n", src_ip, header->len);
    } else {
        printf("Captured a non-IP packet of size: %d bytes\n", header->len);
    }
}

int main(int argc, char *argv[]) {
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Get all devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return 1;
    }

    // Print available devices and allow the user to select one
    printf("Available network devices:\n");
    int count = 0;
    for (device = alldevs; device != NULL; device = device->next) {
        printf("%d: %s\n", ++count, device->name);
    }
    
    // Check if any devices were found
    if (count == 0) {
        printf("No devices found!\n");
        return 1;
    }

    printf("Select a device (1 - %d): ", count);
    int choice;
    scanf("%d", &choice);

    // Validate choice
    if (choice < 1 || choice > count) {
        printf("Invalid device choice! Exiting...\n");
        pcap_freealldevs(alldevs);
        return 1;
    }

    // Set the selected device
    for (device = alldevs, count = 0; count < choice - 1; device = device->next, count++);
    
    // Open the device for packet capture
    handle = pcap_open_live(device->name, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device->name, errbuf);
        pcap_freealldevs(alldevs);
        return 1;
    }
    
    printf("Listening on %s...\nPress Ctrl+C to stop.\n", device->name);

    // Start capturing packets
    pcap_loop(handle, 0, packet_handler, NULL);
    
    // Cleanup
    pcap_close(handle);
    pcap_freealldevs(alldevs);
    
    return 0;
}