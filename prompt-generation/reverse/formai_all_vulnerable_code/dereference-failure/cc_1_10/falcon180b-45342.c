//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: automated
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#define SNAPLEN 65535
#define PCAP_ERRBUF_SIZE 256

void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet received with length %d\n", header->len);
    printf("Data:\n");
    for(int i=0; i<header->len; i++){
        printf("%02X ", packet[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    char dev[100];
    struct bpf_program filter;
    char filter_exp[50] = "tcp";

    // Get device name
    if (argc!= 2) {
        printf("Error: Please provide the network device name.\n");
        exit(1);
    }
    strcpy(dev, argv[1]);

    // Open the device for capturing
    handle = pcap_open_live(dev, SNAPLEN, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Error: %s\n", errbuf);
        exit(1);
    }

    // Compile the filter expression
    if (pcap_compile(handle, &filter, filter_exp, 0, 0) == -1) {
        printf("Error: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // Set the filter
    if (pcap_setfilter(handle, &filter) == -1) {
        printf("Error: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // Start capturing packets
    pcap_loop(handle, 0, got_packet, NULL);

    // Close the device
    pcap_freecode(&filter);
    pcap_close(handle);

    return 0;
}