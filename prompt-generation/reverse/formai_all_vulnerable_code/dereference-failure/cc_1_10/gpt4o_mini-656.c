//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <netinet/ip_icmp.h>
#include <string.h>

#define MAX_PACKETS 100

// Function to print the IP address in human-readable form
void print_ip(const u_char *ip_addr) {
    struct in_addr ip;
    memcpy(&ip, ip_addr, sizeof(ip));
    printf("%s", inet_ntoa(ip));
}

// Callback function for packet capture
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ip *ip_header = (struct ip *)(packet + 14); // Skip Ethernet header
    int ip_header_length = ip_header->ip_hl * 4; // IP header length in bytes

    printf("Packet captured:\n");
    printf("Source IP: ");
    print_ip(&ip_header->ip_src);
    printf("\nDestination IP: ");
    print_ip(&ip_header->ip_dst);
    printf("\nProtocol: ");

    switch (ip_header->ip_p) {
        case IPPROTO_TCP:
            printf("TCP\n");
            break;
        case IPPROTO_UDP:
            printf("UDP\n");
            break;
        case IPPROTO_ICMP:
            printf("ICMP\n");
            break;
        default:
            printf("Other Protocol\n");
            break;
    }
    printf("Packet Length: %d bytes\n", header->len);
    printf("---------------------------------------------------\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *dev = argv[1];
    char errbuf[PCAP_ERRBUF_SIZE];
    
    pcap_if_t *all_devs;
    pcap_if_t *device;

    if (pcap_findalldevs(&all_devs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // Find the specified device
    for (device = all_devs; device; device = device->next) {
        if (strcmp(device->name, dev) == 0) {
            break;
        }
    }

    if (!device) {
        fprintf(stderr, "Device %s not found.\n", dev);
        pcap_freealldevs(all_devs);
        exit(EXIT_FAILURE);
    }

    pcap_freealldevs(all_devs);

    pcap_t *handle = pcap_open_live(device->name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device %s: %s\n", device->name, errbuf);
        exit(EXIT_FAILURE);
    }

    printf("Capturing packets on interface %s...\n", device->name);
    printf("Press Ctrl+C to stop capturing.\n");

    // Start capturing packets
    pcap_loop(handle, MAX_PACKETS, packet_handler, NULL);

    pcap_close(handle);
    printf("Capture complete. Exiting...\n");

    return 0;
}