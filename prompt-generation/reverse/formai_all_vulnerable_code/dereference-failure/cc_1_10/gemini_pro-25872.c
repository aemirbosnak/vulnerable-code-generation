//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: introspective
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "port 80";
    bpf_u_int32 mask;
    bpf_u_int32 net;

    // Get the device
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Error: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Get the network and mask
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Error: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Open the device
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Compile the filter
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Set the filter
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Capture the packets
    while (1) {
        struct pcap_pkthdr *header;
        const u_char *packet;

        int res = pcap_next_ex(handle, &header, &packet);
        if (res == 0) {
            continue;
        } else if (res == -1) {
            fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
            return EXIT_FAILURE;
        }

        // Process the packet
        printf("Packet length: %d\n", header->len);
        printf("Packet data:\n");
        for (int i = 0; i < header->len; i++) {
            printf("%02x ", packet[i]);
        }
        printf("\n");
    }

    // Close the device
    pcap_close(handle);

    return EXIT_SUCCESS;
}