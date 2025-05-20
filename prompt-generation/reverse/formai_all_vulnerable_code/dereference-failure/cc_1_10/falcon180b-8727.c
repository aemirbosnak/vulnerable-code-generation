//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <string.h>

#define MAX_DATA_SIZE 1024

struct packet_data {
    u_char *data;
    int size;
};

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct packet_data *data = (struct packet_data *)args;
    data->size = header->len;
    data->data = (u_char *)malloc(header->len);
    memcpy(data->data, packet, header->len);
}

int main() {
    char *dev = "eth0";
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    pcap_dumper_t *dumpfile;
    struct bpf_program filter;
    char filter_str[] = "tcp port 80";
    bpf_u_int32 mask;
    bpf_u_int32 net;
    struct pcap_pkthdr header;
    u_char *packet;
    struct packet_data data;

    handle = pcap_open_live(dev, 65535, 1, 0, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error: %s\n", errbuf);
        exit(1);
    }

    pcap_compile(handle, &filter, filter_str, 1, 0);
    pcap_setfilter(handle, &filter);

    dumpfile = pcap_dump_open(handle, "output.pcap");
    if (dumpfile == NULL) {
        fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
        exit(1);
    }

    data.data = NULL;
    data.size = 0;

    while (pcap_next_ex(handle, &header, (const u_char **)&packet) >= 0) {
        if (header.caplen > MAX_DATA_SIZE) {
            fprintf(stderr, "Warning: Packet truncated\n");
            header.caplen = MAX_DATA_SIZE;
        }

        if (data.data!= NULL) {
            free(data.data);
        }

        data.data = (u_char *)malloc(header.caplen);
        memcpy(data.data, packet, header.caplen);
        data.size = header.caplen;

        pcap_dump((u_char *)dumpfile, &header, data.data);
    }

    pcap_dump_close(dumpfile);
    pcap_close(handle);

    return 0;
}