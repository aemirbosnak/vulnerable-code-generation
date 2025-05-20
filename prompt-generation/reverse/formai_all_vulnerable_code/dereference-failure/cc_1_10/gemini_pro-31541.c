//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: active
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SNAPLEN 1518
#define PROMISC 1

int main(int argc, char *argv[]) {
    char *device;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr *header;
    const u_char *packet;
    int i;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }

    device = argv[1];

    handle = pcap_open_live(device, SNAPLEN, PROMISC, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live(): %s\n", errbuf);
        return EXIT_FAILURE;
    }

    while (1) {
        packet = pcap_next(handle, &header);
        if (packet == NULL) {
            continue;
        }

        printf("Packet captured at %s\n", ctime((const time_t *) &header->ts.tv_sec));
        printf("Length: %d bytes\n", header->len);
        printf("Capture length: %d bytes\n", header->caplen);

        for (i = 0; i < header->caplen; i++) {
            printf("%02x ", packet[i]);
            if ((i + 1) % 16 == 0) {
                printf("\n");
            }
        }
        printf("\n\n");
    }

    pcap_close(handle);

    return EXIT_SUCCESS;
}