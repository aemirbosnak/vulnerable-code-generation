//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: scientific
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/* Function to print packet data */
void print_packet(const unsigned char *packet, int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%02x ", packet[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

/* Main function */
int main(int argc, char *argv[]) {
    pcap_t *handle;         /* Packet capture handle */
    char *dev;              /* Device to capture on */
    char errbuf[PCAP_ERRBUF_SIZE];      /* Error buffer */

    /* Open device for live capture */
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return EXIT_FAILURE;
    }
    handle = pcap_open_live(dev, 65536, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return EXIT_FAILURE;
    }

    /* Set filter for capturing only TCP packets */
    struct bpf_program filter;
    char tcp_filter[] = "tcp";
    int ret = pcap_compile(handle, &filter, tcp_filter, 0, PCAP_NETMASK_UNKNOWN);
    if (ret == -1) {
        fprintf(stderr, "Couldn't compile filter %s: %s\n", tcp_filter, pcap_geterr(handle));
        pcap_close(handle);
        return EXIT_FAILURE;
    }
    ret = pcap_setfilter(handle, &filter);
    if (ret == -1) {
        fprintf(stderr, "Couldn't set filter %s: %s\n", tcp_filter, pcap_geterr(handle));
        pcap_close(handle);
        return EXIT_FAILURE;
    }

    /* Start the capture loop */
    struct pcap_pkthdr header;
    const unsigned char *packet;
    while (1) {
        packet = pcap_next(handle, &header);
        if (packet == NULL) {
            continue;
        }

        /* Print packet data */
        printf("Packet captured, length = %d\n", header.len);
        print_packet(packet, header.len);
    }

    /* Cleanup */
    pcap_freecode(&filter);
    pcap_close(handle);

    return EXIT_SUCCESS;
}