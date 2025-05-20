//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>
#include <pcap.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PACKETS 100
#define SNAPLEN 1518

void signal_handler(int signum) {
    if (signum == SIGINT) {
        printf("\nExiting...\n");
        exit(0);
    }
}

int main(int argc, char *argv[]) {
    // Handle Ctrl+C gracefully
    signal(SIGINT, signal_handler);

    // Check command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return -1;
    }

    // Open the network device for packet capture
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(argv[1], SNAPLEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live(): %s\n", errbuf);
        return -1;
    }

    // Set the filter to capture all packets
    struct bpf_program filter;
    if (pcap_compile(handle, &filter, "ip", 1, 0) < 0) {
        fprintf(stderr, "pcap_compile(): %s\n", pcap_geterr(handle));
        pcap_close(handle);
        return -1;
    }
    if (pcap_setfilter(handle, &filter) < 0) {
        fprintf(stderr, "pcap_setfilter(): %s\n", pcap_geterr(handle));
        pcap_close(handle);
        return -1;
    }

    // Loop through the packets and print their details
    int count = 0;
    struct pcap_pkthdr header;
    const u_char *packet;
    while ((packet = pcap_next(handle, &header)) != NULL && count < MAX_PACKETS) {
        printf("Packet %d: %d bytes\n", count + 1, header.len);
        printf("  Timestamp: %ld.%ld\n", header.ts.tv_sec, header.ts.tv_usec);
        printf("  Source IP: %s\n", inet_ntoa(*(struct in_addr *) (packet + 12)));
        printf("  Destination IP: %s\n", inet_ntoa(*(struct in_addr *) (packet + 16)));
        printf("  Protocol: %d\n", packet[9]);
        count++;
    }

    // Free the filter memory
    pcap_freecode(&filter);

    // Close the network device
    pcap_close(handle);

    return 0;
}