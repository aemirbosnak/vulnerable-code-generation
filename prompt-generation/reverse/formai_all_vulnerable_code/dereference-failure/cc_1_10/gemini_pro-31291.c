//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <pcap/pcap.h>

int main() {
    char *dev = NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr *header;
    const u_char *packet;
    int res;

    printf("Let's dive into the fascinating world of network packets!\n");

    if (pcap_findalldevs(&dev, errbuf) == -1) {
        fprintf(stderr, "Oops, couldn't find any network devices! (%s)\n", errbuf);
        return -1;
    }

    printf("Hurray! Found a network device: %s\n", dev);

    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Oh no! Couldn't open the device! (%s)\n", errbuf);
        return -1;
    }

    printf("We're all set! Let's start monitoring those packets.\n");

    while ((res = pcap_next_ex(handle, &header, &packet)) >= 0) {
        if (res == 0) continue;

        printf("Yay! We've got a packet! Size: %d bytes\n", header->len);

        // Let's print some details:
        printf("\tTimestamp: %lu.%lu\n", header->ts.tv_sec, header->ts.tv_usec);
        printf("\tCapture length: %d\n", header->caplen);
        printf("\tOriginal length: %d\n", header->len);

        if (header->len > 0) {
            printf("\tPacket data (first 16 bytes): ");
            for (int i = 0; i < 16 && i < header->len; i++) {
                printf("%02X ", packet[i]);
            }
            printf("\n");
        }
    }

    if (res == -1) {
        fprintf(stderr, "Oops, something went wrong while monitoring packets! (%s)\n", pcap_geterr(handle));
    }

    pcap_close(handle);
    printf("Thanks for joining us! Stay curious and keep exploring the world of network packets.\n");
    return 0;
}