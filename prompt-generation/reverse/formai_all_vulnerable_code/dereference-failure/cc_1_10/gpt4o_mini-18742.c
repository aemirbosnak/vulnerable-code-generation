//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>

#define MAXBYTES2CAPTURE 2048 

// Function to handle received packets
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    const struct ip *iph = (struct ip *)(packet + 14); // Skip Ethernet header
    char src_ip[INET_ADDRSTRLEN];
    char dst_ip[INET_ADDRSTRLEN];

    // Convert IP addresses from binary to text
    inet_ntop(AF_INET, &(iph->ip_src), src_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &(iph->ip_dst), dst_ip, INET_ADDRSTRLEN);

    // Print packet information
    printf("Packet captured:\n");
    printf("Source IP: %s\n", src_ip);
    printf("Destination IP: %s\n", dst_ip);
    printf("Packet length: %u bytes\n\n", header->len);
}

// Main function to setup packet capture
int main(int argc, char *argv[]) {
    pcap_if_t *alldevs;
    pcap_if_t *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct pcap_pkthdr header;
    const u_char *packet;
    
    // Get the list of devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
        return 1;
    }

    // Display available devices
    printf("Available Devices:\n");
    for (device = alldevs; device != NULL; device = device->next) {
        printf("%s\n", device->name);
    }

    // Use the first device for capturing
    device = alldevs;
    if (device == NULL) {
        fprintf(stderr, "No devices found.\n");
        return 1;
    }

    // Open the device for capturing
    handle = pcap_open_live(device->name, MAXBYTES2CAPTURE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device %s: %s\n", device->name, errbuf);
        return 1;
    }

    // Start capturing packets
    printf("Listening on %s...\n", device->name);
    pcap_loop(handle, 0, packet_handler, NULL);

    // Cleanup
    pcap_freealldevs(alldevs);
    pcap_close(handle);
    return 0;
}