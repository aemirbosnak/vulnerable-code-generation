//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <arpa/inet.h>

#define MAX_PKT_SIZE 65535
#define SNAPLEN 1514

typedef struct {
    u_char *data;
    int len;
} packet_t;

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    packet_t *pkt = (packet_t *) args;
    pkt->data = malloc(header->caplen);
    pkt->len = header->caplen;
    memcpy(pkt->data, packet, header->caplen);
}

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    char filter_exp[] = "tcp port 80";
    bpf_u_int32 netmask, mask;
    struct bpf_program filter;
    packet_t *pkt = malloc(sizeof(packet_t));
    pkt->data = NULL;
    pkt->len = 0;

    if (pcap_lookupnet(argv[1], &netmask, &mask, errbuf) == -1) {
        fprintf(stderr, "Error looking up network: %s\n", errbuf);
        exit(1);
    }

    handle = pcap_open_live(argv[1], SNAPLEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening live capture: %s\n", errbuf);
        exit(1);
    }

    if (pcap_compile(handle, &filter, filter_exp, 0, netmask)!= 0) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    if (pcap_setfilter(handle, &filter)!= 0) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    pcap_loop(handle, -1, process_packet, pkt);

    return 0;
}