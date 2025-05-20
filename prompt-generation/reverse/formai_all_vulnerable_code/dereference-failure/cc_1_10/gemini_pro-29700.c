//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
    char *device;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 net;
    bpf_u_int32 mask;
    struct pcap_pkthdr *header;
    const u_char *packet;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <network interface>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    device = argv[1];

    if (pcap_lookupnet(device, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "pcap_lookupnet: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    handle = pcap_open_live(device, BUFSIZ, 1, 100, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    if (pcap_compile(handle, &fp, "ether proto 0x888e", 0, net) == -1) {
        fprintf(stderr, "pcap_compile: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "pcap_setfilter: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    while (1) {
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == -1) {
            fprintf(stderr, "pcap_next_ex: %s\n", pcap_geterr(handle));
            break;
        } else if (res == 0) {
            continue;
        }

        printf("Packet length: %d\n", header->len);
        printf("Packet data: ");
        for (int i = 0; i < header->len; i++) {
            printf("%02x ", packet[i]);
        }
        printf("\n\n");
    }

    pcap_close(handle);
    return EXIT_SUCCESS;
}