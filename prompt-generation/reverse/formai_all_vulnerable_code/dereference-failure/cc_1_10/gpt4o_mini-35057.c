//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define SIZE_ETHERNET 14

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ip *ip_header;
    struct tcphdr *tcp_header;

    const char *src_ip;
    const char *dst_ip;

    // Get the IP header from the packet
    ip_header = (struct ip *)(packet + SIZE_ETHERNET);
    src_ip = inet_ntoa(ip_header->ip_src);
    dst_ip = inet_ntoa(ip_header->ip_dst);

    // Print packet details
    printf("Packet captured:\n");
    printf("  Source IP: %s\n", src_ip);
    printf("  Destination IP: %s\n", dst_ip);
    printf("  Packet length: %d\n", header->len);
}

int main(int argc, char *argv[]) {
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Check user input for device name
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <network_device>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Find all available devices
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
        fprintf(stderr, "Device not found: %s\n", argv[1]);
        pcap_freealldevs(alldevs);
        return EXIT_FAILURE;
    }

    // Open the device for packet capture
    handle = pcap_open_live(device->name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device %s: %s\n", device->name, errbuf);
        pcap_freealldevs(alldevs);
        return EXIT_FAILURE;
    }

    pcap_freealldevs(alldevs);

    printf("Starting packet capture on %s...\n", device->name);

    // Capture packets in a loop
    pcap_loop(handle, 0, packet_handler, NULL);

    // Cleanup and exit
    pcap_close(handle);
    return EXIT_SUCCESS;
}