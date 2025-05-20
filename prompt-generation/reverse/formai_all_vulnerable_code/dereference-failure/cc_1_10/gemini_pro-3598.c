//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main() {
    char *device;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr header;
    const unsigned char *packet;
    int i;

    // Find a suitable device to capture packets from
    device = pcap_lookupdev(errbuf);
    if (device == NULL) {
        fprintf(stderr, "Error finding a capture device: %s\n", errbuf);
        return -1;
    }

    // Open the device for capturing packets
    handle = pcap_open_live(device, 65535, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening the capture device: %s\n", errbuf);
        return -1;
    }

    // Capture packets until the user presses Enter
    while (1) {
        // Wait for a packet to arrive
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == -1) {
            fprintf(stderr, "Error capturing a packet: %s\n", pcap_geterr(handle));
            break;
        } else if (res == 0) {
            // Timeout elapsed without any packets being captured
            continue;
        }

        // Print the packet header
        printf("Packet length: %d\n", header.len);
        printf("Capture time: %s\n", ctime((const time_t *) &header.ts.tv_sec));

        // Print the packet data
        for (i = 0; i < header.len; i++) {
            printf("%02x ", packet[i]);
            if (i % 16 == 15) {
                printf("\n");
            }
        }

        printf("\n\n");
    }

    // Close the capture device
    pcap_close(handle);

    return 0;
}