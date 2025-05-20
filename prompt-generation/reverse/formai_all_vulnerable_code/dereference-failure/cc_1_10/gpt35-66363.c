//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "port 80";
    bpf_u_int32 net;
    const unsigned char *packet;
    struct pcap_pkthdr header;
    int res;

    // Open the default network interface for capturing
    handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", argv[1], errbuf);
        return 1;
    }

    // Compile the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    // Set the filter
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    // Capture packets
    while ((res = pcap_next_ex(handle, &header, &packet)) >= 0) {
        if (res == 0)
            // Timeout expired
            continue;

        printf("Packet length %d\n", header.len);
        for (int i = 0; i < header.len; i++)
            printf("%02x ", packet[i]);
        printf("\n");
    }

    // Clean up
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}