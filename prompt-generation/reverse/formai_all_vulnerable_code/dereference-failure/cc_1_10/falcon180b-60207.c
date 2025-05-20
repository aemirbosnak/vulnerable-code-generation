//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <math.h>

#define MAX_SNAPLEN 65535
#define MAX_PKTS 1000
#define ETHERNET_MTU 1500

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    char *dev;
    struct bpf_program fp;
    int net, mask;
    int i, j, k;
    struct pcap_pkthdr *header;
    const u_char *packet;
    double sum = 0.0;
    int packet_count = 0;

    if (pcap_lookupnet("eth0", &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Error: %s\n", errbuf);
        exit(1);
    }

    dev = "eth0";
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Error: %s\n", errbuf);
        exit(1);
    }

    pcap_compile(handle, &fp, "tcp", 1, PCAP_NETMASK_UNKNOWN);
    pcap_setfilter(handle, &fp);

    while (packet_count < MAX_PKTS) {
        packet = pcap_next(handle, &header);

        if (packet == NULL) {
            continue;
        }

        sum += header->len;
        packet_count++;
    }

    pcap_close(handle);

    printf("Average packet size: %.2f bytes\n", sum / packet_count);

    return 0;
}