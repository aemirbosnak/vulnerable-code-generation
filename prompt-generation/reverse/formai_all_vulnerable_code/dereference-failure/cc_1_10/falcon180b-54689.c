//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>

#define TRUE    1
#define FALSE   0
#define MAX_PKT_SIZE 65535

typedef struct _packet {
    u_char *data;
    int size;
} PACKET;

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    PACKET *pkt = (PACKET *) args;
    pkt->data = (u_char *) malloc(header->caplen);
    if (pkt->data == NULL) {
        fprintf(stderr, "Error: failed to allocate memory for packet data.\n");
        exit(EXIT_FAILURE);
    }
    memcpy(pkt->data, packet, header->caplen);
    pkt->size = header->caplen;
}

int main(int argc, char **argv) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    char *dev;
    char filter_str[100];
    struct bpf_program filter;
    PACKET *packet;
    int res;

    // Open device for capturing
    dev = "eth0";
    handle = pcap_open_live(dev, BUFSIZ, 1, 0, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // Compile filter expression
    sprintf(filter_str, "tcp port 80");
    res = pcap_compile(handle, &filter, filter_str, 0, 0);
    if (res == -1) {
        fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Set filter
    res = pcap_setfilter(handle, &filter);
    if (res == -1) {
        fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Allocate memory for packet
    packet = (PACKET *) malloc(sizeof(PACKET));
    if (packet == NULL) {
        fprintf(stderr, "Error: failed to allocate memory for packet.\n");
        exit(EXIT_FAILURE);
    }

    // Register callback function
    pcap_loop(handle, -1, packet_handler, (u_char *) packet);

    // Free resources and exit
    pcap_freecode(&filter);
    pcap_close(handle);
    free(packet->data);
    free(packet);
    return 0;
}