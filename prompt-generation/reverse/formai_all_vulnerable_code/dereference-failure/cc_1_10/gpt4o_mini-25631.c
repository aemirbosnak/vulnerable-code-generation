//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    const struct ip *ip_header;
    char src_ip[INET_ADDRSTRLEN], dst_ip[INET_ADDRSTRLEN];

    // Get the IP header from the packet
    ip_header = (struct ip *)(packet + 14); // Ethernet header is 14 bytes

    // Convert the IP addresses to human-readable format
    inet_ntop(AF_INET, &(ip_header->ip_src), src_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &(ip_header->ip_dst), dst_ip, INET_ADDRSTRLEN);

    printf("Packet captured: Length: %d bytes | Source IP: %s | Destination IP: %s\n", 
           header->len, src_ip, dst_ip);
}

int main(int argc, char **argv) {
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Find the list of available devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Search for the specified device
    for (device = alldevs; device != NULL; device = device->next) {
        if (strcmp(device->name, argv[1]) == 0) {
            break;
        }
    }

    // Check if device was found
    if (device == NULL) {
        fprintf(stderr, "Device %s not found.\n", argv[1]);
        pcap_freealldevs(alldevs);
        return EXIT_FAILURE;
    }

    // Open the device for capturing
    handle = pcap_open_live(device->name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device->name, errbuf);
        pcap_freealldevs(alldevs);
        return EXIT_FAILURE;
    }

    printf("Capturing packets on device %s. Press Ctrl+C to stop.\n", device->name);

    // Start packet capture loop
    pcap_loop(handle, 0, packet_handler, NULL);

    // Clean up
    pcap_close(handle);
    pcap_freealldevs(alldevs);
    return EXIT_SUCCESS;
}