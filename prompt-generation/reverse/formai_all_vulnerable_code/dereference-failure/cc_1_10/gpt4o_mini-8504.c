//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ip *ip_header = (struct ip *)(packet + 14); // Skip Ethernet header
    struct tcphdr *tcp_header;
    struct udphdr *udp_header;

    printf("\n\nPacket captured: %d bytes\n", header->len);
    printf("Source IP: %s\n", inet_ntoa(ip_header->ip_src));
    printf("Destination IP: %s\n", inet_ntoa(ip_header->ip_dst));
    printf("Protocol: %d\n", ip_header->ip_p);

    // Check the protocol type
    switch(ip_header->ip_p) {
        case IPPROTO_TCP:
            tcp_header = (struct tcphdr *)(packet + 14 + (ip_header->ip_hl * 4));
            printf("TCP Packet:\n");
            printf("Source Port: %d\n", ntohs(tcp_header->th_sport));
            printf("Destination Port: %d\n", ntohs(tcp_header->th_dport));
            break;
        case IPPROTO_UDP:
            udp_header = (struct udphdr *)(packet + 14 + (ip_header->ip_hl * 4));
            printf("UDP Packet:\n");
            printf("Source Port: %d\n", ntohs(udp_header->uh_sport));
            printf("Destination Port: %d\n", ntohs(udp_header->uh_dport));
            break;
        default:
            printf("Unknown Protocol: %d\n", ip_header->ip_p);
            break;
    }
}

int main(int argc, char *argv[]) {
    pcap_if_t *alldevs;
    pcap_if_t *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Check device list and initialize pcap
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Find the specified device
    for (device = alldevs; device != NULL; device = device->next) {
        if (strcmp(device->name, argv[1]) == 0) {
            break;
        }
    }

    if (device == NULL) {
        fprintf(stderr, "No such device found: %s\n", argv[1]);
        pcap_freealldevs(alldevs);
        return EXIT_FAILURE;
    }

    // Open the device for packet capture
    handle = pcap_open_live(device->name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device->name, errbuf);
        pcap_freealldevs(alldevs);
        return EXIT_FAILURE;
    }

    printf("Listening on %s...\n", device->name);

    // Capture packets
    pcap_loop(handle, 0, packet_handler, NULL);

    // Cleanup
    pcap_freealldevs(alldevs);
    pcap_close(handle);
    return EXIT_SUCCESS;
}