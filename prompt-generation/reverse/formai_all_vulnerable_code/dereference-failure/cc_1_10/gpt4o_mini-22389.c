//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <string.h>

#define ERRBUF_SIZE PCAP_ERRBUF_SIZE

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    const struct ip *ip_header;
    char src_ip[INET_ADDRSTRLEN], dst_ip[INET_ADDRSTRLEN];
    
    // Analyze the packet by examining the IP header
    ip_header = (struct ip *)(packet + 14); // Ethernet header is 14 bytes

    // Convert IP addresses to human-readable format
    inet_ntop(AF_INET, &(ip_header->ip_src), src_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &(ip_header->ip_dst), dst_ip, INET_ADDRSTRLEN);

    // Print the packet details
    printf("Packet captured:\n");
    printf("Source IP: %s\n", src_ip);
    printf("Destination IP: %s\n", dst_ip);
    printf("Protocol: %d\n", ip_header->ip_p);
    printf("Packet Length: %d bytes\n\n", header->len);
}

void start_capture(const char *dev) {
    char errbuf[ERRBUF_SIZE];
    pcap_t *handle;

    // Open the device for packet capturing
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", dev, errbuf);
        return;
    }

    // Start capturing packets
    pcap_loop(handle, 0, packet_handler, NULL);

    // Close the handle
    pcap_close(handle);
}

char* get_device() {
    char errbuf[ERRBUF_SIZE];
    pcap_if_t *alldevs, *device;

    // Retrieve the list of available devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Could not find any devices: %s\n", errbuf);
        return NULL;
    }

    // Choose the first device (for simplicity)
    device = alldevs;
    if (device == NULL) {
        fprintf(stderr, "No devices found.\n");
        return NULL;
    }

    // Return the name of the first device found
    char *dev_name = device->name;
    
    // Free the device list
    pcap_freealldevs(alldevs);
    
    return dev_name;
}

int main() {
    char *device;

    // Get a network device for capturing
    device = get_device();
    if (device != NULL) {
        printf("Using device: %s\n", device);
        start_capture(device);
    } else {
        fprintf(stderr, "No device available for capture.\n");
    }

    return 0;
}