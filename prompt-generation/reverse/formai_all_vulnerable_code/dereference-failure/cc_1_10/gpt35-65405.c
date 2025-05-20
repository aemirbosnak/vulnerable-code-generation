//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: real-life
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet captured of length: %d\n", header->len);
}

int main(int argc, char *argv[]) {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Open pcap session on default interface or input file
    if (argc == 2) {
        handle = pcap_open_offline(argv[1], errbuf);
        if (handle == NULL) {
            fprintf(stderr, "Error opening input file: %s\n", errbuf);
            return 1;
        }
        printf("Reading from input file: %s\n", argv[1]);
    } else {
        handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
        if (handle == NULL) {
            fprintf(stderr, "Error opening pcap session on eth0: %s\n", errbuf);
            return 1;
        }
        printf("Listening on default interface: eth0\n");
    }

    // Set filter expression
    struct bpf_program filter;
    char filter_exp[] = "tcp port 80";
    if (pcap_compile(handle, &filter, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Begin capturing packets
    int num_packets = 10;
    if (argc >= 3) {
        num_packets = atoi(argv[2]);
    }
    printf("Capturing %d packets...\n", num_packets);
    pcap_loop(handle, num_packets, packet_handler, NULL);

    // Cleanup
    pcap_freecode(&filter);
    pcap_close(handle);
    printf("Done.\n");
    return 0;
}