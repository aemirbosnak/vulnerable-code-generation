//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <stdbool.h>
#include <string.h>

#define MAX_BYTES 1024

// Custom struct to hold packet data
typedef struct _packet_data {
    int packet_number;
    struct pcap_pkthdr header;
    const u_char *packet_data;
} packet_data;

// Callback function to handle captured packets
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // Cast the args pointer back to the packet_data struct
    packet_data *data = (packet_data *)args;

    // Increment the packet number
    data->packet_number++;

    // Print packet number, timestamp, and packet length
    printf("Packet %d received at %s, length %d bytes\n", data->packet_number, ctime(&header->ts.tv_sec), header->len);

    // Print the first 128 bytes of the packet data (if available)
    if (header->len < MAX_BYTES) {
        printf("Packet data: %s\n\n", (char *)packet);
    } else {
        printf("Packet data too large to print.\n\n");
    }
}

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <interface> <number of packets>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the network interface
    char *device = argv[1];

    // Open the network interface for packet capture
    pcap_t *handle = pcap_open_live(device, BUFSIZ, 0, 1000, NULL);
    if (handle == NULL) {
        fprintf(stderr, "Error opening %s: %s\n", device, pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Set the filter to capture all packets
    char filter_exp[] = "";
    struct bpf_program filter;
    if (pcap_compile(handle, &filter, filter_exp, 0, 0) != 0) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    if (pcap_setfilter(handle, &filter) != 0) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the packet data struct
    packet_data data;
    data.packet_number = 0;

    // Capture packets using a loop
    int num_packets = atoi(argv[2]);
    int count = 0;
    while (count < num_packets) {
        int status = pcap_loop(handle, 1, packet_handler, (u_char *)&data);
        if (status == -1) {
            fprintf(stderr, "Error capturing packets: %s\n", pcap_geterr(handle));
            exit(EXIT_FAILURE);
        }
        count++;
    }

    // Clean up
    pcap_close(handle);
    return EXIT_SUCCESS;
}