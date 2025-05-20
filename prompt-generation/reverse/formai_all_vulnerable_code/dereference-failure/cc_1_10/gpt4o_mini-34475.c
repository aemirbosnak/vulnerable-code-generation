//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: complete
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKET_SIZE 65535

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // Print packet information
    printf("Packet captured:\n");
    printf("Length: %d bytes\n", header->len);
    printf("Timestamp: %ld.%06ld seconds\n", header->ts.tv_sec, header->ts.tv_usec);

    // Format the packet data as hex
    for (int i = 0; i < header->len; i++) {
        printf("%02x ", packet[i]);
        if ((i + 1) % 16 == 0)
            printf("\n");
    }
    printf("\n\n");
}

void start_capture(const char *device) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // Open device for live capture
    handle = pcap_open_live(device, MAX_PACKET_SIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device, errbuf);
        exit(EXIT_FAILURE);
    }

    // Capture packets
    printf("Starting packet capture on device: %s\n", device);
    pcap_loop(handle, 0, packet_handler, NULL);

    pcap_close(handle);
}

void list_network_devices() {
    pcap_if_t *alldevs;
    pcap_if_t *d;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Get the list of network devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Could not find devices: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    printf("Available network devices:\n");
    for (d = alldevs; d != NULL; d = d->next) {
        printf(" - %s", d->name);
        if (d->description != NULL)
            printf(": %s", d->description);
        printf("\n");
    }

    // Free device list
    pcap_freealldevs(alldevs);
}

int main() {
    // List all available network devices
    list_network_devices();

    // Capture packets from a specified device
    char device[100];
    printf("Enter the device name to capture packets from: ");
    fgets(device, sizeof(device), stdin);
    device[strcspn(device, "\n")] = 0; // Remove newline character

    // Start packet capture
    start_capture(device);

    return 0;
}