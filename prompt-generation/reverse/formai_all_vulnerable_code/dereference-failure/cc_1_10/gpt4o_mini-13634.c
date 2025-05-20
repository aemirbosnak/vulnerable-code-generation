//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <arpa/inet.h>

// Structure to hold packet data for analysis
typedef struct {
    const u_char *data;
    struct pcap_pkthdr header;
} PacketData;

// Function to parse the packet data and print basic information
void parse_packet(PacketData *packet) {
    printf("Packet Length: %d\n", packet->header.len);
    printf("Captured Length: %d\n", packet->header.caplen);
    
    // Example of printing first 16 bytes of packet data in hex format
    printf("Packet Data (first 16 bytes): ");
    for (int i = 0; i < 16 && i < packet->header.caplen; i++) {
        printf("%02x ", packet->data[i]);
    }
    printf("\n\n");
}

// Packet capture callback function
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    PacketData *pd = (PacketData *) args;

    // Fill the PacketData structure
    pd->data = packet;
    pd->header = *header;

    // Parse and print the packet information
    parse_packet(pd);
}

// Main capture function
void capture_packets(const char *device) {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    
    // Open the device for packet capturing
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device, errbuf);
        return;
    }

    // Create a PacketData object to hold packet information
    PacketData pd;

    // Start capturing packets
    printf("Starting packet capture on device: %s\n", device);
    pcap_loop(handle, 10, packet_handler, (u_char *) &pd);

    // Close the pcap handle
    pcap_close(handle);
    printf("Finished packet capture.\n");
}

// Function to list available devices for capturing
void list_devices() {
    pcap_if_t *alldevs, *device;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Find all available devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return;
    }

    printf("Available devices:\n");
    for (device = alldevs; device != NULL; device = device->next) {
        printf("- %s\n", device->name);
    }

    pcap_freealldevs(alldevs);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <device_name>\n", argv[0]);
        list_devices();
        return EXIT_FAILURE;
    }

    const char *device_name = argv[1];
    capture_packets(device_name);

    return EXIT_SUCCESS;
}