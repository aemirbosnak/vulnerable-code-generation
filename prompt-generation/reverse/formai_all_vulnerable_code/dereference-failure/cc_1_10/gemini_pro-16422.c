//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: realistic
#include <pcap.h>
#include <stdio.h>
#include <arpa/inet.h>

#define MAX_BYTES_TO_CAPTURE 2048

int main() {
    char *device;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "tcp and port 80";
    bpf_u_int32 net;
    bpf_u_int32 mask;
    struct pcap_pkthdr *header;
    const unsigned char *packet;

    // Find a suitable device
    device = pcap_lookupdev(errbuf);
    if (device == NULL) {
        fprintf(stderr, "pcap_lookupdev: %s\n", errbuf);
        return 1;
    }

    // Get the network address and mask
    if (pcap_lookupnet(device, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "pcap_lookupnet: %s\n", errbuf);
        return 1;
    }

    // Open the device
    handle = pcap_open_live(device, MAX_BYTES_TO_CAPTURE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live: %s\n", errbuf);
        return 1;
    }

    // Compile the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "pcap_compile: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Set the filter
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "pcap_setfilter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Loop through the packets
    while (1) {
        // Wait for a packet
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == 0) {
            continue;
        } else if (res == -1) {
            fprintf(stderr, "pcap_next_ex: %s\n", pcap_geterr(handle));
            return 1;
        }

        // Print the packet header
        printf("Packet length: %d\n", header->len);
        printf("Capture time: %d.%06d\n", header->ts.tv_sec, header->ts.tv_usec);

        // Print the packet data
        printf("Packet data:\n");
        for (int i = 0; i < header->caplen; i++) {
            printf("%02x ", packet[i]);
        }
        printf("\n");
    }

    // Cleanup
    pcap_freealldevs(handle);
    pcap_close(handle);

    return 0;
}