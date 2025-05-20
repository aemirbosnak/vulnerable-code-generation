//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: energetic
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

// Function to print the packet data
void print_packet_data(u_char *data, int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%02x ", (int)data[i]);
    }
    printf("\n");
}

// Function to handle the captured packets
void packet_handler(u_char *data, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet received:\n");
    print_packet_data(packet, header->len);
}

// Main function
int main() {
    char device_name[100] = "eth0";
    char filter_expression[100] = "tcp or udp";
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program filter;

    // Open the device for packet capture
    handle = pcap_open_live(device_name, 65535, 1, 0, errbuf);
    if (handle == NULL) {
        printf("Error: %s\n", errbuf);
        return 1;
    }

    // Compile the filter expression
    if (pcap_compile(handle, &filter, filter_expression, 0, 0) < 0) {
        printf("Error: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Set the filter for the device
    if (pcap_setfilter(handle, &filter) < 0) {
        printf("Error: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Loop to capture packets
    while (1) {
        struct pcap_pkthdr *header;
        const u_char *packet;

        // Capture a packet
        packet = pcap_next(handle, &header);

        // Check if a packet was captured
        if (packet == NULL) {
            printf("No packet received.\n");
            continue;
        }

        // Call the packet handler function
        packet_handler(packet, header, packet);
    }

    // Close the device
    pcap_close(handle);

    return 0;
}