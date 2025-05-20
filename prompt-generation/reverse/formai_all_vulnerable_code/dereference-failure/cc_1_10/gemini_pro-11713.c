//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: light-weight
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // Find a suitable device.
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "pcap_lookupdev(): %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Open the device.
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live(): %s\n", errbuf);
        return EXIT_FAILURE;
    }

    struct pcap_pkthdr *header;
    const u_char *data;
    int res;

    while ((res = pcap_next_ex(handle, &header, &data)) >= 0) {
        if (res == 0) {
            continue;
        }

        printf("Packet length: %d\n", header->len);
        printf("Packet data:\n");
        for (int i = 0; i < header->len; i++) {
            printf("%02x ", data[i]);
        }
        printf("\n\n");
    }

    if (res == -1) {
        fprintf(stderr, "pcap_next_ex(): %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Close the device.
    pcap_close(handle);

    return EXIT_SUCCESS;
}