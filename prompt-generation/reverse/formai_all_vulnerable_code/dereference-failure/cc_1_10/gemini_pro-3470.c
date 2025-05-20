//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main() {
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    bpf_u_int32 net, mask;
    struct pcap_pkthdr *header;
    const u_char *packet;
    pcap_t *handle;

    printf("Opening network interface...");
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        perror(errbuf);
        exit(1);
    }
    printf("Done.\n");

    printf("Getting network parameters...");
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        perror(errbuf);
        exit(1);
    }
    printf("Done.\n");

    printf("Opening packet capture handle...");
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        perror(errbuf);
        exit(1);
    }
    printf("Done.\n");

    printf("Listening for packets...");
    while (1) {
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == 0) {
            continue;
        } else if (res == -1) {
            perror("pcap_next_ex() failed");
            exit(1);
        }

        printf("[%ld] ", header->ts.tv_sec);
        for (int i = 0; i < header->len; i++) {
            printf("%02X ", packet[i]);
        }
        printf("\n");
    }

    pcap_close(handle);
    return 0;
}