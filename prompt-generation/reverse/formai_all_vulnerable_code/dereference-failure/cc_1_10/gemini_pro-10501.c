//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: multivariable
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    char *device;
    char *filter;
    int snaplen;
    int promisc;
    int timeout;
    pcap_t *handle;
    struct bpf_program fp;
    struct pcap_pkthdr *header;
    const u_char *packet;
    int ret;
    int i;

    if (argc < 6) {
        fprintf(stderr, "Usage: %s <device> <filter> <snaplen> <promisc> <timeout>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    device = argv[1];
    filter = argv[2];
    snaplen = atoi(argv[3]);
    promisc = atoi(argv[4]);
    timeout = atoi(argv[5]);

    // Open the device
    handle = pcap_open_live(device, snaplen, promisc, timeout, NULL);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live(): %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Compile the filter
    if (pcap_compile(handle, &fp, filter, 0, 0) == -1) {
        fprintf(stderr, "pcap_compile(): %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Set the filter
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "pcap_setfilter(): %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Capture packets
    while ((ret = pcap_next_ex(handle, &header, &packet)) >= 0) {
        if (ret == 1) {
            // Print the packet
            printf("Packet length: %d\n", header->len);
            for (i = 0; i < header->len; i++) {
                printf("%02x ", packet[i]);
            }
            printf("\n");
        } else if (ret == 0) {
            // Timeout
            fprintf(stderr, "Timeout\n");
        } else {
            // Error
            fprintf(stderr, "pcap_next_ex(): %s\n", pcap_geterr(handle));
        }
    }

    // Close the device
    pcap_close(handle);

    return 0;
}