//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "icmp";
    bpf_u_int32 net, mask;
    struct pcap_pkthdr header;
    const u_char *packet;
    int count = 0;

    printf("Packet Capturer starting...\n");

    if (argc != 2) {
        fprintf(stderr, "Must provide interface name");
        exit(EXIT_FAILURE);
    }

    if (pcap_lookupnet(argv[1], &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Error: %s", errbuf);
        exit(EXIT_FAILURE);
    }

    handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error: %s", errbuf);
        exit(EXIT_FAILURE);
    }

    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Error: %s", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error: %s", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    while (count < 10) {
        packet = pcap_next(handle, &header);
        if (packet == NULL) {
            fprintf(stderr, "Error: no packet found");
            continue;
        }

        printf("Packet #%d:\n", ++count);
        printf("\tTimestamp: %ld.%06ld\n", header.ts.tv_sec, header.ts.tv_usec);
        printf("\tLength: %d bytes\n", header.len);

        for (u_int i = 0; i < header.len; i++) {
            printf("%02x", packet[i]);
            if ((i + 1) % 16 == 0) printf("\n");
        }
        printf("\n\n");
    }

    pcap_close(handle);
    printf("Packet Capturer stopped.\n");

    return 0;
}