//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main() {
    pcap_t *handle;
    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    char filter_exp[] = "port 80";
    struct bpf_program fp;

    // Find a device to capture from.
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find a device: %s\n", errbuf);
        return 1;
    }

    // Open the device.
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open the device: %s\n", errbuf);
        return 1;
    }

    // Compile the filter expression.
    if (pcap_compile(handle, &fp, filter_exp, 0, 0) < 0) {
        fprintf(stderr, "Couldn't compile the filter expression: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Set the filter.
    if (pcap_setfilter(handle, &fp) < 0) {
        fprintf(stderr, "Couldn't set the filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Capture packets.
    int i = 0;
    while (i < 10) {
        struct pcap_pkthdr *header;
        const u_char *packet;

        int res = pcap_next_ex(handle, &header, &packet);
        if (res == 0) {
            continue;
        } else if (res == -1) {
            fprintf(stderr, "Error capturing packets: %s\n", pcap_geterr(handle));
            return 1;
        }

        // Process the packet.
        printf("Packet %d: %d bytes\n", i, header->len);
        for (int j = 0; j < header->len; j++) {
            printf("%02x ", packet[j]);
        }
        printf("\n");
        i++;
    }

    // Close the device.
    pcap_close(handle);

    return 0;
}