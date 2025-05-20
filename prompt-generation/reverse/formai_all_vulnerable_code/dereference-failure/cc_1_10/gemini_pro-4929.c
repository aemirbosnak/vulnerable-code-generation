//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: scalable
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

#define PCAP_BUF_SIZE 65535

struct myPacket {
    struct pcap_pkthdr hdr;
    unsigned char *data;
};

void packetHandler(u_char *args, const struct pcap_pkthdr *hdr, const u_char *data) {
    struct myPacket *packet = (struct myPacket *)args;
    packet->hdr = *hdr;
    packet->data = (unsigned char *)malloc(hdr->caplen);
    memcpy(packet->data, data, hdr->caplen);
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program filter;
    struct myPacket packet;
    char *iface;

    // Get the interface to capture packets from
    iface = pcap_lookupdev(errbuf);
    if (!iface) {
        fprintf(stderr, "Error getting the interface: %s\n", errbuf);
        return -1;
    }

    // Open the device for capturing
    handle = pcap_open_live(iface, PCAP_BUF_SIZE, 1, 1000, errbuf);
    if (!handle) {
        fprintf(stderr, "Error opening the device: %s\n", errbuf);
        return -1;
    }

    // Compile the filter
    if (pcap_compile(handle, &filter, "tcp and port 80", 1, 0) == -1) {
        fprintf(stderr, "Error compiling the filter: %s\n", pcap_geterr(handle));
        return -1;
    }

    // Set the filter
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Error setting the filter: %s\n", pcap_geterr(handle));
        return -1;
    }

    // Start capturing packets
    pcap_loop(handle, 10, packetHandler, (u_char *)&packet);

    // Print the packet data
    for (int i = 0; i < packet.hdr.caplen; i++) {
        printf("%02X ", packet.data[i]);
    }
    printf("\n");

    // Cleanup
    free(packet.data);
    pcap_close(handle);
    pcap_freecode(&filter);

    return 0;
}