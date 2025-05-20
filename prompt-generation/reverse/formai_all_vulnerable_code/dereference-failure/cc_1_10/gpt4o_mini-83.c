//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <string.h>

#define SNAP_LEN 65535  // max number of bytes to capture
#define FILTER_EXP "ip" // capture only IP packets
#define PROMISCUOUS_MODE 1
#define TIMEOUT 1000    // timeout in milliseconds

// Function to print packet details
void print_packet_info(const struct pcap_pkthdr *header, const u_char *packet) {
    struct ethhdr *eth = (struct ethhdr *)packet;

    printf("\nPacket capture length: %d\n", header->caplen);
    printf("Packet total length : %d\n", header->len);
    
    printf("Source MAC: %02x:%02x:%02x:%02x:%02x:%02x\n", 
           eth->h_source[0], eth->h_source[1], eth->h_source[2], 
           eth->h_source[3], eth->h_source[4], eth->h_source[5]);

    printf("Destination MAC: %02x:%02x:%02x:%02x:%02x:%02x\n", 
           eth->h_dest[0], eth->h_dest[1], eth->h_dest[2], 
           eth->h_dest[3], eth->h_dest[4], eth->h_dest[5]);

    printf("EtherType: 0x%04x\n", ntohs(eth->h_proto));
    printf("-------------------------------------------------\n");
}

// Packet processing callback function
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    print_packet_info(header, packet);
}

// Set up packet capturing
int main(int argc, char *argv[]) {
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    
    // Get the list of all network devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return 1;
    }

    // Print device list to user
    printf("Available devices:\n");
    for (device = alldevs; device != NULL; device = device->next) {
        printf("%s\n", device->name);
    }

    // If no device was found, exit
    if (alldevs == NULL) {
        fprintf(stderr, "No devices found! Exiting...\n");
        return 1;
    }

    // Open the first available device
    handle = pcap_open_live(alldevs->name, SNAP_LEN, PROMISCUOUS_MODE, TIMEOUT, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Unable to open the device %s: %s\n", alldevs->name, errbuf);
        pcap_freealldevs(alldevs);
        return 1;
    }

    // Compile the filter expression
    struct bpf_program fp;
    if (pcap_compile(handle, &fp, FILTER_EXP, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Failed to compile filter: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        pcap_freealldevs(alldevs);
        return 1;
    }

    // Set the compiled filter
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Failed to set filter: %s\n", pcap_geterr(handle));
        pcap_freecode(&fp);
        pcap_close(handle);
        pcap_freealldevs(alldevs);
        return 1;
    }

    pcap_freecode(&fp);

    // Start packet capture
    printf("Starting packet capture. Press Ctrl+C to stop...\n");
    pcap_loop(handle, 0, packet_handler, NULL);

    // Clean up and close the pcap handle and free device list
    pcap_close(handle);
    pcap_freealldevs(alldevs);
    return 0;
}