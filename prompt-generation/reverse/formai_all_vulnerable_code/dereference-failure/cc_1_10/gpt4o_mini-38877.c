//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

#define MAX_PACKET_SIZE 65536

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // Increment packet count in user data
    int *packet_count = (int *)args;
    (*packet_count)++;

    // Print packet count
    printf("Packet Count: %d\n", *packet_count);

    // Capture timestamp
    struct tm *lt;
    char time_string[64];
    time_t local_tv_sec = header->ts.tv_sec;
    lt = localtime(&local_tv_sec);
    strftime(time_string, sizeof time_string, "%Y-%m-%d %H:%M:%S", lt);
    
    // Print timestamp
    printf("Timestamp: %s.%06ld\n", time_string, header->ts.tv_usec);
    
    // Print packet length
    printf("Packet Length: %d bytes\n", header->len);
    
    // Print first 16 bytes of packet data
    printf("Packet Data:\n");
    for (int i = 0; i < (header->len > 16 ? 16 : header->len); i++) {
        printf("%02x ", packet[i]);
    }
    printf("\n\n");
}

void error_handler(const char *error_message) {
    fprintf(stderr, "Error: %s\n", error_message);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    pcap_if_t *interfaces, *temp;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Check for interface argument
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface_name>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get network devices list
    if (pcap_findalldevs(&interfaces, errbuf) == -1) {
        error_handler(errbuf);
    }

    // Search for the specified interface
    for (temp = interfaces; temp != NULL; temp = temp->next) {
        if (strcmp(temp->name, argv[1]) == 0) {
            break;
        }
    }

    // If no matching interface is found
    if (temp == NULL) {
        fprintf(stderr, "No such interface: %s\n", argv[1]);
        pcap_freealldevs(interfaces);
        return EXIT_FAILURE;
    }

    // Open the device for packet capture
    handle = pcap_open_live(temp->name, MAX_PACKET_SIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        error_handler(errbuf);
    }

    // Initialize packet count
    int packet_count = 0;

    // Start capturing packets
    printf("Capturing on %s...\n", temp->name);
    pcap_loop(handle, 0, packet_handler, (u_char *)&packet_count);

    // Clean up
    pcap_freealldevs(interfaces);
    pcap_close(handle);
    return EXIT_SUCCESS;
}