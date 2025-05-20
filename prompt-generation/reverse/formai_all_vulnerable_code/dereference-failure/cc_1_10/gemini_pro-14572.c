//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pcap.h>

// Maximum number of packets to capture
#define MAX_PACKETS 100

// Function to print the packet information
void print_packet_info(const u_char *packet, int len) {
    // Get the packet header
    struct pcap_pkthdr *header = (struct pcap_pkthdr *) packet;

    // Get the packet data
    const u_char *data = packet + header->caplen;

    // Print the packet information
    printf("Packet length: %d\n", header->len);
    printf("Packet capture time: %s\n", ctime((const time_t *) &header->ts.tv_sec));
    printf("Packet data:\n");
    for (int i = 0; i < len; i++) {
        printf("%02x ", data[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n\n");
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has provided an interface to capture packets from
    if (argc != 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        return -1;
    }

    // Get the interface to capture packets from
    char *interface = argv[1];

    // Open the interface for packet capture
    pcap_t *handle = pcap_open_live(interface, 65535, 1, 1000, NULL);
    if (handle == NULL) {
        printf("Error opening interface %s\n", interface);
        return -1;
    }

    // Create a packet filter
    struct bpf_program filter;
    if (pcap_compile(handle, &filter, "ip", 1, 0) == -1) {
        printf("Error compiling filter\n");
        return -1;
    }

    // Set the filter on the interface
    if (pcap_setfilter(handle, &filter) == -1) {
        printf("Error setting filter\n");
        return -1;
    }

    // Capture packets
    int count = 0;
    while (count < MAX_PACKETS) {
        // Get the next packet
        struct pcap_pkthdr *header;
        const u_char *packet;
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == 0) {
            continue;
        } else if (res == -1) {
            printf("Error capturing packet\n");
            return -1;
        }

        // Print the packet information
        print_packet_info(packet, header->caplen);

        // Increment the packet count
        count++;
    }

    // Close the interface
    pcap_close(handle);

    return 0;
}