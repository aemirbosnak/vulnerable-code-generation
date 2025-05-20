//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main() {
    // Open a network interface for packet sniffing
    char *dev = pcap_lookupdev(NULL);
    if (dev == NULL) {
        perror("pcap_lookupdev");
        return EXIT_FAILURE;
    }

    // Create a packet capture handle
    pcap_t *handle = pcap_open_live(dev, BUFSIZ, 1, 1000, NULL);
    if (handle == NULL) {
        perror("pcap_open_live");
        return EXIT_FAILURE;
    }

    // Set the filter to capture all packets
    struct bpf_program filter;
    if (pcap_compile(handle, &filter, "tcp", 0, 0) != 0) {
        perror("pcap_compile");
        pcap_close(handle);
        return EXIT_FAILURE;
    }

    if (pcap_setfilter(handle, &filter) != 0) {
        perror("pcap_setfilter");
        pcap_close(handle);
        return EXIT_FAILURE;
    }

    // Start the packet capture loop
    while (1) {
        // Wait for a packet to arrive
        struct pcap_pkthdr *header;
        const unsigned char *data;
        int res = pcap_next_ex(handle, &header, &data);

        // If an error occurred, print it and continue
        if (res == -1) {
            perror("pcap_next_ex");
            continue;
        }

        // If a packet was captured, print its details
        if (res == 1) {
            printf("Packet captured!\n");
            printf("Source: %s\n", inet_ntoa(*((struct in_addr *)data)));
            printf("Destination: %s\n", inet_ntoa(*((struct in_addr *)(data + 16))));
            printf("Length: %d bytes\n", header->len);
            printf("Data: %s\n", data + 34);
        }
    }

    // Cleanup
    pcap_close(handle);
    return EXIT_SUCCESS;
}