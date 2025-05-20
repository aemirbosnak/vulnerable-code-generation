//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <pcap/pcap.h>

int main() {
    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr *header;
    const u_char *packet;

    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "pcap_lookupdev() failed: %s\n", errbuf);
        return -1;
    }

    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live() failed: %s\n", errbuf);
        return -1;
    }

    while (1) {
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == -1) {
            fprintf(stderr, "pcap_next_ex() failed: %s\n", pcap_geterr(handle));
            break;
        } else if (res == 0) {
            continue;
        }

        printf("Packet length: %d\n", header->len);

        const u_char *mac_src = &packet[6];
        const u_char *mac_dst = &packet[0];
        printf("MAC source: %.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n", mac_src[0], mac_src[1], mac_src[2], mac_src[3], mac_src[4], mac_src[5]);
        printf("MAC destination: %.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n", mac_dst[0], mac_dst[1], mac_dst[2], mac_dst[3], mac_dst[4], mac_dst[5]);

        const u_char *ip_src = &packet[26];
        const u_char *ip_dst = &packet[30];
        printf("IP source: %d.%d.%d.%d\n", ip_src[0], ip_src[1], ip_src[2], ip_src[3]);
        printf("IP destination: %d.%d.%d.%d\n", ip_dst[0], ip_dst[1], ip_dst[2], ip_dst[3]);

        const u_char *port_src = &packet[34];
        const u_char *port_dst = &packet[36];
        printf("Port source: %d\n", port_src[0] * 256 + port_src[1]);
        printf("Port destination: %d\n", port_dst[0] * 256 + port_dst[1]);

        printf("Payload:\n");
        for (int i = 42; i < header->len; i++) {
            printf("%.2x ", packet[i]);
        }
        printf("\n\n");
    }

    pcap_close(handle);
    return 0;
}