//Falcon2-11B DATASET v1.0 Category: Wireless Network Scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <pcap.h>
#include <net/ethernet.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/if_ether.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    char *dev = "wlan0";
    const char *promisc = "promiscuous";
    const char *remote = NULL;
    const char *timeout = "5000";

    pcap_t *handle;
    if (pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf) == -1) {
        fprintf(stderr, "Could not open device %s: %s\n", dev, errbuf);
        exit(1);
    }

    pcap_compile(handle, &dev, remote, timeout, promisc);

    char *name;
    struct bpf_program fp;
    struct pcap_pkthdr h;
    const u_char *p;

    int count = 0;
    while ((p = pcap_next(handle, &h))!= NULL) {
        if (h.len < sizeof(struct ether_header)) {
            continue;
        }

        struct ether_header *eth = (struct ether_header *)p;
        if (memcmp(eth->ether_shost, eth->ether_dhost, 6) == 0) {
            continue;
        }

        name = ether_ntoa(eth->ether_shost);
        printf("SSID: %s\n", name);
        printf("MAC: %02x:%02x:%02x:%02x:%02x:%02x\n", eth->ether_shost[0], eth->ether_shost[1], eth->ether_shost[2], eth->ether_shost[3], eth->ether_shost[4], eth->ether_shost[5]);
        printf("Channel: %d\n", ntohs(eth->ether_type) & 0xf000);
        printf("Count: %d\n", count);
        count++;
    }

    pcap_freecode(&fp);
    pcap_close(handle);
    return 0;
}