//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <string.h>

#define SNAP_LEN 1518 // Max bytes to capture for each packet
#define PROMISCUOUS 1 // Enable promiscuous mode
#define TIMEOUT 1000  // Timeout in milliseconds

// Function to process each captured packet
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    const struct ip *ip_header;       // Pointer to the IP header
    const struct tcphdr *tcp_header;  // Pointer to the TCP header
    
    // Points to the IP header in the packet
    ip_header = (struct ip *)(packet + 14); // Skip Ethernet header (14 bytes)
    
    // Print source and destination IP addresses
    char src_ip[INET_ADDRSTRLEN];
    char dst_ip[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &(ip_header->ip_src), src_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &(ip_header->ip_dst), dst_ip, INET_ADDRSTRLEN);
    
    printf("Captured packet: %s -> %s\n", src_ip, dst_ip);
    
    // If the packet contains a TCP header
    if (ip_header->ip_p == IPPROTO_TCP) {
        tcp_header = (struct tcphdr *)(packet + 14 + ip_header->ip_hl * 4); // IP header length to TCP header
        
        printf("Source Port: %u, Destination Port: %u\n", ntohs(tcp_header->source), ntohs(tcp_header->dest));
    }

    printf("Packet length: %d bytes\n\n", header->len);
}

int main(int argc, char *argv[]) {
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Get a list of all available devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return 1;
    }
    
    // Print the list of devices
    printf("Available devices:\n");
    for (device = alldevs; device != NULL; device = device->next) {
        printf("%s\n", device->name);
    }
    
    // Prompt user to select a device
    char selected_device[100];
    printf("Enter the device name to capture from: ");
    scanf("%s", selected_device);
    
    // Open the specified device for packet capture
    handle = pcap_open_live(selected_device, SNAP_LEN, PROMISCUOUS, TIMEOUT, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", selected_device, errbuf);
        pcap_freealldevs(alldevs);
        return 2;
    }

    // Capture packets indefinitely, calling packet_handler for each packet
    printf("Capturing packets on %s...\n", selected_device);
    pcap_loop(handle, 0, packet_handler, NULL);
    
    // Clean up
    pcap_close(handle);
    pcap_freealldevs(alldevs);
    
    return 0;
}