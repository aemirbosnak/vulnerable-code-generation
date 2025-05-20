//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/ether.h>
#include <string.h>

#define SNAP_LEN 1518 // Maximum bytes per packet to capture
#define SIZE_ETHERNET 14 // Ethernet header size

// Callback function for processing captured packets
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ether_header *eth_header;
    const struct ip *ip_header;
    char src_ip[INET_ADDRSTRLEN], dst_ip[INET_ADDRSTRLEN];

    // Define pointers for Ethernet and IP headers
    eth_header = (struct ether_header *)packet;

    // Check the Ethernet type for IPv4
    if (ntohs(eth_header->ether_type) == ETHERTYPE_IP) {
        ip_header = (struct ip *)(packet + SIZE_ETHERNET);

        // Convert IPs to readable format
        inet_ntop(AF_INET, &(ip_header->ip_src), src_ip, INET_ADDRSTRLEN);
        inet_ntop(AF_INET, &(ip_header->ip_dst), dst_ip, INET_ADDRSTRLEN);

        // Print captured packet information
        printf("Captured Packet: \n");
        printf("Source MAC: %s\n", ether_ntoa((struct ether_addr *)eth_header->ether_shost));
        printf("Destination MAC: %s\n", ether_ntoa((struct ether_addr *)eth_header->ether_dhost));
        printf("Source IP: %s\n", src_ip);
        printf("Destination IP: %s\n", dst_ip);
        printf("-----------------------------------\n");
    }
}

int main(int argc, char *argv[]) {
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Check command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Find available devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Find specified device
    for (device = alldevs; device != NULL; device = device->next) {
        if (strcmp(device->name, argv[1]) == 0) break;
    }

    if (device == NULL) {
        fprintf(stderr, "No such device: %s\n", argv[1]);
        pcap_freealldevs(alldevs);
        return EXIT_FAILURE;
    }

    // Open device for live capturing
    handle = pcap_open_live(device->name, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device->name, errbuf);
        pcap_freealldevs(alldevs);
        return EXIT_FAILURE;
    }

    printf("Starting packet capture on %s...\n", device->name);

    // Start capturing packets
    pcap_loop(handle, 0, packet_handler, NULL);

    // Cleanup
    pcap_freealldevs(alldevs);
    pcap_close(handle);
    return EXIT_SUCCESS;
}