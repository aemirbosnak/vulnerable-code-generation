//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

#define MAX_PACKET_SIZE 65535

int main() {
    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program filter;
    char filter_str[] = "tcp";
    int net, mask;
    int ret;
    unsigned char *packet;

    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Error: %s\n", errbuf);
        exit(1);
    }

    handle = pcap_open_live(dev, MAX_PACKET_SIZE, 1, 0, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error: %s\n", errbuf);
        exit(1);
    }

    ret = pcap_compile(handle, &filter, filter_str, 0, net);
    if (ret!= 0) {
        fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
        exit(1);
    }

    ret = pcap_setfilter(handle, &filter);
    if (ret!= 0) {
        fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
        exit(1);
    }

    packet = (unsigned char*) malloc(MAX_PACKET_SIZE);
    while (1) {
        ret = pcap_next_ex(handle, &packet, &net);
        if (ret == 0) {
            printf("Packet captured!\n");
        } else if (ret == -1) {
            fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
            exit(1);
        } else {
            printf("Packet dropped\n");
        }
    }

    pcap_freecode(&filter);
    pcap_close(handle);
    free(packet);
    return 0;
}