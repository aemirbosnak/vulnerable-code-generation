//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>

#define MAX_PACKET_SIZE 65535
#define SNAPLEN 1514
#define TRUE 1
#define FALSE 0

typedef struct {
    u_char *data;
    int len;
} Packet;

void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    Packet *pkt = (Packet *) args;
    pkt->data = (u_char *) malloc(header->len);
    if (pkt->data == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }
    memcpy(pkt->data, packet, header->len);
    pkt->len = header->len;
}

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    char filter_str[100];
    struct bpf_program filter;
    Packet *packet;
    int ret;
    int count = 0;

    if (argc!= 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        exit(1);
    }

    if ((handle = pcap_open_live(argv[1], SNAPLEN, 1, 1000, errbuf)) == NULL) {
        printf("Error opening interface: %s\n", errbuf);
        exit(1);
    }

    if (pcap_compile(handle, &filter, filter_str, 1, 0)!= 0) {
        printf("Error compiling filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    if (pcap_setfilter(handle, &filter)!= 0) {
        printf("Error setting filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    packet = (Packet *) malloc(sizeof(Packet));
    if (packet == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    while (TRUE) {
        ret = pcap_loop(handle, 0, got_packet, (u_char *) packet);
        if (ret == -1) {
            printf("Error capturing packets: %s\n", pcap_geterr(handle));
            exit(1);
        }
        if (ret == 0) {
            printf("No packets captured\n");
            exit(0);
        }
        if (ret > 0) {
            printf("Captured %d packets\n", count);
            exit(0);
        }
        count++;
    }

    return 0;
}