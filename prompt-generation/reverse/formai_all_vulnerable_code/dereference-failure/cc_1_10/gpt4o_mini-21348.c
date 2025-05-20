//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <string.h>

#define CAPTURE_COUNT 100

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ip *ip_header;
    struct udphdr *udp_header;
    struct tcphdr *tcp_header;

    // Get the IP header
    ip_header = (struct ip *)(packet + 14);  // 14 byte Ethernet header

    // Print source and destination IP addresses
    char src_ip[INET_ADDRSTRLEN];
    char dst_ip[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &(ip_header->ip_src), src_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &(ip_header->ip_dst), dst_ip, INET_ADDRSTRLEN);

    printf("Source IP: %s ", src_ip);
    printf("Destination IP: %s ", dst_ip);

    // Determine the protocol
    switch (ip_header->ip_p) {
        case IPPROTO_TCP:
            tcp_header = (struct tcphdr *)(packet + 14 + (ip_header->ip_hl * 4));
            printf("Protocol: TCP ");
            printf("Source Port: %d ", ntohs(tcp_header->source));
            printf("Destination Port: %d\n", ntohs(tcp_header->dest));
            break;
        case IPPROTO_UDP:
            udp_header = (struct udphdr *)(packet + 14 + (ip_header->ip_hl * 4));
            printf("Protocol: UDP ");
            printf("Source Port: %d ", ntohs(udp_header->uh_sport));
            printf("Destination Port: %d\n", ntohs(udp_header->uh_dport));
            break;
        default:
            printf("Protocol: Other\n");
            break;
    }
}

int main(int argc, char *argv[]) {
    char *dev;                // Device to sniff on
    char errbuf[PCAP_ERRBUF_SIZE]; // Error buffer
    pcap_if_t *alldevsp, *device;

    // Find all available devices
    if (pcap_findalldevs(&alldevsp, errbuf) == -1) {
        fprintf(stderr, "Cannot find devices: %s\n", errbuf);
        return 1;
    }

    // Choose the first device
    dev = alldevsp->name;   
    printf("Using device: %s\n", dev);

    // Open the device for capturing
    pcap_t *handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", dev, errbuf);
        return 2;
    }

    // Start packet capture
    printf("Capturing packets... Press Ctrl+C to stop!\n");
    pcap_loop(handle, CAPTURE_COUNT, packet_handler, NULL);

    // Close the handle
    pcap_close(handle);
    pcap_freealldevs(alldevsp);
    return 0;
}