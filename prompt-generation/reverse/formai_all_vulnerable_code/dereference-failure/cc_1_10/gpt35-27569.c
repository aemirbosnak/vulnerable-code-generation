//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

#define MAX_PACKET_SIZE 65535

int main(int argc, char *argv[]) {
    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 mask;
    bpf_u_int32 net;
    u_char packet[MAX_PACKET_SIZE];
    struct pcap_pkthdr *header;
    const u_char *data;

    // Find a suitable network interface to capture packets from
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return 1;
    }

    // Open the network interface in promiscuous mode
    handle = pcap_open_live(dev, MAX_PACKET_SIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 1;
    }

    // Compile the filter expression to capture the packets we want
    // In this example, we capture all TCP traffic on port 80 (HTTP)
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }
    if (pcap_compile(handle, &fp, "tcp port 80", 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter expression: %s\n", pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Start capturing packets and print out their contents
    while (pcap_next_ex(handle, &header, &data) >= 0) {
        printf("Packet captured, length = %d bytes\n", header->caplen);
        printf("Data:\n");
        for (int i = 0; i < header->caplen; i++) {
            printf("%02x ", data[i]);
            if ((i + 1) % 16 == 0) printf("\n");
        }
        printf("\n\n");
    }

    // Close the network interface
    pcap_close(handle);
    return 0;
}