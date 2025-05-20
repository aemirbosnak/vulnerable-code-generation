//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: safe
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <stdbool.h>

void print_packet_info(const u_char *packet, size_t packet_len) {
    struct pcap_pkthdr *header = (struct pcap_pkthdr *)packet;

    printf("Packet length: %d\n", header->len);
    printf("Packet timestamp: %s\n", ctime((const time_t *)&header->ts.tv_sec));

    size_t i;
    printf("Packet data: ");
    for (i = 0; i < packet_len; i++) {
        printf("%02x ", packet[i]);
    }
    printf("\n\n");
}

int main() {
    char *device = NULL;  // Use the default device
    char *filter = NULL;  // No filter
    bpf_u_int32 netmask;  // Don't care about the netmask
    int snaplen = 65535;  // Capture the entire packet
    int promiscuous = 1;  // Set promiscuous mode
    int timeout = 1000;  // Wait for 1 second between packets

    // Initialize the error buffer
    char errbuf[PCAP_ERRBUF_SIZE];

    // Open the device
    pcap_t *handle = pcap_open_live(device, snaplen, promiscuous, timeout, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening the device: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Compile the filter
    struct bpf_program fp;
    if (pcap_compile(handle, &fp, filter, 0, netmask) == -1) {
        fprintf(stderr, "Error compiling the filter: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        return EXIT_FAILURE;
    }

    // Set the filter
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error setting the filter: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        return EXIT_FAILURE;
    }

    // Capture packets
    int count = 0;
    while (true) {
        // Wait for a packet to arrive
        struct pcap_pkthdr *header;
        const u_char *packet;
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == -1) {
            fprintf(stderr, "Error reading the packet: %s\n", pcap_geterr(handle));
            break;
        } else if (res == 0) {
            continue;  // No packet was received
        }

        // Print the packet information
        print_packet_info(packet, header->len);

        count++;
    }

    // Close the device
    pcap_close(handle);

    return EXIT_SUCCESS;
}