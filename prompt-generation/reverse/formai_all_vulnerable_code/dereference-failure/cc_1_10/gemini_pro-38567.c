//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: rigorous
#include <pcap.h>
#include <stdio.h>

#define SNAPLEN 1518
#define PROMISC 1

int main(int argc, char **argv) {
    char *device;
    pcap_t *handle;
    struct pcap_pkthdr *header;
    const unsigned char *packet;
    int i, res;

    // Obtain the name of the device to capture from
    if (argc < 2) {
        printf("Usage: %s <device>\n", argv[0]);
        exit(1);
    }
    device = argv[1];

    // Open the device for capturing
    handle = pcap_open_live(device, SNAPLEN, PROMISC, 1000, NULL);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live(): %s\n", pcap_geterr(handle));
        exit(2);
    }

    // Capture packets in a loop
    while ((res = pcap_next_ex(handle, &header, &packet)) >= 0) {
        if (res == 0) {
            // Timeout reached, no packets received
            continue;
        }

        // Print packet information
        printf("Packet length: %d\n", header->len);
        printf("Number of bytes captured: %d\n", header->caplen);
        printf("Packet data:\n");
        for (i = 0; i < header->caplen; i++) {
            printf("%02X ", packet[i]);
        }
        printf("\n\n");
    }

    // Check for errors
    if (res == -1) {
        fprintf(stderr, "pcap_next_ex(): %s\n", pcap_geterr(handle));
        exit(3);
    }

    // Close the device
    pcap_close(handle);
    return 0;
}