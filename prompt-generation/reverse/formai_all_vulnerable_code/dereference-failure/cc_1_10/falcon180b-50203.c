//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: authentic
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_DEVICES 10
#define MAX_SNAPLEN 65535
#define MAX_FILTER 100

pcap_t *dev;
char errbuf[PCAP_ERRBUF_SIZE];
char *dev_list[MAX_DEVICES];
int num_devs;
int snapshot_len;
struct bpf_program filter;

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet received:\n");
    printf("Length: %d\n", header->len);
    printf("Data: ");
    for (int i = 0; i < header->len; i++) {
        printf("%02X ", packet[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        exit(1);
    }

    char *dev_name = argv[1];
    if (pcap_findalldevs(&dev_list[0], errbuf) == -1) {
        fprintf(stderr, "Error: %s\n", errbuf);
        exit(1);
    }

    num_devs = pcap_findalldevs(&dev_list[0], errbuf);
    for (int i = 0; i < num_devs; i++) {
        if (strcmp(dev_list[i], dev_name) == 0) {
            printf("Opening device: %s\n", dev_list[i]);
            dev = pcap_open_live(dev_list[i], MAX_SNAPLEN, 0, 0, errbuf);
            if (dev == NULL) {
                fprintf(stderr, "Error: %s\n", errbuf);
                exit(1);
            }
            break;
        }
    }

    if (dev == NULL) {
        fprintf(stderr, "Error: device not found\n");
        exit(1);
    }

    if (pcap_compile(dev, &filter, "tcp", 0, 0) == -1) {
        fprintf(stderr, "Error: %s\n", pcap_geterr(dev));
        exit(1);
    }

    if (pcap_setfilter(dev, &filter) == -1) {
        fprintf(stderr, "Error: %s\n", pcap_geterr(dev));
        exit(1);
    }

    pcap_loop(dev, -1, process_packet, NULL);

    pcap_freecode(&filter);
    pcap_close(dev);

    return 0;
}