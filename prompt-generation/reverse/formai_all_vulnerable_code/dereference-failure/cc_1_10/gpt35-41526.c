//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main(int argc, char **argv)
{
    char *device; // pointer to the device we want to sniff on
    char error_buffer[PCAP_ERRBUF_SIZE]; // buffer to store errors
    pcap_t *handle; // handle to the packet capture session
    int snapshot_length = 1024; // amount of data to capture in each packet
    int promiscuous = 1; // set to 1 to capture all packets, including those not addressed to this machine
    int timeout = 1000; // time to wait for packets (in milliseconds)
    struct pcap_pkthdr packet_header; // header that describes captured packet
    const u_char *packet_data; // pointer to packet data

    // Get the name of the device we want to sniff on
    device = pcap_lookupdev(error_buffer);
    if (device == NULL) {
        fprintf(stderr, "Could not find default device: %s\n", error_buffer);
        return 2;
    }

    // Open the device in promiscuous mode
    handle = pcap_open_live(device, snapshot_length, promiscuous, timeout, error_buffer);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device, error_buffer);
        return 2;
    }

    // Start capturing packets
    printf("Packet Capturer started on: %s\n", device);
    printf("Capturing packets...\n");
    while (1) {
        packet_data = pcap_next(handle, &packet_header);
        fprintf(stdout, "Packet Captured: %d bytes\n", packet_header.len);
        /* print packet */
        for (int i = 0; i < packet_header.len; i++) {
            printf("%02x", packet_data[i]);
            if (i % 16 == 15 || i == packet_header.len - 1) {
                printf("\n");
            } else if (i % 8 == 7) {
                printf(" ");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }

    // Clean up
    pcap_close(handle);

    return 0;
}