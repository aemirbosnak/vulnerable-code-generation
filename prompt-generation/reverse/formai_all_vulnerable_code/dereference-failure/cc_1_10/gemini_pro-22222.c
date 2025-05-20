//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <pcap/pcap.h>

int main() {
    // Open a live capture device
    char *dev = pcap_lookupdev(NULL);
    if (dev == NULL) {
        fprintf(stderr, "No suitable capture device found\n");
        return EXIT_FAILURE;
    }
    pcap_t *handle = pcap_open_live(dev, BUFSIZ, 1, 1000, NULL);
    if (handle == NULL) {
        fprintf(stderr, "Error opening capture device %s\n", dev);
        return EXIT_FAILURE;
    }

    // Loop forever, capturing packets
    while (1) {
        // Wait for a packet to arrive
        struct pcap_pkthdr *header;
        const u_char *data;
        int res = pcap_next_ex(handle, &header, &data);
        if (res < 0) {
            fprintf(stderr, "Error reading packet\n");
            continue;
        }
        if (res == 0) {
            continue;
        }

        // Print the packet header
        printf("Packet length: %d\n", header->len);
        printf("Capture time: %s\n", ctime((const time_t *)&header->ts.tv_sec));

        // Print the packet data in hex
        int i;
        for (i = 0; i < header->len; i++) {
            printf("%02x ", data[i]);
            if ((i + 1) % 16 == 0) {
                printf("\n");
            }
        }
        printf("\n\n");
    }

    // Close the capture device
    pcap_close(handle);
    return EXIT_SUCCESS;
}