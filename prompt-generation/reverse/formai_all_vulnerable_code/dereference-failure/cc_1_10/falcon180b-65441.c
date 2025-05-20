//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: light-weight
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>

#define MAX_PACKET_SIZE 65535

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // Process the captured packet here
}

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    char filter_str[100];
    struct bpf_program fp;
    int net = 0;
    int mask = 0xff;
    int timeout = 1000;
    int ret;

    if (argc!= 3) {
        printf("Usage: %s <interface> <filter>\n", argv[0]);
        return 1;
    }

    strcpy(filter_str, argv[2]);

    if (pcap_lookupnet(argv[1], &net, &mask, errbuf) == -1) {
        printf("Error: %s\n", errbuf);
        return 1;
    }

    handle = pcap_open_live(argv[1], MAX_PACKET_SIZE, 1, 0, errbuf);
    if (handle == NULL) {
        printf("Error: %s\n", errbuf);
        return 1;
    }

    if (pcap_compile(handle, &fp, filter_str, 0, net) == -1) {
        printf("Error: %s\n", errbuf);
        return 1;
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Error: %s\n", errbuf);
        return 1;
    }

    pcap_loop(handle, -1, process_packet, NULL);

    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}