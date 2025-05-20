//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <netinet/ether.h>
#include <arpa/inet.h>
#include <string.h>

// Callback function that is called when a packet is captured
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ether_header *eth_header;
    struct ip *ip_header;

    eth_header = (struct ether_header *) packet;
    
    // Check for IP packets (IPv4)
    if (ntohs(eth_header->ether_type) == ETHERTYPE_IP) {
        ip_header = (struct ip *) (packet + sizeof(struct ether_header));
        
        char src_ip[INET_ADDRSTRLEN];
        char dest_ip[INET_ADDRSTRLEN];

        // Convert IP addresses from binary to string
        inet_ntop(AF_INET, &(ip_header->ip_src), src_ip, INET_ADDRSTRLEN);
        inet_ntop(AF_INET, &(ip_header->ip_dst), dest_ip, INET_ADDRSTRLEN);

        printf("Captured a packet:\n");
        printf("Source IP: %s\n", src_ip);
        printf("Destination IP: %s\n", dest_ip);
        printf("Protocol: %d\n", ip_header->ip_p);
        printf("-----------------------------------\n");
    }
}

int main(int argc, char *argv[]) {
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    
    // Check for proper argument usage
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    // Find all available devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return 1;
    }

    // Find the specified interface
    device = alldevs;
    while (device) {
        if (strcmp(device->name, argv[1]) == 0) {
            break;
        }
        device = device->next;
    }

    if (device == NULL) {
        fprintf(stderr, "Device not found: %s\n", argv[1]);
        pcap_freealldevs(alldevs);
        return 1;
    }

    // Open the device for packet capture
    handle = pcap_open_live(device->name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        pcap_freealldevs(alldevs);
        return 1;
    }

    // Print the capturing details
    printf("Listening on device: %s\n", device->name);
    
    // Start the packet capture loop
    pcap_loop(handle, 0, packet_handler, NULL);
    
    // Cleanup
    pcap_freealldevs(alldevs);
    pcap_close(handle);
    
    return 0;
}