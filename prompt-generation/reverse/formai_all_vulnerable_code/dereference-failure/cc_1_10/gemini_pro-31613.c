//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/in.h>

int main() {
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr *header;
    const u_char *packet;
    int res;

    // Get the device.
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "pcap_lookupdev(): %s\n", errbuf);
        return 1;
    }

    // Open the device.
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live(): %s\n", errbuf);
        return 1;
    }

    // Loop forever, capturing packets.
    while (1) {
        // Wait for a packet.
        res = pcap_next_ex(handle, &header, &packet);
        if (res < 0) {
            fprintf(stderr, "pcap_next_ex(): %s\n", pcap_geterr(handle));
            return 1;
        }

        // Print the packet header.
        printf("Packet length: %d\n", header->len);
        printf("Packet number: %d\n", header->ts.tv_sec);
        printf("Packet timestamp: %d\n", header->ts.tv_usec);

        // Print the packet data.
        for (int i = 0; i < header->len; i++) {
            printf("%02x ", packet[i]);
        }

        printf("\n\n");
    }

    // Close the device.
    pcap_close(handle);

    return 0;
}