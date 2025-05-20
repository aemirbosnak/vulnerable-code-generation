//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: innovative
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define SNAPLEN 65535
#define PCAP_ERRBUF_SIZE 256

char errbuf[PCAP_ERRBUF_SIZE];

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Received packet of length %d\n", header->len);
}

int main(int argc, char *argv[]) {
    pcap_t *handle;
    char *dev;
    char filter_str[100];
    struct bpf_program filter;
    int net = 0;
    int mask = 0;
    int status;

    if (argc < 3) {
        printf("Usage: %s <device> <filter>\n", argv[0]);
        exit(1);
    }

    dev = argv[1];
    strcpy(filter_str, argv[2]);

    handle = pcap_open_live(dev, SNAPLEN, 1, 1000, errbuf);

    if (handle == NULL) {
        printf("Error: %s\n", errbuf);
        exit(1);
    }

    status = pcap_compile(handle, &filter, filter_str, 1, net);

    if (status == -1) {
        printf("Error compiling filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    status = pcap_setfilter(handle, &filter);

    if (status == -1) {
        printf("Error setting filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    while (1) {
        status = pcap_loop(handle, -1, process_packet, NULL);

        if (status == -1) {
            printf("Error: %s\n", pcap_geterr(handle));
            exit(1);
        }
    }

    pcap_freecode(&filter);
    pcap_close(handle);

    return 0;
}