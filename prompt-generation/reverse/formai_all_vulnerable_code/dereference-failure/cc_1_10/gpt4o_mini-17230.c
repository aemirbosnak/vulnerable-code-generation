//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>

#define MAXBYTES2CAPTURE 2048

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ip *ip_header;
    struct tcphdr *tcp_header;
    struct udphdr *udp_header;

    // Print packet length
    printf("Packet Length: %d bytes\n", header->len);

    // Assuming the packet is an IP packet
    ip_header = (struct ip *)(packet + 14); // 14 bytes for Ethernet header

    // Print source and destination IP addresses
    char src_ip[INET_ADDRSTRLEN];
    char dst_ip[INET_ADDRSTRLEN];
    
    inet_ntop(AF_INET, &(ip_header->ip_src), src_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &(ip_header->ip_dst), dst_ip, INET_ADDRSTRLEN);
    
    printf("Source IP: %s\n", src_ip);
    printf("Destination IP: %s\n", dst_ip);
    
    // Check for TCP
    if (ip_header->ip_p == IPPROTO_TCP) {
        tcp_header = (struct tcphdr *)(packet + 14 + (ip_header->ip_hl * 4));
        printf("Protocol: TCP\n");
        printf("Source Port: %d\n", ntohs(tcp_header->source));
        printf("Destination Port: %d\n", ntohs(tcp_header->dest));
    }

    // Check for UDP
    else if (ip_header->ip_p == IPPROTO_UDP) {
        udp_header = (struct udphdr *)(packet + 14 + (ip_header->ip_hl * 4));
        printf("Protocol: UDP\n");
        printf("Source Port: %d\n", ntohs(udp_header->source));
        printf("Destination Port: %d\n", ntohs(udp_header->dest));
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    int packet_count = 10; // Number of packets to capture

    // Find all available devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
        return 1;
    }

    // Print available devices
    printf("Available Network Devices:\n");
    for (device = alldevs; device != NULL; device = device->next) {
        printf("%s\n", device->name);
        if (device->description)
            printf("Description: %s\n", device->description);
        else
            printf("No description available\n");
    }

    // Open the first available device (for simplicity)
    device = alldevs;
    handle = pcap_open_live(device->name, MAXBYTES2CAPTURE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device->name, errbuf);
        return 1;
    }

    // Capture packets
    printf("Capturing packets on %s...\n", device->name);
    pcap_loop(handle, packet_count, packet_handler, NULL);

    // Clean up
    pcap_close(handle);
    pcap_freealldevs(alldevs);
    printf("Finished capturing packets.\n");

    return 0;
}