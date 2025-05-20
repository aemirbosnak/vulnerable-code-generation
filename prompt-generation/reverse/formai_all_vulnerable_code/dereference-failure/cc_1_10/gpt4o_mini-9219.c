//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <arpa/inet.h>

// Function to handle each captured packet
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Captured a packet with length of [%d]\n", header->len);
    
    // Analyzing the captured packet (just a simple print in this example)
    for(int i = 0; i < header->len; i++) {
        if(i % 16 == 0) 
            printf("\n");
        printf("%02x ", packet[i]);
    }
    printf("\n\n");
}

int main(int argc, char *argv[]) {
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Check for device input
    if(argc < 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    // Find all available devices
    if(pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return 1;
    }

    // Find the specified device
    for(device = alldevs; device != NULL; device = device->next) {
        if(strcmp(device->name, argv[1]) == 0) {
            break;
        }
    }

    if(device == NULL) {
        fprintf(stderr, "Device %s not found.\n", argv[1]);
        pcap_freealldevs(alldevs);
        return 1;
    }

    // Open the selected device for capturing
    handle = pcap_open_live(device->name, BUFSIZ, 1, 1000, errbuf);
    if(handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        pcap_freealldevs(alldevs);
        return 1;
    }

    // Capture packets with a maximum count (0 means infinite)
    printf("Listening on %s...\n", device->name);
    pcap_loop(handle, 0, packet_handler, NULL);

    // Clean up
    pcap_freealldevs(alldevs);
    pcap_close(handle);
    
    printf("\nPacket capturing completed. Bye!\n");
    return 0;
}