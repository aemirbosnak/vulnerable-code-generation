//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: unmistakable
// Ethan's Network Packet Monitoring Extravaganza

#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

// Main function - the orchestra conductor
int main(int argc, char **argv) {
    // Check if we have enough arguments - we're a needy program
    if (argc < 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        return -1;
    }

    // Capture the interface - the stage we'll perform on
    char *interface = argv[1];

    // Open the device - let's get this show on the road
    pcap_t *handle = pcap_open_live(interface, BUFSIZ, 1, 1000, NULL);
    if (handle == NULL) {
        printf("Error opening device %s\n", interface);
        return -1;
    }

    // Compile the filter - the script for our performance
    struct bpf_program fp;
    if (pcap_compile(handle, &fp, "tcp and port 80", 1, 0) == -1) {
        printf("Error compiling filter\n");
        return -1;
    }

    // Set the filter - time to focus on the good stuff
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Error setting filter\n");
        return -1;
    }

    // Packet loop - the grand finale
    while (1) {
        struct pcap_pkthdr *header;
        const u_char *data;

        // Capture a packet - the moment we've been waiting for
        int res = pcap_next_ex(handle, &header, &data);

        // Check if there was an error or we reached the end
        if (res == -1) {
            printf("Error capturing packet\n");
            break;
        } else if (res == 0) {
            continue;
        }

        // Print packet info - the curtain call
        printf("Packet captured on %s\n", interface);
        printf("Length: %d\n", header->len);
        printf("Data: ");
        for (int i = 0; i < header->len; i++) {
            printf("%02x", data[i]);
        }
        printf("\n\n");
    }

    // Cleanup - don't leave a mess
    pcap_close(handle);
    return 0;
}