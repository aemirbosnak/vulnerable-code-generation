//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: satisfied
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <time.h>

// Function to print packet details
void print_packet_info(const struct pcap_pkthdr *header, const u_char *packet) {
    struct ip *ip_header = (struct ip*)(packet + 14); // Skip Ethernet header
    printf("Packet Capture Length: %d\n", header->caplen);
    printf("Packet Total Length: %d\n", header->len);
    printf("Source IP: %s\n", inet_ntoa(ip_header->ip_src));
    printf("Destination IP: %s\n", inet_ntoa(ip_header->ip_dst));

    if (ip_header->ip_p == IPPROTO_TCP) {
        printf("Protocol: TCP\n");
    } else if (ip_header->ip_p == IPPROTO_UDP) {
        printf("Protocol: UDP\n");
    } else {
        printf("Protocol: Other\n");
    }
    printf("Timestamp: %s", ctime((const time_t*)&header->ts.tv_sec));
    printf("\n");
}

// Packet handler function
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // Print packet information
    print_packet_info(header, packet);
}

int main(int argc, char *argv[]) {
    char *dev; // Device name
    char errbuf[PCAP_ERRBUF_SIZE]; 
    pcap_t *handle;
    int packet_count = 10; // Number of packets to capture

    // Check user arguments
    if (argc > 1) {
        packet_count = atoi(argv[1]);
    }

    // Find the default device
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Error finding device: %s\n", errbuf);
        return 1;
    }
    printf("Using device: %s\n", dev);

    // Open the pcap device
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", dev, errbuf);
        return 1;
    }

    // Start packet capture
    printf("Starting packet capture (max %d packets)...\n", packet_count);
    pcap_loop(handle, packet_count, packet_handler, NULL);

    // Close the handle
    pcap_close(handle);
    printf("Packet capture finished.\n");

    return 0;
}