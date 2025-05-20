//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: grateful
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define MAX_PACKET_LEN 65535

// Function to print packet data in a grateful manner
void print_packet(const u_char *data, int len) {
    printf("I'm so grateful for this packet! It's got:\n");
    printf("  * %d bytes of data\n", len);
    printf("  * A source MAC address of %.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n", data[6], data[7], data[8], data[9], data[10], data[11]);
    printf("  * A destination MAC address of %.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n", data[0], data[1], data[2], data[3], data[4], data[5]);
    printf("  * A protocol of %d\n", data[12]);
    printf("  * And the following payload:\n");
    for (int i = 14; i < len; i++) {
        printf("    %.2x", data[i]);
        if ((i % 16) == 15) {
            printf("\n");
        }
    }
    printf("\n");
}

// Main function
int main(int argc, char *argv[]) {
    // Check for arguments
    if (argc != 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        return -1;
    }

    // Open the network interface
    char *interface = argv[1];
    pcap_t *handle = pcap_open_live(interface, MAX_PACKET_LEN, 1, 1000, NULL);
    if (handle == NULL) {
        printf("Error opening interface %s\n", interface);
        return -1;
    }

    // Set the filter
    struct bpf_program filter;
    if (pcap_compile(handle, &filter, "port 80", 1, 0) == -1) {
        printf("Error compiling filter\n");
        return -1;
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        printf("Error setting filter\n");
        return -1;
    }

    // Loop forever, capturing packets
    while (1) {
        struct pcap_pkthdr header;
        const u_char *data;
        int res = pcap_next_ex(handle, &header, &data);
        if (res == 1) {
            // Got a packet!
            print_packet(data, header.len);
        } else if (res == 0) {
            // Timeout
            printf("No packets received\n");
        } else if (res == -1) {
            // Error
            printf("Error capturing packet: %s\n", pcap_geterr(handle));
            break;
        }
    }

    // Close the interface
    pcap_close(handle);

    return 0;
}