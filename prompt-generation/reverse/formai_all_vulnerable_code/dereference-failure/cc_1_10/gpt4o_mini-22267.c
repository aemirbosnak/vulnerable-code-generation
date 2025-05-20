//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/ether.h>
#include <string.h>

#define SIZE_ETHERNET 14

/* Ethernet header */
struct ethernet_header {
    u_char  ether_dhost[ETH_ALEN];    // Destination host address
    u_char  ether_shost[ETH_ALEN];    // Source host address
    u_short ether_type;                // IP? ARP? RARP? etc
};

/* Callback function for packet handling */
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ethernet_header *eth_header;
    struct ip *ip_header;
    char src_ip[INET_ADDRSTRLEN];
    char dst_ip[INET_ADDRSTRLEN];

    // Getting the Ethernet header
    eth_header = (struct ethernet_header *) packet;
    printf("Ethernet Header \n");
    printf("   - Source MAC: %s\n", ether_ntoa((const struct ether_addr *)&eth_header->ether_shost));
    printf("   - Destination MAC: %s\n", ether_ntoa((const struct ether_addr *)&eth_header->ether_dhost));

    // Check if the Ethernet type is IP
    if (ntohs(eth_header->ether_type) == ETHERTYPE_IP) {
        // Move the packet pointer to the IP header
        ip_header = (struct ip *)(packet + SIZE_ETHERNET);
        inet_ntop(AF_INET, &(ip_header->ip_src), src_ip, INET_ADDRSTRLEN);
        inet_ntop(AF_INET, &(ip_header->ip_dst), dst_ip, INET_ADDRSTRLEN);
        
        printf("IP Header \n");
        printf("   - Source IP: %s\n", src_ip);
        printf("   - Destination IP: %s\n", dst_ip);
    }
    printf("----------------------------------------------\n");
}

int main(int argc, char *argv[]) {
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    int packet_count = 10; // Number of packets to capture

    // Check if a device is specified
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <network interface>\n", argv[0]);
        return 1;
    }

    // Retrieve the list of devices
    if (pcap_findalldevs(&alldevs, errbuf) < 0) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return 1;
    }

    // Find the specified device
    for (device = alldevs; device != NULL; device = device->next) {
        if (strcmp(device->name, argv[1]) == 0) {
            break;
        }
    }

    if (device == NULL) {
        fprintf(stderr, "No such device found: %s\n", argv[1]);
        pcap_freealldevs(alldevs);
        return 1;
    }

    // Open the device for capturing
    handle = pcap_open_live(device->name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Failed to open device: %s\n", errbuf);
        pcap_freealldevs(alldevs);
        return 1;
    }

    printf("Capturing packets on %s...\n", device->name);

    // Start capturing packets
    pcap_loop(handle, packet_count, packet_handler, NULL);

    // Cleanup
    pcap_close(handle);
    pcap_freealldevs(alldevs);
    printf("Packet capture complete.\n");

    return 0;
}