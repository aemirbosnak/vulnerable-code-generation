//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

#define MAX_PACKET_SIZE 65535
#define SNAPLEN 1514
#define TRUE 1
#define FALSE 0

typedef struct {
    u_char *data;
    size_t size;
} PacketData;

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    PacketData *packet_data = (PacketData *) args;
    packet_data->data = (u_char *) malloc(header->caplen);
    packet_data->size = header->caplen;
    memcpy(packet_data->data, packet, header->caplen);
}

int main(int argc, char *argv[]) {
    char *dev = "eth0";
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    bpf_u_int32 mask, net;
    bpf_u_int32 *netp;
    char filter_exp[20];
    PacketData packet_data;
    int ret;

    if (argc!= 2) {
        printf("Usage: %s <filter_expression>\n", argv[0]);
        exit(1);
    }

    strcpy(filter_exp, argv[1]);
    netp = &net;
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Error looking up network for device %s: %s\n", dev, errbuf);
        exit(1);
    }

    handle = pcap_open_live(dev, SNAPLEN, 1, 0, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening live capture for device %s: %s\n", dev, errbuf);
        exit(1);
    }

    if (pcap_compile(handle, &packet_data.data, filter_exp, 1, netp)!= 0) {
        fprintf(stderr, "Error compiling filter expression: %s\n", pcap_geterr(handle));
        exit(1);
    }

    if (pcap_setfilter(handle, &packet_data.data)!= 0) {
        fprintf(stderr, "Error setting filter expression: %s\n", pcap_geterr(handle));
        exit(1);
    }

    ret = pcap_loop(handle, -1, packet_handler, &packet_data);

    if (ret == -1) {
        fprintf(stderr, "Error capturing packets: %s\n", pcap_geterr(handle));
    } else if (ret == 0) {
        fprintf(stdout, "No packets captured\n");
    } else {
        fprintf(stdout, "Captured %d packets\n", ret);
    }

    pcap_freecode(&packet_data.data);
    pcap_close(handle);

    return 0;
}