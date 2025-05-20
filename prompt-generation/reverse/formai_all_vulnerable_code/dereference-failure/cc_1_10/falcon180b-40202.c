//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>

#define SNAPLEN 1500
#define MAX_PACKETS 1000
#define TRUE 1
#define FALSE 0

typedef struct {
    u_char *data;
    int len;
} packet_t;

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    packet_t *pkt = (packet_t *) args;
    pkt->data = (u_char *) malloc(header->len);
    pkt->len = header->len;
    memcpy(pkt->data, packet, header->len);
}

int main(int argc, char **argv) {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    char filter_str[50] = "tcp";
    struct bpf_program filter;
    packet_t *packets = NULL;
    int num_packets = 0;
    int i;

    handle = pcap_open_live(argv[1], SNAPLEN, 1, 0, errbuf);
    if (handle == NULL) {
        printf("Error opening interface: %s\n", errbuf);
        exit(1);
    }

    if (pcap_compile(handle, &filter, filter_str, 0, 0)!= 0) {
        printf("Error compiling filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    if (pcap_setfilter(handle, &filter)!= 0) {
        printf("Error setting filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    packets = (packet_t *) malloc(MAX_PACKETS * sizeof(packet_t));
    for (i = 0; i < MAX_PACKETS; i++) {
        packets[i].data = NULL;
        packets[i].len = 0;
    }

    pcap_loop(handle, -1, packet_handler, (u_char *) packets);

    for (i = 0; i < num_packets; i++) {
        printf("Packet %d:\n", i);
        printf("Data: ");
        for (int j = 0; j < packets[i].len; j++) {
            printf("%02X ", packets[i].data[j]);
        }
        printf("\n");
    }

    pcap_freecode(&filter);
    pcap_close(handle);
    return 0;
}