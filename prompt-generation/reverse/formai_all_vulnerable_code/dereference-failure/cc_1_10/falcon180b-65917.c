//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

#define MAX_PACKET_SIZE 65535
#define MAX_PACKET_COUNT 1000

struct packet {
    u_char *data;
    size_t size;
};

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct packet *pkt = (struct packet *) args;
    pkt->data = (u_char *) malloc(header->caplen);
    pkt->size = header->caplen;
    memcpy(pkt->data, packet, header->caplen);
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    const u_char *packet;
    struct packet pkts[MAX_PACKET_COUNT];
    int i = 0;

    handle = pcap_open_live("eth0", 65535, 1, 0, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening capture device: %s\n", errbuf);
        exit(1);
    }

    pcap_loop(handle, -1, packet_handler, (u_char *) pkts);

    for (i = 0; i < MAX_PACKET_COUNT && pkts[i].data!= NULL; i++) {
        packet = pkts[i].data;
        printf("Packet %d:\n", i);
        printf("Size: %d\n", pkts[i].size);
        printf("Data:\n");
        for (int j = 0; j < pkts[i].size; j++) {
            printf("%02X ", *(packet + j));
        }
        printf("\n");
        free(pkts[i].data);
    }

    pcap_close(handle);

    return 0;
}