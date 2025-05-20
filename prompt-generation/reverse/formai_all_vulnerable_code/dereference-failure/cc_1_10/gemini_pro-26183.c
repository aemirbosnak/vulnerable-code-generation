//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: modular
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

// Define the packet capture loop module
void packet_capture_loop(pcap_t *handle, int num_packets) {
    int packet_count = 0;
    struct pcap_pkthdr *header;
    const u_char *data;

    while (packet_count < num_packets) {
        if (pcap_next_ex(handle, &header, &data) == 1) {
            // Process the packet here
            packet_count++;
        } else {
            // Handle errors
        }
    }
}

// Define the packet initialization module
pcap_t *init_packet_capture(char *device, char* filter, int snaplen) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // Open the device
    handle = pcap_open_live(device, snaplen, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        return NULL;
    }

    // Compile the filter
    struct bpf_program fp;
    if (pcap_compile(handle, &fp, filter, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        return NULL;
    }

    // Set the filter
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        return NULL;
    }

    return handle;
}

// Define the main function
int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <device> <filter> <num_packets>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Initialize the packet capture
    pcap_t *handle = init_packet_capture(argv[1], argv[2], 65535);
    if (handle == NULL) {
        return EXIT_FAILURE;
    }

    // Capture the packets
    packet_capture_loop(handle, atoi(argv[3]));

    // Close the handle
    pcap_close(handle);

    return EXIT_SUCCESS;
}