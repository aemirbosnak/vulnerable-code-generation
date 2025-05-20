//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>

#define MAX_PACKET_SIZE 65535

struct packet_header {
    uint32_t ts_sec;      // Timestamp seconds
    uint32_t ts_usec;     // Timestamp microseconds
    uint32_t incl_len;    // Length of the packet including header
    uint32_t orig_len;    // Original length of the packet
};

struct packet_data {
    struct packet_header header;
    uint8_t data[MAX_PACKET_SIZE];
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(argv[1], MAX_PACKET_SIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Error opening interface: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    while (1) {
        struct pcap_pkthdr *header; // Packet header
        const u_char *packet;        // Packet data

        int res = pcap_next_ex(handle, &header, &packet);
        if (res == 0) { // Timeout
            continue;
        } else if (res == -1) { // Error
            printf("Error reading packet: %s\n", pcap_geterr(handle));
            break;
        }

        // Parse the packet header
        struct packet_data *pkt = (struct packet_data *)packet;
        printf("Timestamp: %u.%06u\n", pkt->header.ts_sec, pkt->header.ts_usec);
        printf("Packet length: %u\n", pkt->header.incl_len);

        // Dump the packet data
        printf("Packet data:\n");
        for (int i = 0; i < pkt->header.incl_len; i++) {
            printf("%02X ", pkt->data[i]);
        }
        printf("\n\n");
    }

    pcap_close(handle);
    return EXIT_SUCCESS;
}