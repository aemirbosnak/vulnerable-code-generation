//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pcap.h>

#define PCAP_ERRBUF_SIZE 256

int main(int argc, char **argv) {
    char *device = NULL;
    char *filter = NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = NULL;
    struct pcap_pkthdr *header;
    const u_char *packet;

    // Check for command line arguments.
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <device> <filter>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the device and filter.
    device = argv[1];
    filter = argv[2];

    // Open the device.
    handle = pcap_open_live(device, 65535, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Compile the filter.
    struct bpf_program fp;
    if (pcap_compile(handle, &fp, filter, 1, 0) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Set the filter.
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Capture packets.
    while (1) {
        int ret = pcap_next_ex(handle, &header, &packet);
        if (ret == 1) {
            // We got a packet.
            // Parse the packet.
            uint32_t timestamp = header->ts.tv_sec;
            uint32_t microseconds = header->ts.tv_usec;
            uint16_t length = header->len;
            uint8_t rssi = packet[48];

            // Print the packet information.
            printf("%u.%06u: %u bytes; RSSI: %d\n", timestamp, microseconds, length, rssi);
        } else if (ret == 0) {
            // Timeout.
            continue;
        } else {
            // Error.
            fprintf(stderr, "Error capturing packet: %s\n", pcap_geterr(handle));
            return EXIT_FAILURE;
        }
    }

    // Close the device.
    pcap_close(handle);

    return EXIT_SUCCESS;
}