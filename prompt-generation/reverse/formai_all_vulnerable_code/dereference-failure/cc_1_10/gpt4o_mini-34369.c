//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <arpa/inet.h>

#define SNAP_LEN 1518   // max bytes to capture per packet
#define SIZE_ETHERNET 14
#define ETHER_ADDR_LEN 6

// Ethernet header
struct ether_header {
    u_char ether_dhost[ETHER_ADDR_LEN]; // destination host address
    u_char ether_shost[ETHER_ADDR_LEN]; // source host address
    u_short ether_type;                  // IP? ARP? RARP? etc
};

// Function to print the packet details
void print_packet(const u_char *packet, struct pcap_pkthdr header) {
    const struct ether_header *ethernet; // Pointer to ethernet header
    ethernet = (struct ether_header*)(packet); // Cast packet to ethernet header
    
    // Extract source and destination MAC addresses
    printf("Packet captured at: %s", ctime((const time_t*)&header.ts.tv_sec));
    printf("Packet length: %d bytes\n", header.len);
    
    printf("Destination MAC Address: ");
    for(int i = 0; i < ETHER_ADDR_LEN; i++) {
        printf("%02x%s", ethernet->ether_dhost[i], (i < ETHER_ADDR_LEN - 1) ? ":" : "");
    }
    
    printf("\nSource MAC Address: ");
    for(int i = 0; i < ETHER_ADDR_LEN; i++) {
        printf("%02x%s", ethernet->ether_shost[i], (i < ETHER_ADDR_LEN - 1) ? ":" : "");
    }
    
    printf("\nEthernet Type: 0x%04x\n", ntohs(ethernet->ether_type));
    printf("-------------------------------------------------\n");
}

// Packet capture callback function
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    print_packet(packet, *header);
}

int main(int argc, char **argv) {
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Check usage
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <device>\n", argv[0]);
        return 1;
    }

    // Find a suitable device
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "pcap_findalldevs() failed: %s\n", errbuf);
        return 1;
    }

    // Find the specified device
    for (device = alldevs; device != NULL; device = device->next) {
        if (strcmp(device->name, argv[1]) == 0) {
            break;
        }
    }

    // Check if device was found
    if (device == NULL) {
        fprintf(stderr, "Device not found: %s\n", argv[1]);
        pcap_freealldevs(alldevs);
        return 1;
    }

    // Open the device for packet capture
    handle = pcap_open_live(device->name, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live() failed: %s\n", errbuf);
        pcap_freealldevs(alldevs);
        return 1;
    }

    // Start packet capture
    printf("Listening on device %s...\n", device->name);
    pcap_loop(handle, 0, packet_handler, NULL);

    // Cleanup
    pcap_freealldevs(alldevs);
    pcap_close(handle);
    
    return 0;
}