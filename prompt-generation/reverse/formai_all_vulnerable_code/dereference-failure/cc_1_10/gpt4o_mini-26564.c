//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>

#define SNAP_LEN 1518 // Maximum number of bytes to capture from each packet
#define DEFAULT_COUNT 100 // Default number of packets to capture

// Function to print the packet data in hex format
void print_packet(const u_char *packet, struct pcap_pkthdr header) {
    int i;
    printf("\nPacket Length: %d\n", header.len);
    for (i = 0; i < header.len; i++) {
        if (i % 16 == 0) {
            printf("\n");
        }
        printf("%02x ", packet[i]);
    }
    printf("\n");
}

// Packet handler callback function
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    int count = *((int *)args);
    if (count > 0) {
        print_packet(packet, *header);
        (*((int *)args))--;
    }
}

// Function to start packet capturing
void start_capture(char *interface, int packet_count) {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    // Open the device for packet capture
    handle = pcap_open_live(interface, SNAP_LEN, 1, 1000, errbuf);
    
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", interface, errbuf);
        exit(EXIT_FAILURE);
    }

    // Start packet capture
    int res = pcap_loop(handle, packet_count, packet_handler, (u_char *)&packet_count);
    
    if (res < 0) {
        fprintf(stderr, "Error capturing packets: %s\n", pcap_geterr(handle));
    }

    // Close the pcap handle
    pcap_close(handle);
}

// Main function with configurable options
int main(int argc, char *argv[]) {
    char *interface = NULL;
    int packet_count = DEFAULT_COUNT;

    if (argc > 1) {
        interface = argv[1]; // First argument is the interface
        if (argc > 2) {
            packet_count = atoi(argv[2]); // Second argument is the number of packets to capture
        }
    } else {
        fprintf(stderr, "Usage: %s <interface> [packet_count]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Monitoring interface: %s\n", interface);
    printf("Capturing %d packets...\n", packet_count);
    
    start_capture(interface, packet_count);
    
    printf("Packet capture complete.\n");
    return 0;
}