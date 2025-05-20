//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <string.h>

#define SNAP_LEN 1518   // Max bytes to capture per packet

// Callback function to be called when packets are captured
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ip *ip_header;
    struct tcphdr *tcp_header;
    struct udphdr *udp_header;
    int ip_header_len;

    // Pointer to start of IP header
    ip_header = (struct ip*)(packet + 14); // Skip Ethernet header (14 bytes)

    // Source and destination IP
    char src_ip[INET_ADDRSTRLEN];
    char dst_ip[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &(ip_header->ip_src), src_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &(ip_header->ip_dst), dst_ip, INET_ADDRSTRLEN);

    // Packet details
    printf("Captured a packet:\n");
    printf("Source IP: %s\n", src_ip);
    printf("Destination IP: %s\n", dst_ip);
    printf("Protocol: %d\n", ip_header->ip_p);

    // Check for TCP or UDP Protocol
    if (ip_header->ip_p == IPPROTO_TCP) {
        tcp_header = (struct tcphdr*)(packet + 14 + (ip_header->ip_hl * 4));
        printf("TCP Packet:\n");
        printf("Source Port: %d\n", ntohs(tcp_header->source));
        printf("Destination Port: %d\n", ntohs(tcp_header->dest));
    } else if (ip_header->ip_p == IPPROTO_UDP) {
        udp_header = (struct udphdr*)(packet + 14 + (ip_header->ip_hl * 4));
        printf("UDP Packet:\n");
        printf("Source Port: %d\n", ntohs(udp_header->source));
        printf("Destination Port: %d\n", ntohs(udp_header->dest));
    }

    printf("=====================\n");
}

int main(int argc, char *argv[]) {
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <network interface>\n", argv[0]);
        return 1;
    }

    // Find all devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return 1;
    }

    // Open the specified device
    device = alldevs;
    while (device != NULL) {
        if (strcmp(device->name, argv[1]) == 0) break;
        device = device->next;
    }

    if (device == NULL) {
        fprintf(stderr, "Device %s not found.\n", argv[1]);
        pcap_freealldevs(alldevs);
        return 1;
    }

    handle = pcap_open_live(device->name, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device->name, errbuf);
        pcap_freealldevs(alldevs);
        return 1;
    }

    printf("Listening on %s...\n", device->name);

    // Start capturing packets
    pcap_loop(handle, 0, packet_handler, NULL);

    // Clean up
    pcap_freealldevs(alldevs);
    pcap_close(handle);
    return 0;
}