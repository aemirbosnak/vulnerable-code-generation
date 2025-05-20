//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: decentralized
#include <pcap.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_PACKETS 10
#define SNAPLEN 65535

int main() {
    // Define the device to capture packets from
    char *device = "en0";

    // Open the device for capturing packets
    pcap_t *handle = pcap_open_live(device, SNAPLEN, 1, 1000, NULL);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device %s: %s\n", device, pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Define the filter to capture packets
    struct bpf_program filter;
    if (pcap_compile(handle, &filter, "tcp", 1, 0) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Set the filter on the device
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Capture packets
    int num_packets = 0;
    while (num_packets < MAX_PACKETS) {
        // Get the next packet
        struct pcap_pkthdr *header;
        const u_char *packet;
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == 1) {
            // Process the packet
            printf("Packet %d:\n", num_packets++);

            // Get the source and destination IP addresses
            struct in_addr *src_addr = (struct in_addr *)(packet + 12);
            struct in_addr *dst_addr = (struct in_addr *)(packet + 16);

            // Get the source and destination ports
            u_short *src_port = (u_short *)(packet + 20);
            u_short *dst_port = (u_short *)(packet + 22);

            // Print the packet information
            printf("Source IP: %s\n", inet_ntoa(*src_addr));
            printf("Destination IP: %s\n", inet_ntoa(*dst_addr));
            printf("Source port: %d\n", ntohs(*src_port));
            printf("Destination port: %d\n", ntohs(*dst_port));
            printf("Payload: %s\n", packet + 34);
        } else if (res == -1) {
            fprintf(stderr, "Error capturing packet: %s\n", pcap_geterr(handle));
            return EXIT_FAILURE;
        }
    }

    // Close the device
    pcap_close(handle);

    return EXIT_SUCCESS;
}