//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: lively
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>

// Convert the timestamp to a human-readable format
void print_timestamp(const struct timeval *tv) {
    char buf[32];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&tv->tv_sec));
    printf("%s.%06ld ", buf, tv->tv_usec);
}

// Print the packet contents in a human-readable format
void print_packet(const u_char *packet, const struct pcap_pkthdr *header) {
    // Print the timestamp
    printf("Timestamp: ");
    print_timestamp(&header->ts);

    // Print the packet length
    printf("Length: %d bytes\n", header->len);

    // Print the packet contents
    printf("Contents: ");
    for (int i = 0; i < header->len; i++) {
        printf("%02x ", packet[i]);
    }
    printf("\n");
}

// The main function
int main() {
    // Open the network interface
    char *dev = pcap_lookupdev(NULL);
    if (dev == NULL) {
        fprintf(stderr, "Could not find a network interface\n");
        return -1;
    }

    // Create a packet capture handle
    pcap_t *handle = pcap_open_live(dev, BUFSIZ, 1, 1000, NULL);
    if (handle == NULL) {
        fprintf(stderr, "Could not open the network interface\n");
        return -1;
    }

    // Start the packet capture loop
    while (1) {
        // Wait for a packet
        struct pcap_pkthdr *header;
        const u_char *packet;
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == -1) {
            fprintf(stderr, "Error while capturing packets\n");
            break;
        } else if (res == 0) {
            // No packets were captured
            continue;
        }

        // Print the packet
        print_packet(packet, header);
    }

    // Close the packet capture handle
    pcap_close(handle);

    return 0;
}