//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

#define MAX_BYTES_PER_PACKET 2048

int main(int argc, char *argv[]) {
    char *device;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr *header;
    const u_char *data;
    int i;

    // Get the device to capture packets from
    if (argc == 2) {
        device = argv[1];
    } else {
        device = pcap_lookupdev(errbuf);
        if (device == NULL) {
            fprintf(stderr, "Error finding device: %s\n", errbuf);
            return EXIT_FAILURE;
        }
    }

    // Open the device for capturing packets
    handle = pcap_open_live(device, MAX_BYTES_PER_PACKET, 0, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Capture packets until the user presses enter
    printf("Press enter to stop capturing packets.\n");
    while (getchar() != '\n') {
        // Get the next packet
        header = pcap_next(handle, &data);

        // Print the packet header
        printf("Packet length: %d\n", header->len);
        printf("Packet capture time: %s\n", ctime((const time_t *)&header->ts.tv_sec));

        // Print the packet data
        for (i = 0; i < header->len; i++) {
            printf("%02X ", data[i]);
        }
        printf("\n\n");
    }

    // Close the device
    pcap_close(handle);

    return EXIT_SUCCESS;
}