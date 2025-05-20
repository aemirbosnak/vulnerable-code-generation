//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <pcap/pcap.h>

int main() {
    // Open the network device
    char *device = "enp0s3";
    pcap_t *handle = pcap_open_live(device, BUFSIZ, 1, 1000, NULL);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device, pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Set the filter
    struct bpf_program fp;
    char *filter = "tcp and port 80";
    if (pcap_compile(handle, &fp, filter, 0, 0) == -1) {
        fprintf(stderr, "Could not compile filter %s: %s\n", filter, pcap_geterr(handle));
        return EXIT_FAILURE;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Could not set filter %s: %s\n", filter, pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Capture packets
    int count = 0;
    struct pcap_pkthdr *header;
    const unsigned char *data;
    while (1) {
        int res = pcap_next_ex(handle, &header, &data);
        if (res == -1) {
            fprintf(stderr, "Could not capture packet: %s\n", pcap_geterr(handle));
            return EXIT_FAILURE;
        } else if (res == 0) {
            continue;
        }

        // Process the packet
        printf("Packet %d: %d bytes\n", count, header->len);
        for (int i = 0; i < header->len; i++) {
            printf("%02x ", data[i]);
        }
        printf("\n\n");

        count++;
    }

    // Close the network device
    pcap_close(handle);

    return EXIT_SUCCESS;
}