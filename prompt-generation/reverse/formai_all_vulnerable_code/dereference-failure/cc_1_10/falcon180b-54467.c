//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

typedef struct {
    u_char *data;
    int size;
} packet_t;

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    packet_t *packet_data = (packet_t *) args;
    packet_data->data = (u_char *) malloc(header->caplen);
    packet_data->size = header->caplen;
    memcpy(packet_data->data, packet, header->caplen);
}

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    char filter_exp[] = "tcp or udp";
    struct bpf_program fp;
    int net = 1, mask = 0xffffff00;
    int i = 0, j = 0;
    packet_t packet_data;

    handle = pcap_open_live("eth0", 65535, 1, 0, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live() failed: %s\n", errbuf);
        exit(1);
    }

    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "pcap_compile() failed\n");
        exit(1);
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "pcap_setfilter() failed\n");
        exit(1);
    }

    while (1) {
        struct pcap_pkthdr header;
        const u_char *packet;

        packet = pcap_next(handle, &header);

        if (packet == NULL) {
            continue;
        }

        if (header.caplen > 0) {
            process_packet(&packet_data, &header, packet);
            printf("Packet %d:\n", ++i);
            printf("Length: %d\n", header.caplen);
            printf("Data: ");

            for (j = 0; j < header.caplen; j++) {
                printf("%02x ", packet_data.data[j]);
            }

            printf("\n");
        }
    }

    return 0;
}