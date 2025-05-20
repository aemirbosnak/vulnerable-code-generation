//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

#define SIZE_ETHERNET 14
#define ETHER_HDR_LEN 14

// Ethernet header
struct ethernet_header {
    u_char dest_mac[6];
    u_char src_mac[6];
    u_short ether_type;
};

// Callback function to be called by pcap when a packet is captured
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ethernet_header *eth_header;
    
    // Cast the packet data to ethernet header
    eth_header = (struct ethernet_header *)packet;

    // Print source and destination MAC addresses in readable format
    printf("Source MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
           eth_header->src_mac[0], eth_header->src_mac[1], eth_header->src_mac[2],
           eth_header->src_mac[3], eth_header->src_mac[4], eth_header->src_mac[5]);
    
    printf("Destination MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
           eth_header->dest_mac[0], eth_header->dest_mac[1], eth_header->dest_mac[2],
           eth_header->dest_mac[3], eth_header->dest_mac[4], eth_header->dest_mac[5]);

    printf("Packet Length: %d bytes\n", header->len);
    printf("---------------------------------\n");
}

int main(int argc, char *argv[]) {
    pcap_if_t *interfaces, *temp;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Check for the required user input
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    // Find all available network interfaces
    if (pcap_findalldevs(&interfaces, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return 1;
    }

    // Locate the requested interface
    temp = interfaces;
    while (temp != NULL) {
        if (strcmp(temp->name, argv[1]) == 0) {
            break;
        }
        temp = temp->next;
    }

    // Check if the interface was found
    if (temp == NULL) {
        fprintf(stderr, "Interface %s not found.\n", argv[1]);
        pcap_freealldevs(interfaces);
        return 1;
    }

    // Open the interface for capturing packets
    handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", argv[1], errbuf);
        pcap_freealldevs(interfaces);
        return 1;
    }

    // Start capturing packets
    printf("Starting packet capture on %s...\n", argv[1]);
    pcap_loop(handle, 0, packet_handler, NULL);

    // Cleanup
    pcap_close(handle);
    pcap_freealldevs(interfaces);
    return 0;
}