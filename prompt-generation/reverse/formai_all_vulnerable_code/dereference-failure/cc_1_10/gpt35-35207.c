//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <time.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>

int main(int argc, char *argv[]) {
    char *device; // The network device to capture packets on
    char error_buffer[PCAP_ERRBUF_SIZE]; // Error buffer for pcap functions
    pcap_t *handle; // Packet capture handle
    struct pcap_pkthdr header; // Packet metadata
    const uint8_t *packet; // Packet data
    time_t timestamp; // Current timestamp
    struct tm *now; // Current time

    // Find the default network device to capture packets on
    device = pcap_lookupdev(error_buffer);
    if (device == NULL) {
        fprintf(stderr, "Error: %s\n", error_buffer);
        exit(EXIT_FAILURE);
    }

    // Open the network device for packet capture
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, error_buffer);
    if (handle == NULL) {
        fprintf(stderr, "Error: %s\n", error_buffer);
        exit(EXIT_FAILURE);
    }

    // Loop through packets and print their data and metadata
    while (1) {
        packet = pcap_next(handle, &header);
        if (packet == NULL) {
            continue;
        }

        // Get the current timestamp and convert it to human-readable format
        timestamp = header.ts.tv_sec;
        now = localtime(&timestamp);

        // Print the packet metadata and header data
        printf("Packet captured on %02d/%02d/%4d at %02d:%02d:%02d.%06d\n",
            now->tm_mday, now->tm_mon + 1, now->tm_year + 1900, now->tm_hour, now->tm_min, now->tm_sec, header.ts.tv_usec);
        printf("Packet length: %d bytes\n", header.len);

        // Print the packet data in hexadecimal and ASCII format
        for (int i = 0; i < header.len; i++) {
            if (i % 16 == 0) {
                printf("\n%04x: ", i);
            }
            printf("%02x ", packet[i]);
        }
        printf("\n");
    }

    // Close the packet capture handle
    pcap_close(handle);
    return 0;
}