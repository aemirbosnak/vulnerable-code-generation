//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <pcap.h>

#define MAX_DATA_SIZE 65535
#define SNAP_LEN 65535
#define ERROR_BUF_SIZE 1024

typedef struct {
    u_char *data;
    int len;
} PacketData;

static void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    PacketData *data = (PacketData*)args;
    data->data = malloc(header->len);
    data->len = header->len;
    memcpy(data->data, packet, header->len);
}

int main() {
    char errbuf[ERROR_BUF_SIZE];
    char *dev = "eth0";
    pcap_t *handle;
    PacketData data;
    bpf_u_int32 net = 0xffffff00;
    bpf_u_int32 mask = 0xffffff00;
    char filter_exp[] = "net 192.168.1.0/24";

    handle = pcap_open_live(dev, SNAP_LEN, 1, 1000, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live(): %s\n", errbuf);
        exit(1);
    }

    if (pcap_compile(handle, &data, filter_exp, 1, net)!= 0) {
        fprintf(stderr, "pcap_compile(): %s\n", pcap_geterr(handle));
        exit(2);
    }

    if (pcap_setfilter(handle, &data)!= 0) {
        fprintf(stderr, "pcap_setfilter(): %s\n", pcap_geterr(handle));
        exit(3);
    }

    while (pcap_loop(handle, -1, got_packet, &data) >= 0) {
        printf("Received packet: %s\n", data.data);
        free(data.data);
        data.data = NULL;
        data.len = 0;
    }

    pcap_close(handle);
    return 0;
}