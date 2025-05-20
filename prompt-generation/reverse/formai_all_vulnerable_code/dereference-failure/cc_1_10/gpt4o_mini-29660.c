//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: dynamic
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define SNAP_LEN 65535  // Capture all packets, regardless of the size

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ip *ip_header;
    struct tcphdr *tcp_header;

    // Calculate the IP header length
    ip_header = (struct ip *)(packet + 14); // Skip the Ethernet header (14 bytes)
    int ip_header_length = ip_header->ip_hl * 4; // ip_hl is in 4-byte words

    // Only process TCP packets
    if (ip_header->ip_p == IPPROTO_TCP) {
        tcp_header = (struct tcphdr *)(packet + 14 + ip_header_length);

        printf("Captured a TCP packet:\n");
        printf("Source IP: %s\n", inet_ntoa(ip_header->ip_src));
        printf("Destination IP: %s\n", inet_ntoa(ip_header->ip_dst));
        printf("Source Port: %u\n", ntohs(tcp_header->th_sport));
        printf("Destination Port: %u\n", ntohs(tcp_header->th_dport));
        printf("Packet Length: %d bytes\n", header->len);
        printf("\n");
    } else {
        printf("Captured a non-TCP packet, ignoring...\n");
    }
}

void usage() {
    printf("Usage: packet_capturer <interface>\n");
    printf("Example: packet_capturer eth0\n");
}

int main(int argc, char *argv[]) {
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    if (argc != 2) {
        usage();
        return EXIT_FAILURE;
    }

    // Get the list of network devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Look for the specified device
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

    // Open the device for packet capturing
    handle = pcap_open_live(device->name, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device %s: %s\n", device->name, errbuf);
        pcap_freealldevs(alldevs);
        return EXIT_FAILURE;
    }

    // Start capturing packets
    printf("Listening on %s...\n", device->name);
    pcap_loop(handle, 0, packet_handler, NULL);

    // Cleanup
    pcap_freealldevs(alldevs);
    pcap_close(handle);
    return EXIT_SUCCESS;
}