//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Claude Shannon
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Function prototype for packet handling
void packetHandler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

// This program demonstrates the capture of packets in a simplistic yet effective manner.
int main(int argc, char *argv[]) {
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    char filter_exp[] = "ip"; // Filter for only IP packets
    int pkt_count = 0;

    // Check for the correct number of arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    // Get a list of all available devices
    if (pcap_findalldevs(&alldevs, errbuf) != 0) {
        fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
        return 1;
    }

    // Search for the specified device
    for (device = alldevs; device; device = device->next) {
        if (strcmp(device->name, argv[1]) == 0) {
            break;
        }
    }

    // If the device wasn't found
    if (device == NULL) {
        fprintf(stderr, "Device not found: %s\n", argv[1]);
        pcap_freealldevs(alldevs);
        return 1;
    }

    // Open the device for live capture
    handle = pcap_open_live(device->name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device %s: %s\n", device->name, errbuf);
        pcap_freealldevs(alldevs);
        return 1;
    }

    // Compile the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        pcap_freealldevs(alldevs);
        pcap_close(handle);
        return 1;
    }

    // Set the compiled filter
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        pcap_freealldevs(alldevs);
        pcap_close(handle);
        return 1;
    }

    // Begin packet capturing
    printf("Capturing packets on %s. Press Ctrl+C to stop.\n", device->name);
    
    // Start the packet capture loop
    pcap_loop(handle, 0, packetHandler, (u_char*)&pkt_count);

    // Cleanup
    pcap_freealldevs(alldevs);
    pcap_freecode(&fp);
    pcap_close(handle);
  
    printf("Captured %d packets.\n", pkt_count);
    return 0;
}

// Callback function to handle captured packets
void packetHandler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    int *counter = (int*)args;

    printf("Packet captured: Length: [%d] \n", header->len);
    (*counter)++; // Increment the packet count
}