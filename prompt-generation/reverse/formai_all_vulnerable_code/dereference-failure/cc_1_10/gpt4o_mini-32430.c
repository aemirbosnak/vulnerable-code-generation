//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

// Number of packets to capture
#define PACKET_COUNT 10

// Global variable to store packet count
unsigned int packet_count = 0;

// Function to process captured packets
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // Get the IP header from the packet
    struct ip *ip_header = (struct ip *)(packet + 14); // Skip Ethernet header

    // Print source and destination IP addresses
    char src_ip[INET_ADDRSTRLEN];
    char dest_ip[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &(ip_header->ip_src), src_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &(ip_header->ip_dst), dest_ip, INET_ADDRSTRLEN);

    printf("Packet %d: %s -> %s\n", ++packet_count, src_ip, dest_ip);

    // Stop capturing after certain packets are collected
    if (packet_count >= PACKET_COUNT) {
        pcap_breakloop((pcap_t *)args);
    }
}

// Main function
int main(int argc, char *argv[]) {
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    int device_index;

    // Check command line arguments
    if (argc != 2) {
        printf("Usage: %s <device_number>\n", argv[0]);
        return EXIT_FAILURE;
    }

    device_index = atoi(argv[1]);

    // Get the list of available devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Find the specified device
    device = alldevs;
    for (int i = 0; i < device_index && device != NULL; i++) {
        device = device->next;
    }

    // Error handling for device selection
    if (device == NULL) {
        fprintf(stderr, "Error: device number %d is not valid.\n", device_index);
        pcap_freealldevs(alldevs);
        return EXIT_FAILURE;
    }

    // Open the selected device for packet capture
    handle = pcap_open_live(device->name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device->name, errbuf);
        pcap_freealldevs(alldevs);
        return EXIT_FAILURE;
    }

    printf("Using device: %s\n", device->description);

    // Set the callback function for packet processing
    pcap_loop(handle, 0, packet_handler, (u_char *)handle);

    // Close the pcap handle and free device list
    pcap_close(handle);
    pcap_freealldevs(alldevs);

    printf("Captured %d packets.\n", packet_count);
    return EXIT_SUCCESS;
}