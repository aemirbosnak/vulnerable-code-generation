//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: secure
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BYTES_PER_PACKET 2048

// Function to print the data in a packet
void print_packet(u_char *user, const struct pcap_pkthdr *h, const u_char *bytes) {
    // Get the timestamp of the packet
    printf("Timestamp: %s\n", ctime((const time_t *) &h->ts.tv_sec));

    // Get the length of the packet
    printf("Length: %d\n", h->len);

    // Print the data in the packet
    printf("Data: ");
    for (int i = 0; i < h->len; i++) {
        printf("%02x ", bytes[i]);
    }
    printf("\n\n");
}

// Function to capture packets
void capture_packets(char *device) {
    // Open the device for capturing
    pcap_t *handle = pcap_open_live(device, MAX_BYTES_PER_PACKET, 1, 1000, NULL);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device %s: %s\n", device, pcap_geterr(handle));
        exit(1);
    }

    // Start the capture loop
    while (1) {
        // Wait for a packet to arrive
        struct pcap_pkthdr *header;
        const u_char *bytes;
        int res = pcap_next_ex(handle, &header, &bytes);
        if (res == 0) continue;
        if (res == -1) {
            fprintf(stderr, "Error capturing packet: %s\n", pcap_geterr(handle));
            break;
        }

        // Print the packet
        print_packet(NULL, header, bytes);
    }

    // Close the device
    pcap_close(handle);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has specified a device
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <device>\n", argv[0]);
        exit(1);
    }

    // Capture packets from the specified device
    capture_packets(argv[1]);

    return 0;
}