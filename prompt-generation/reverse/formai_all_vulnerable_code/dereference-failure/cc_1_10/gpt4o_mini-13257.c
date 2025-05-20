//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

#define MAX_PACKET_SIZE 65536

void packet_handler(u_char *user, const struct pcap_pkthdr *pkthdr, const u_char *packet) {
    printf("Packet captured:\n");
    printf("Length: %d bytes\n", pkthdr->len);
    
    // Print each byte of the packet in hexadecimal format
    for (int i = 0; i < pkthdr->len; i++) {
        printf("%02x ", packet[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n\n");
}

int main(int argc, char *argv[]) {
    pcap_if_t *alldevsp;
    pcap_if_t *device;
    char errbuf[PCAP_ERRBUF_SIZE];
    
    // Check for a device to capture packets from
    if (pcap_findalldevs(&alldevsp, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return 1;
    }

    // Display available devices
    printf("Available devices:\n");
    for (device = alldevsp; device != NULL; device = device->next) {
        printf("- %s\n", device->name);
    }

    // Prompt user for a device selection
    char *dev_name;
    if (alldevsp->next == NULL) {
        dev_name = alldevsp->name; // Only one device found
    } else {
        printf("Select a device name from above (or press Enter for the first one)\n");
        fgets(dev_name, sizeof(dev_name), stdin);
        
        // Remove newline character if present
        dev_name[strcspn(dev_name, "\n")] = 0; 
    }

    // Opening the device for packet capture
    pcap_t *handle = pcap_open_live(dev_name, MAX_PACKET_SIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", dev_name, errbuf);
        return 2;
    }

    printf("Listening on %s...\n", dev_name);

    // Start capturing packets
    pcap_loop(handle, 0, packet_handler, NULL);
    
    // Close the pcap handle
    pcap_close(handle);
    
    // Free the list of devices
    pcap_freealldevs(alldevsp);
    
    return 0;
}