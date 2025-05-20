//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>

#define SNAP_LEN 1518  // max number of bytes to capture

// Callback function invoked by pcap for each captured packet
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    const struct ip *ip_header;
    ip_header = (struct ip*)(packet + 14); // Skip Ethernet header (14 bytes)

    // Print the packet length and source, destination IP
    printf("Packet Length: %d bytes\n", header->len);
    printf("Source IP: %s\n", inet_ntoa(ip_header->ip_src));
    printf("Destination IP: %s\n", inet_ntoa(ip_header->ip_dst));

    // Print a portion of the payload
    printf("Packet Payload: ");
    for(int i = 0; i < 16 && i + 14 + sizeof(struct ip) < header->len; ++i) {
        printf("%02x ", packet[i + 14 + sizeof(struct ip)]);
    }
    printf("\n\n");
}

// main function to set up packet capture
int main(int argc, char *argv[]) {
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Check for a device name argument
    if (argc != 2) {
        printf("Usage: %s <device>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the list of all available devices
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

    // No such device found
    if (device == NULL) {
        fprintf(stderr, "No device found with name %s\n", argv[1]);
        pcap_freealldevs(alldevs);
        return EXIT_FAILURE;
    }

    // Open the device for capturing
    handle = pcap_open_live(device->name, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Cannot open device %s: %s\n", device->name, errbuf);
        pcap_freealldevs(alldevs);
        return EXIT_FAILURE;
    }

    printf("Listening on %s...\n", device->name);

    // Start capturing packets
    pcap_loop(handle, 0, packet_handler, NULL);

    // Clean up
    pcap_freealldevs(alldevs);
    pcap_close(handle);
    return EXIT_SUCCESS;
}