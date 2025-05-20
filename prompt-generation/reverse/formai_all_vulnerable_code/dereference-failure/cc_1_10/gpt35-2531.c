//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: satisfied
#include <stdio.h>
#include <pcap.h>

int main(int argc, char **argv) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    const u_char *packet;
    struct pcap_pkthdr header;
    int packet_count = 0;

    // Open ethernet interface
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open interface: %s\n", errbuf);
        return 1;
    }

    // Begin packet capture loop
    while (packet_count < 10) {
        packet = pcap_next(handle, &header);
        if (packet != NULL) {
            printf("Packet %d captured.\n", packet_count);
            printf("%ld bytes captured\n", header.caplen);
            printf("Source MAC: ");
            for (int i = 0; i < 6; i++) {
                printf("%02x:", packet[i]);
            }
            printf("\n");
            printf("Destination MAC: ");
            for (int i = 6; i < 12; i++) {
                printf("%02x:", packet[i]);
            }
            printf("\n");
            printf("Packet data:\n");
            for (int i = 0; i < header.caplen; i++) {
                printf("%02x ", packet[i]);
                if ((i + 1) % 16 == 0) {
                    printf("\n");
                }
            }
            printf("\n");
        } else {
            fprintf(stderr, "No packets captured.\n");
        }
        packet_count++;
    }

    // Close the handle to free resources
    pcap_close(handle);

    return 0;
}