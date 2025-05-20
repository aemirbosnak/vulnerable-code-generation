//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <stdbool.h>

#define NUM_PACKETS 100

int main() {
    // Open the network device
    char *device = "eth0";
    pcap_t *handle = pcap_open_live(device, BUFSIZ, 1, 1000, NULL);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device %s\n", device);
        return EXIT_FAILURE;
    }

    // Set the filter
    char *filter = "tcp";
    struct bpf_program fp;
    if (pcap_compile(handle, &fp, filter, 0, 0) == -1) {
        fprintf(stderr, "Error compiling filter %s\n", filter);
        pcap_close(handle);
        return EXIT_FAILURE;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error setting filter %s\n", filter);
        pcap_close(handle);
        return EXIT_FAILURE;
    }

    // Capture the packets
    struct pcap_pkthdr *header;
    const u_char *data;
    int count = 0;
    while (count < NUM_PACKETS) {
        if (pcap_next_ex(handle, &header, &data) == 1) {
            // Process the packet
            printf("Packet %d:\n", count);
            printf("timestamp: %ld.%ld\n", header->ts.tv_sec, header->ts.tv_usec);
            printf("length: %d\n", header->len);
            printf("data:\n");
            for (int i = 0; i < header->len; i++) {
                printf("%02x ", data[i]);
            }
            printf("\n\n");
            count++;
        }
    }

    // Close the device
    pcap_close(handle);

    return EXIT_SUCCESS;
}