//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main() {
    char *dev = "lo";             // Interface to sniff on
    char *filter_exp = "ip";      // Filter expression
    bpf_u_int32 net, mask;        // Network address and mask
    int promisc = 1;              // Promiscuous mode

    // Open the device for sniffing
    pcap_t *handle = pcap_open_live(dev, 65535, promisc, 1000, NULL);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device %s\n", dev);
        return -1;
    }

    // Compile the filter expression
    struct bpf_program fp;
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Error compiling filter %s\n", filter_exp);
        return -1;
    }

    // Set the filter
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error setting filter %s\n", filter_exp);
        return -1;
    }

    // Loop forever and sniff packets
    while (1) {
        struct pcap_pkthdr *header;
        const u_char *packet;

        // Get the next packet
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == 0) {
            continue;
        } else if (res == -1) {
            fprintf(stderr, "Error getting packet\n");
            return -1;
        }

        // Print the packet length
        printf("Packet length: %d\n", header->len);

        // Print the packet data in a funny way
        printf("Packet data: ");
        for (int i = 0; i < header->len; i++) {
            if (packet[i] < 32 || packet[i] > 126) {
                printf(".");
            } else {
                printf("%c", packet[i]);
            }
        }
        printf("\n");

        // Print the packet timestamp
        printf("Packet timestamp: %ld.%06ld\n", header->ts.tv_sec, header->ts.tv_usec);

        // Print a funny message
        printf("I'm a little packet sniffer, short and stout,\n");
        printf("Here is a packet, it's going about.\n");
        printf("With a hop, skip, and a jump, it's on its way,\n");
        printf("To deliver your data, come what may.\n\n");
    }

    // Close the device
    pcap_close(handle);

    return 0;
}