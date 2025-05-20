//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

// Interface and filter to capture packets
#define INTERFACE "eth0"
#define FILTER "port 80"

// Function to print packet information
void print_packet_info(const u_char *packet, struct pcap_pkthdr packet_header) {
    printf("Packet Capture Length: %d\n", packet_header.caplen);
    printf("Packet Length: %d\n", packet_header.len);

    for (int i = 0; i < packet_header.caplen; i++) {
        printf("%02x ", packet[i]); // Print the packet data in hexadecimal format
        if ( (i % 16 == 15 && i != 0) || i == packet_header.caplen - 1)
            printf("\n"); // Print new line and start a new row after 16 bytes
    }

    printf("\n");
}

int main() {
    char error_buffer[PCAP_ERRBUF_SIZE]; // Buffer to store any error message
    int timeout_limit = 10000; // Timeout limit to capture packets in milliseconds

    // Open live capture session on the specified interface
    pcap_t *pcap_handle = pcap_open_live(INTERFACE, BUFSIZ, 0, timeout_limit, error_buffer);
    if (!pcap_handle) {
        printf("Error opening the pcap handle: %s\n", error_buffer);
        exit(1);
    }

    // Compile and apply the filter to capture packets
    struct bpf_program filter;
    if (pcap_compile(pcap_handle, &filter, FILTER, 0, 0) == -1) {
        printf("Error compiling the filter: %s\n", pcap_geterr(pcap_handle));
        exit(1);
    }
    if (pcap_setfilter(pcap_handle, &filter) == -1) {
        printf("Error setting the filter: %s\n", pcap_geterr(pcap_handle));
        exit(1);
    }

    // Capture next packet and print the information
    struct pcap_pkthdr packet_header; // Packet header metadata
    const u_char *packet; // Packet data
    while ((packet = pcap_next(pcap_handle, &packet_header))) {
        printf("\nPacket Received:\n");
        print_packet_info(packet, packet_header);
    }

    pcap_close(pcap_handle); // Close the pcap handle

    return 0;
}