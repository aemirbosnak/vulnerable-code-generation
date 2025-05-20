//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: intelligent
#include <stdlib.h>
#include <stdio.h>
#include <pcap.h>
#include <signal.h>

#define MAX_PACKET_SIZE 65535

// Function to handle Ctrl-C signal
void handle_ctrl_c(int signal) {
    printf("\nCtrl-C pressed. Stopping packet capture...\n");
    exit(0);
}

int main(int argc, char *argv[]) {
    char *device;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr header;
    const u_char *packet;

    // Register Ctrl-C signal handler
    signal(SIGINT, handle_ctrl_c);

    // Get the device name from the command line arguments
    if (argc != 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }
    device = argv[1];

    // Open the device for packet capture
    handle = pcap_open_live(device, MAX_PACKET_SIZE, 0, 1000, errbuf);
    if (handle == NULL) {
        printf("Error opening device: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Start the packet capture loop
    while (1) {
        // Wait for a packet to arrive
        packet = pcap_next(handle, &header);
        if (packet == NULL) {
            // Timeout occurred
            continue;
        }

        // Print the packet information
        printf("Packet received: %d bytes\n", header.len);
        for (int i = 0; i < header.len; i++) {
            printf("%02X ", packet[i]);
        }
        printf("\n\n");
    }

    // Close the device and exit
    pcap_close(handle);
    return EXIT_SUCCESS;
}