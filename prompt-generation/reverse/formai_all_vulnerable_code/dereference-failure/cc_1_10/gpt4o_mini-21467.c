//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>

#define SNAP_LEN 1518  // Max number of bytes to capture

// Callback function that will be called by pcap for each captured packet
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ip *ip_header;
    char source_ip[INET_ADDRSTRLEN]; 
    char dest_ip[INET_ADDRSTRLEN];

    // Verify that the packet is large enough to contain the IP header
    if (header->len >= sizeof(struct ip)) {
        ip_header = (struct ip *)(packet + 14); // Skip ethernet header (14 bytes)
        
        // Convert the IP addresses from binary to ascii
        inet_ntop(AF_INET, &(ip_header->ip_src), source_ip, INET_ADDRSTRLEN);
        inet_ntop(AF_INET, &(ip_header->ip_dst), dest_ip, INET_ADDRSTRLEN);

        printf("Captured a packet:\n");
        printf("Source IP: %s\n", source_ip);
        printf("Destination IP: %s\n\n", dest_ip);
    } else {
        printf("Packet too small to contain IP header\n");
    }
}

int main(int argc, char *argv[]) {
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    int device_number = 0;

    if (argc > 1) {
        device_number = atoi(argv[1]);
    }

    // Get a list of all devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return 1;
    }

    // Print available devices
    printf("Available devices:\n");
    for (device = alldevs; device != NULL; device = device->next) {
        printf("%d: %s\n", ++device_number, device->name);
    }

    if (device_number < 1) {
        fprintf(stderr, "No devices found!\n");
        return 1;
    }

    // Open the selected device for capturing
    device = alldevs; // Reset to the first device
    for (int i = 1; i < device_number; i++) {
        device = device->next;
    }

    handle = pcap_open_live(device->name, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device %s: %s\n", device->name, errbuf);
        return 1;
    }

    // Start capturing packets
    printf("Listening on %s... Press Ctrl+C to stop.\n", device->name);
    pcap_loop(handle, 0, packet_handler, NULL);

    // Clean up and close the handle
    pcap_close(handle);
    pcap_freealldevs(alldevs);
    
    return 0;
}