//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>

// Define a callback function that is called whenever a packet is captured
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // Printing packet length and capture length
    printf("Packet Length: %d bytes\n", header->len);
    printf("Capture Length: %d bytes\n", header->caplen);
    
    // Just displaying a part of the packet
    printf("Packet Data (first 16 bytes): ");
    for (int i = 0; i < 16 && i < header->caplen; i++) {
        printf("%02x ", packet[i]);
    }
    printf("\n\n");
}

int main(int argc, char *argv[]) {
    pcap_if_t *alldevs;
    pcap_if_t *device;
    char errbuf[PCAP_ERRBUF_SIZE];
    
    // Check for interface name as a command line argument
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    // Finding all available devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Search for the specified device
    for (device = alldevs; device != NULL; device = device->next) {
        if (strcmp(device->name, argv[1]) == 0) {
            break;
        }
    }

    // If device not found
    if (device == NULL) {
        fprintf(stderr, "Device %s not found.\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Opening the device for packet capturing
    pcap_t *handle = pcap_open_live(device->name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device->name, errbuf);
        return EXIT_FAILURE;
    }

    printf("Listening on %s...\n", device->name);

    // Start capturing packets
    pcap_loop(handle, 10, packet_handler, NULL);

    // Cleanup
    pcap_close(handle);
    pcap_freealldevs(alldevs);

    return EXIT_SUCCESS;
}