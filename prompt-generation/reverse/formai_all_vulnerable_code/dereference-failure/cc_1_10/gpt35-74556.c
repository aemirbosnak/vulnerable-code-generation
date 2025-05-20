//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

void packet_handler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packetData) {
    printf("Packet Captured\n");
    printf("Packet Length: %d\n", pkthdr->len);
}

int main(int argc, char **argv) {
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // Get the default network device
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        printf("Error finding the default network device: %s", errbuf);
        return 1;
    }

    // Open the device for packet capture
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Error opening device %s: %s", dev, errbuf);
        return 1;
    }

    // Set the BPF filter to filter only TCP packets
    struct bpf_program filter;
    char filter_exp[] = "tcp";
    bpf_u_int32 net;
    if (pcap_compile(handle, &filter, filter_exp, 0, net) == -1) {
        printf("Error compiling filter: %s", pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        printf("Error setting filter: %s", pcap_geterr(handle));
        return 1;
    }

    // Start capturing packets
    printf("Starting Packet Capture\n");
    pcap_loop(handle, -1, packet_handler, NULL);

    // Close the capture handle and free the device string
    pcap_close(handle);
    free(dev);

    return 0;
}