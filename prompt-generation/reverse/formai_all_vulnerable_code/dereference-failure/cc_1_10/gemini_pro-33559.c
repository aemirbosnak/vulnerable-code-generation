//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_BYTES 2048

int main(int argc, char *argv[]) {
    char *device;
    char *filter;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    struct pcap_pkthdr header;
    const u_char *packet;

    // Get the device name from the user.
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <device name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    device = argv[1];

    // Open the device.
    handle = pcap_open_live(device, MAX_BYTES, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // Compile the filter.
    filter = "udp and port 80";
    if (pcap_compile(handle, &fp, filter, 0, 0) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Set the filter.
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Capture packets.
    while (1) {
        packet = pcap_next(handle, &header);
        if (packet == NULL) {
            fprintf(stderr, "Error capturing packet: %s\n", pcap_geterr(handle));
            exit(EXIT_FAILURE);
        }

        // Print the packet.
        printf("Packet length: %d\n", header.len);
        printf("Source IP: %s\n", inet_ntoa(*(struct in_addr *)packet));
        printf("Destination IP: %s\n", inet_ntoa(*(struct in_addr *)(packet + 16)));
        printf("Source Port: %d\n", *(unsigned short *)(packet + 20));
        printf("Destination Port: %d\n", *(unsigned short *)(packet + 22));
        printf("Data: %s\n", packet + 28);
        printf("\n");
    }

    // Close the device.
    pcap_close(handle);

    return EXIT_SUCCESS;
}