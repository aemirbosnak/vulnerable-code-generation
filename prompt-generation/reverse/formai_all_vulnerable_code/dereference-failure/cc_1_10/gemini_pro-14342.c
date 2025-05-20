//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <pcap/pcap.h>
#include <time.h>

#define MAX_BYTES 1024

struct packet_header {
    u_int32_t timestamp;
    u_int32_t length;
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *interface = argv[1];
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(interface, MAX_BYTES, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Error opening interface: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    struct pcap_pkthdr *header;
    const u_char *data;
    while (1) {
        int res = pcap_next_ex(handle, &header, &data);
        if (res == -1) {
            printf("Error capturing packet: %s\n", pcap_geterr(handle));
            break;
        } else if (res == 0) {
            continue;
        }

        struct packet_header *pkt_header = (struct packet_header *)data;
        printf("Packet captured at %u.%06u\n", pkt_header->timestamp, pkt_header->length);
        printf("Packet length: %u bytes\n", pkt_header->length);
        printf("Packet data:\n");
        for (int i = 0; i < pkt_header->length; i++) {
            printf("%02x ", data[i]);
        }
        printf("\n");
    }

    pcap_close(handle);
    return EXIT_SUCCESS;
}