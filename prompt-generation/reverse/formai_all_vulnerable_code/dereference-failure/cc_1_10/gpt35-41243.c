//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

#define MAX_PACKET_SIZE 65535

void capture_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Received a packet of length %d\n", header->len);
    printf("------------------------\n");

    // Print out the packet data in hexadecimal format
    int i;
    for (i = 0; i < header->len; i++) {
        printf("%02x ", packet[i]);

        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }

    printf("\n\n");
}

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "tcp";
    bpf_u_int32 net;
    bpf_u_int32 mask;
    struct pcap_pkthdr header;
    const u_char *packet;

    // Find out the network and subnet mask
    if (pcap_lookupnet(argv[1], &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Error getting network information: %s\n", errbuf);
        exit(1);
    }

    // Open the device for packet capture
    handle = pcap_open_live(argv[1], MAX_PACKET_SIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", argv[1], errbuf);
        exit(1);
    }

    // Compile the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Failed to compile filter expression: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // Apply the filter
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Failed to set filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // Start capturing packets
    int num_packets = atoi(argv[2]);
    printf("Capturing %d packets...\n", num_packets);
    pcap_loop(handle, num_packets, capture_packet, NULL);

    // Close the capture device and free memory
    pcap_freecode(&fp);
    pcap_close(handle);
    printf("Capture complete.\n");

    return 0;
}