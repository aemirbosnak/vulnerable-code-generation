//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>
#include <arpa/inet.h>

#define SNAPLEN 65535
#define MAX_PACKET_SIZE 2048
#define TRUE 1
#define FALSE 0

typedef struct {
    u_char *data;
    size_t size;
} PacketData;

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Received a packet of size %d bytes\n", header->len);
    printf("Packet data: ");
    for (int i = 0; i < header->len; i++) {
        printf("%02X ", packet[i]);
    }
    printf("\n");
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *pcap_handle;
    char *dev = "eth0";
    char filter_str[20] = "tcp or udp";
    struct bpf_program filter;

    // Open the session in promiscuous mode
    pcap_handle = pcap_open_live(dev, SNAPLEN, 1, 0, errbuf);
    if (pcap_handle == NULL) {
        printf("Error opening session: %s\n", errbuf);
        exit(1);
    }

    // Compile the filter expression
    if (pcap_compile(pcap_handle, &filter, filter_str, 0, 0) == -1) {
        printf("Error compiling filter: %s\n", pcap_geterr(pcap_handle));
        exit(1);
    }

    // Set the filter
    if (pcap_setfilter(pcap_handle, &filter) == -1) {
        printf("Error setting filter: %s\n", pcap_geterr(pcap_handle));
        exit(1);
    }

    // Loop to capture packets
    PacketData packet_data;
    while (TRUE) {
        struct pcap_pkthdr header;
        const u_char *packet = pcap_next(pcap_handle, &header);
        if (packet == NULL) {
            printf("No packets captured\n");
            break;
        }
        // Check if the packet matches the filter
        if (pcap_offline_filter(&filter, &header, packet) == 0) {
            process_packet(NULL, &header, packet);
        }
    }

    // Close the session
    pcap_close(pcap_handle);
    return 0;
}