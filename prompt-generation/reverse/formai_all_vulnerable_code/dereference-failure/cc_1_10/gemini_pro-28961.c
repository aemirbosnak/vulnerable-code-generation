//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pcap.h>

#define MAX_PACKET_SIZE 65535

int main(int argc, char *argv[]) {
    char *interface;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr header;
    const u_char *packet;
    int i;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    interface = argv[1];

    handle = pcap_open_live(interface, MAX_PACKET_SIZE, 0, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening interface: %s\n", errbuf);
        return 1;
    }

    while (1) {
        packet = pcap_next(handle, &header);
        if (packet == NULL) {
            continue;
        }

        printf("Packet captured at %s\n", ctime(&header.ts.tv_sec));
        printf("Packet length: %d\n", header.len);
        printf("Packet data:\n");

        for (i = 0; i < header.len; i++) {
            printf("%02x ", packet[i]);
            if ((i + 1) % 16 == 0) {
                printf("\n");
            }
        }

        printf("\n\n");
    }

    pcap_close(handle);

    return 0;
}