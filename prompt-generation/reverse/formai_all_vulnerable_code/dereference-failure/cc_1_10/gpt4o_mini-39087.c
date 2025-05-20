//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <string.h>

#define CAPTURE_COUNT 100

void process_packet(const struct pcap_pkthdr *header, const u_char *packet);
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char *argv[]) {
    pcap_if_t *alldevsp, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    int num_packets = CAPTURE_COUNT;

    // Check for the correct number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get a list of all devices
    if (pcap_findalldevs(&alldevsp, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Find the specified device
    for (device = alldevsp; device != NULL; device = device->next) {
        if (strcmp(device->name, argv[1]) == 0) {
            break;
        }
    }

    if (device == NULL) {
        fprintf(stderr, "Device not found: %s\n", argv[1]);
        pcap_freealldevs(alldevsp);
        return EXIT_FAILURE;
    }

    // Open the device for capturing
    handle = pcap_open_live(device->name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device->name, errbuf);
        pcap_freealldevs(alldevsp);
        return EXIT_FAILURE;
    }

    printf("Listening on %s...\n", device->name);

    // Start capturing packets
    pcap_loop(handle, num_packets, packet_handler, NULL);

    // Cleanup
    pcap_freealldevs(alldevsp);
    pcap_close(handle);
    printf("Capture finished. Exiting...\n");

    return EXIT_SUCCESS;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    process_packet(header, packet);
}

void process_packet(const struct pcap_pkthdr *header, const u_char *packet) {
    // Get pointers to the IP header
    struct ip *ip_header = (struct ip *)(packet + 14); // Skip Ethernet header
    int ip_header_length = ip_header->ip_hl * 4; // Length of IP header

    // Basic packet information
    printf("Packet Captured: [%ld] Bytes\n", header->len);
    printf("Source IP: %s\n", inet_ntoa(ip_header->ip_src));
    printf("Destination IP: %s\n", inet_ntoa(ip_header->ip_dst));
    printf("Protocol: %d\n", ip_header->ip_p);
    
    // Check if the captured packet is a UDP packet
    if (ip_header->ip_p == IPPROTO_UDP) {
        struct udphdr *udp_header = (struct udphdr *)(packet + 14 + ip_header_length);
        printf("Source Port: %d\n", ntohs(udp_header->source));
        printf("Destination Port: %d\n", ntohs(udp_header->dest));
    }

    printf("------------\n");
}