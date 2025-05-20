//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: mathematical
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    char *device;
    bpf_u_int32 net;
    bpf_u_int32 mask;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    pcap_t *handle;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }

    device = argv[1];

    if (pcap_lookupnet(device, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "pcap_lookupnet: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    if (pcap_compile(handle, &fp, "arp", 0, net) == -1) {
        fprintf(stderr, "pcap_compile: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "pcap_setfilter: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    while (1) {
        struct pcap_pkthdr *header;
        const u_char *packet;

        int res = pcap_next_ex(handle, &header, &packet);

        if (res == -1) {
            fprintf(stderr, "pcap_next_ex: %s\n", pcap_geterr(handle));
            break;
        } else if (res == 0) {
            continue;
        }

        printf("Packet length: %d\n", header->len);

        for (int i = 0; i < header->len; i++) {
            printf("%02x ", packet[i]);
        }

        printf("\n\n");
    }

    pcap_close(handle);

    return EXIT_SUCCESS;
}