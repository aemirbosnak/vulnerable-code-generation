//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Dennis Ritchie
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *device = argv[1];
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Open the network device for capturing
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device, errbuf);
        exit(EXIT_FAILURE);
    }

    // Create a packet filter
    struct bpf_program fp;
    if (pcap_compile(handle, &fp, "tcp", 1, 0) == -1) {
        fprintf(stderr, "Could not compile filter\n");
        exit(EXIT_FAILURE);
    }

    // Set the filter
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Could not set filter\n");
        exit(EXIT_FAILURE);
    }

    // Capture packets
    while (1) {
        struct pcap_pkthdr *header;
        const unsigned char *packet;

        // Get the next packet
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == -1) {
            fprintf(stderr, "Error capturing packet\n");
            exit(EXIT_FAILURE);
        }

        // Ignore packets that are too small
        if (header->caplen < 14) {
            continue;
        }

        // Get the source and destination IP addresses
        uint32_t src_ip = *(uint32_t *)(packet + 12);
        uint32_t dst_ip = *(uint32_t *)(packet + 16);

        // Get the source and destination ports
        uint16_t src_port = *(uint16_t *)(packet + 20);
        uint16_t dst_port = *(uint16_t *)(packet + 22);

        // Print the packet information
        printf("Received packet from %s:%d to %s:%d\n",
               inet_ntoa(*(struct in_addr *)&src_ip), src_port,
               inet_ntoa(*(struct in_addr *)&dst_ip), dst_port);

        // Print the packet data
        for (int i = 0; i < header->caplen; i++) {
            printf("%02x ", packet[i]);
        }
        printf("\n");
    }

    // Close the device
    pcap_close(handle);

    exit(EXIT_SUCCESS);
}