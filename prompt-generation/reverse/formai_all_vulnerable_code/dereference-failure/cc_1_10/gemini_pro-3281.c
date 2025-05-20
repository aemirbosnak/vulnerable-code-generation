//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: rigorous
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>

void dump_packet(const u_char *packet, const int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%02x ", packet[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    char *device = "lo0";
    char *filter = "port 80";
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    struct pcap_pkthdr *header;
    const u_char *packet;
    int i = 0;

    if ((handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf)) == NULL) {
        fprintf(stderr, "pcap_open_live(): %s\n", errbuf);
        exit(1);
    }

    if (pcap_compile(handle, &fp, filter, 0, 0) == -1) {
        fprintf(stderr, "pcap_compile(): %s\n", pcap_geterr(handle));
        exit(1);
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "pcap_setfilter(): %s\n", pcap_geterr(handle));
        exit(1);
    }

    while (1) {
        if ((packet = pcap_next(handle, &header)) == NULL) {
            continue;
        }

        printf("Packet %d\n", i++);
        dump_packet(packet, header->len);
    }

    pcap_close(handle);
    return 0;
}