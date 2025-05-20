//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet received: %d bytes\n", header->len);
    printf("Packet payload: ");
    for (int i = 0; i < header->len; i++) {
        printf("%02X ", packet[i]);
    }
    printf("\n");
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    char filter_str[] = "tcp port 80";
    struct bpf_program filter;

    handle = pcap_open_live("eth0", 65535, 1, 0, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening capture device: %s\n", errbuf);
        exit(1);
    }

    if (pcap_compile(handle, &filter, filter_str, 0, 0) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        exit(2);
    }

    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        exit(3);
    }

    while (1) {
        const u_char *packet;
        struct pcap_pkthdr header;
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == 1) {
            process_packet(NULL, &header, packet);
        } else if (res == 0) {
            printf("No packet received\n");
        } else {
            fprintf(stderr, "Error capturing packet: %s\n", pcap_geterr(handle));
            exit(4);
        }
    }

    pcap_freecode(&filter);
    pcap_close(handle);
    return 0;
}