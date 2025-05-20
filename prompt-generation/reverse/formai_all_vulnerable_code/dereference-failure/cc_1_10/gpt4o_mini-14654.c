//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netinet/ether.h>
#include <string.h>

// Function to print the packet details
void print_packet(const struct pcap_pkthdr *header, const u_char *packet) {
    struct ether_header *eth_header = (struct ether_header *)packet;
    struct ip *ip_header = (struct ip *)(packet + sizeof(struct ether_header));
    struct tcphdr *tcp_header = (struct tcphdr *)(packet + sizeof(struct ether_header) + sizeof(struct ip));
    struct udphdr *udp_header = (struct udphdr *)(packet + sizeof(struct ether_header) + sizeof(struct ip));

    // Display Ethernet Information
    printf("\nCaptured Packet:\n");
    printf("Packet Length: %d bytes\n", header->len);
    printf("Capture Length: %d bytes\n", header->caplen);
    
    printf("Source MAC: %s\n", ether_ntoa((struct ether_addr *)eth_header->ether_shost));
    printf("Destination MAC: %s\n", ether_ntoa((struct ether_addr *)eth_header->ether_dhost));

    // Check if the packet is IP
    if (ntohs(eth_header->ether_type) == ETHERTYPE_IP) {
        printf("Protocol: IP\n");
        printf("Source IP: %s\n", inet_ntoa(ip_header->ip_src));
        printf("Destination IP: %s\n", inet_ntoa(ip_header->ip_dst));

        // Check if the packet is TCP
        if (ip_header->ip_p == IPPROTO_TCP) {
            printf("Protocol: TCP\n");
            printf("Source Port: %d\n", ntohs(tcp_header->source));
            printf("Destination Port: %d\n", ntohs(tcp_header->dest));

        // Check if the packet is UDP
        } else if (ip_header->ip_p == IPPROTO_UDP) {
            printf("Protocol: UDP\n");
            printf("Source Port: %d\n", ntohs(udp_header->source));
            printf("Destination Port: %d\n", ntohs(udp_header->dest));
        } else {
            printf("Other Protocol: %d\n", ip_header->ip_p);
        }
    } else {
        printf("Non-IP Packet\n");
    }
}

int main(int argc, char *argv[]) {
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    const u_char *packet;
    struct pcap_pkthdr header;

    // Check for proper usage
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Find all available devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // Loop through the devices to find the one specified
    for (device = alldevs; device != NULL; device = device->next) {
        if (strcmp(device->name, argv[1]) == 0) {
            break;
        }
    }

    // Check if the device was found
    if (device == NULL) {
        fprintf(stderr, "Device %s not found.\n", argv[1]);
        pcap_freealldevs(alldevs);
        exit(EXIT_FAILURE);
    }

    // Open the device for capture
    handle = pcap_open_live(device->name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device->name, errbuf);
        pcap_freealldevs(alldevs);
        exit(EXIT_FAILURE);
    }

    // Capture packets in a loop
    printf("Starting packet capture on %s...\n", device->name);
    while (1) {
        packet = pcap_next(handle, &header);
        if (packet == NULL) {
            fprintf(stderr, "Error capturing packets\n");
            continue;
        }

        // Print the packet details
        print_packet(&header, packet);
    }

    // Cleanup
    pcap_freealldevs(alldevs);
    pcap_close(handle);
    return 0;
}