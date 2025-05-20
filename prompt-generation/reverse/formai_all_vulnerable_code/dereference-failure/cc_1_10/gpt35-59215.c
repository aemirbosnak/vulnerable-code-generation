//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: realistic
#include <stdio.h>
#include <pcap.h>

#define BUFFER_SIZE 2048

int main(int argc, char **argv) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    const u_char *packet;
    struct pcap_pkthdr header;
    struct bpf_program filter;
    char filter_exp[] = "port 80";
    bpf_u_int32 mask;
    bpf_u_int32 net;
    int num_packets = 0;
    
    // Check if enough arguments are given
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [PCAP_FILE]\n", argv[0]);
        return 1;
    }

    // Open pcap capture file
    if ((handle = pcap_open_offline(argv[1], errbuf)) == NULL) {
        fprintf(stderr, "Error opening file: %s\n", errbuf);
        return 1;
    }

    // Compile and apply filter
    if (pcap_lookupnet(argv[1], &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Error looking up netmask: %s\n", errbuf);
        return 1;
    }
    if (pcap_compile(handle, &filter, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Loop over captured packets
    while ((packet = pcap_next(handle, &header)) != NULL) {
        printf("Packet #%d\n", ++num_packets);
        printf("  Length: %d bytes\n", header.len);
        printf("  Captured at: %s", ctime((const time_t *)&header.ts.tv_sec));
        
        // Print packet contents
        int i;
        for (i = 0; i < header.len; i++) {
            printf("%02x ", packet[i]);
            if ((i+1) % 16 == 0) printf("\n");
        }
        printf("\n\n");
    }

    // Close pcap handle
    pcap_close(handle);

    return 0;
}