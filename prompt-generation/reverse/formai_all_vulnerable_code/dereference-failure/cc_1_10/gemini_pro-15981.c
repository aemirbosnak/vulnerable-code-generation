//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main()
{
    char *device;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr *header;
    const u_char *packet;

    /* Find a suitable device to capture packets from. */
    device = pcap_lookupdev(errbuf);
    if (device == NULL) {
        fprintf(stderr, "pcap_lookupdev(): %s\n", errbuf);
        return EXIT_FAILURE;
    }

    /* Open the device for capturing packets. */
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live(): %s\n", errbuf);
        return EXIT_FAILURE;
    }

    /* Capture and print the packets. */
    while (1) {
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == 1) {
            printf("Packet captured at %s\n", ctime((const time_t *)&header->ts.tv_sec));
            printf("Packet length: %d bytes\n\n", header->len);
            for (int i = 0; i < header->len; i++) {
                if (i % 16 == 0) {
                    printf("\n");
                }
                printf("%02x ", packet[i]);
            }
            printf("\n\n");
        } else if (res == 0) {
            printf("No packets captured\n");
        } else {
            fprintf(stderr, "pcap_next_ex(): %s\n", pcap_geterr(handle));
        }
    }

    /* Close the device when done. */
    pcap_close(handle);

    return EXIT_SUCCESS;
}