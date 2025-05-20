//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <stdbool.h> 

#define SNAP_LEN 65535
#define SIZE_ETHERNET 14

void packet_handler(u_char *user, const struct pcap_pkthdr *hdr, const u_char *packet) {
    /* TODO Your packet handler function implementation goes here */
    printf("Packet Captured\n");
    return;
}

void capture_packets(char *dev, int packets) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    handle = pcap_open_live(dev, SNAP_LEN, 1, 1000, errbuf);

    if (handle == NULL) {
        printf("Could not open device %s: %s\n", dev, errbuf);
        exit(1);
    }

    struct bpf_program fp;
    char filter_exp[] = "ip";

    if (pcap_compile(handle, &fp, filter_exp, 0, 0) == -1) {
        printf("Could not parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(1);
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Could not set filter %s: %s\n", filter_exp, pcap_geterr(handle));
        exit(1);
    }

    pcap_loop(handle, packets, packet_handler, NULL);

    pcap_freecode(&fp);
    pcap_close(handle);
}

int main(int argc, char *argv[]) {
    char *dev;
    int packets;
    bool valid_args = false;

    if (argc == 3) {
        dev = argv[1];
        packets = atoi(argv[2]);
        valid_args = true;
    }

    if (!valid_args) {
        printf("Usage: %s <device> <packets>\n", argv[0]);
        exit(1);
    }

    printf("Listening on device: %s...\n", dev);
    capture_packets(dev, packets);
    printf("Done\n");

    return 0;
}