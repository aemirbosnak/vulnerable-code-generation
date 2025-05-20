//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: single-threaded
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "tcp";
    bpf_u_int32 mask;
    bpf_u_int32 net;
    struct pcap_pkthdr *header;
    const u_char *packet;

    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return EXIT_FAILURE;
    }

    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    while (1) {
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == -1) {
            fprintf(stderr, "Error reading packet: %s\n", pcap_geterr(handle));
            continue;
        } else if (res == 0) {
            continue;
        }

        printf("Packet length: %d\n", header->len);
        printf("Packet data:\n");
        for (int i = 0; i < header->len; i++) {
            printf("%02x ", packet[i]);
        }
        printf("\n\n");
    }

    pcap_close(handle);
    return EXIT_SUCCESS;
}