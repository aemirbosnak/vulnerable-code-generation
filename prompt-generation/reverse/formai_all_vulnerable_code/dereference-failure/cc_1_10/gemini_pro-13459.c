//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>

// Function to print the data in a packet
void print_data(const u_char *data, int size) {
    // Loop through the data and print it as hex bytes
    for (int i = 0; i < size; i++) {
        printf("%02x ", data[i]);
    }

    // Print a newline at the end of the line
    printf("\n");
}

// Function to capture packets
void capture_packets(const char *device) {
    // Open the device for capturing packets
    pcap_t *handle = pcap_open_live(device, BUFSIZ, 1, 1000, NULL);

    // Check if the device was opened successfully
    if (handle == NULL) {
        fprintf(stderr, "Error opening device %s: %s\n", device, pcap_geterr(handle));
        return;
    }

    // Set a filter to capture only TCP packets
    const char *filter = "tcp";
    struct bpf_program fp;

    if (pcap_compile(handle, &fp, filter, 0, 0) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        return;
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        return;
    }

    // Start capturing packets
    int packet_count = 0;
    while (1) {
        struct pcap_pkthdr *header;
        const u_char *data;

        // Retrieve the next packet from the capture buffer
        int res = pcap_next_ex(handle, &header, &data);

        // Check if the packet was captured successfully
        if (res == 1) {
            // Print the packet number
            printf("Packet %d:\n", packet_count++);

            // Print the packet header information
            printf("  Timestamp: %s\n", ctime((const time_t *)&header->ts.tv_sec));
            printf("  Length: %d\n", header->len);
            printf("  Capture length: %d\n", header->caplen);

            // Print the packet data
            printf("  Data: ");
            print_data(data, header->caplen);

            // Print a newline at the end of the packet
            printf("\n");
        }
        // Check if there was an error capturing the packet
        else if (res == -1) {
            fprintf(stderr, "Error capturing packet: %s\n", pcap_geterr(handle));
            return;
        }
        // Check if there were no more packets to capture
        else if (res == 0) {
            break;
        }
    }

    // Close the device
    pcap_close(handle);
}

int main(int argc, char **argv) {
    // Check if the device name was specified
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <device>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Capture packets from the specified device
    capture_packets(argv[1]);

    return EXIT_SUCCESS;
}