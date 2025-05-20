//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <errno.h>

#define MAX_SNAPLEN 65535
#define MAX_PKTS 100

char *dev = NULL;
pcap_t *handle;
pcap_dumper_t *dump_handle;

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet captured:\n");
    printf("Packet length: %d\n", header->len);
    printf("Packet data: ");
    for (int i = 0; i < header->len; i++) {
        printf("%02X ", packet[i]);
    }
    printf("\n");
}

void cleanup(void) {
    pcap_dump_flush(dump_handle);
    pcap_dump_close(dump_handle);
    pcap_close(handle);
    free(dev);
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Error: %s\n", errbuf);
        exit(1);
    }

    handle = pcap_open_live(dev, MAX_SNAPLEN, 1, 0, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error: %s\n", errbuf);
        exit(1);
    }

    if (pcap_setfilter(handle, "tcp") == -1) {
        fprintf(stderr, "Error: Could not set filter\n");
        exit(1);
    }

    dump_handle = pcap_dump_open(handle, "output.pcap");
    if (dump_handle == NULL) {
        fprintf(stderr, "Error: Could not open output file\n");
        exit(1);
    }

    printf("Packet capture started...\n");
    pcap_loop(handle, -1, process_packet, NULL);
    cleanup();

    return 0;
}