//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: calm
#include <stdio.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <netinet/ether.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ether_header *eth_header;
    struct ip *ip_header;
    
    eth_header = (struct ether_header *)packet;
    
    // Check if the packet is an IP packet
    if (ntohs(eth_header->ether_type) == ETHERTYPE_IP) {
        ip_header = (struct ip *)(packet + sizeof(struct ether_header));
        
        // Print source and destination IP addresses
        char source_ip[INET_ADDRSTRLEN];
        char dest_ip[INET_ADDRSTRLEN];
        
        inet_ntop(AF_INET, &(ip_header->ip_src), source_ip, INET_ADDRSTRLEN);
        inet_ntop(AF_INET, &(ip_header->ip_dst), dest_ip, INET_ADDRSTRLEN);
        
        printf("Captured a packet:\n");
        printf("Source IP: %s\n", source_ip);
        printf("Destination IP: %s\n", dest_ip);
        printf("Packet length: %d bytes\n", header->len);
        printf("---------------------------\n");
    }
}

void list_devices() {
    pcap_if_t *alldevs, *device;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Retrieve the device list
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return;
    }
    
    // Print available devices
    printf("Available network devices:\n");
    for (device = alldevs; device != NULL; device = device->next) {
        printf("%s\n", device->name);
    }

    pcap_freealldevs(alldevs);
}

int main(int argc, char *argv[]) {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        list_devices();
        return 1;
    }

    // Open the specified interface for packet capturing
    handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", argv[1], errbuf);
        return 2;
    }

    printf("Listening on %s...\n", argv[1]);
    
    // Start the packet capture loop
    pcap_loop(handle, 0, packet_handler, NULL);
    
    // Close the capture
    pcap_close(handle);
    return 0;
}