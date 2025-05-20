//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

#define MAXBYTES2CAPTURE 2048

// Function to print packet data
void print_packet(const u_char *packet, struct pcap_pkthdr packet_header, int packet_number) {
    printf("Packet #%d:\n", packet_number);
    // Print packet size and timestamp
    printf("Packet size: %d bytes\n", packet_header.len);
    printf("Packet timestamp: %s", ctime((const time_t *)&packet_header.ts.tv_sec));
    // Print packet data
    for (int i = 0; i < packet_header.len; i++) {
        printf("%02x ", packet[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program filter;
    char filter_exp[] = "ip";
    bpf_u_int32 mask;
    bpf_u_int32 net;

    // Get device name from command line argument
    char *dev = argv[1];

    // Get network mask and IP address of device
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        printf("Error: %s\n", errbuf);
        return 1;
    }

    // Open device for packet capture
    handle = pcap_open_live(dev, MAXBYTES2CAPTURE, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Error: %s\n", errbuf);
        return 1;
    }

    // Compile and apply the filter
    if (pcap_compile(handle, &filter, filter_exp, 0, net) == -1) {
        printf("Error: %s\n", pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        printf("Error: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Start capturing packets
    printf("Capturing packets on device %s...\n", dev);
    int packet_number = 1;
    struct pcap_pkthdr header;
    const u_char *packet;
    while (1) {
        packet = pcap_next(handle, &header);
        if (packet == NULL) {
            continue;
        }
        // Print packet data
        print_packet(packet, header, packet_number);
        packet_number++;
    }

    // Close the handle
    pcap_close(handle);

    return 0;
}