//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>

// Function prototype for packet processing
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *dev = argv[1]; // Network interface
    char errbuf[PCAP_ERRBUF_SIZE]; // Buffer to store error messages
    pcap_if_t *all_devs, *device;

    // Find all network interfaces
    if (pcap_findalldevs(&all_devs, errbuf) < 0) {
        fprintf(stderr, "Couldn't find devices: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // Check if the specified device exists
    for (device = all_devs; device != NULL; device = device->next) {
        if (strcmp(device->name, dev) == 0) {
            break;
        }
    }

    if (device == NULL) {
        fprintf(stderr, "Device not found: %s\n", dev);
        pcap_freealldevs(all_devs);
        exit(EXIT_FAILURE);
    }

    // Open the device for packet capturing
    pcap_t *handle = pcap_open_live(device->name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device->name, errbuf);
        pcap_freealldevs(all_devs);
        exit(EXIT_FAILURE);
    }

    printf("Starting packet capture on %s...\n", device->name);

    // Start capturing packets
    pcap_loop(handle, 0, packet_handler, NULL);

    // Cleanup
    pcap_freealldevs(all_devs);
    pcap_close(handle);
    return 0;
}

// Packet processing function
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // Print packet timestamp
    struct tm *ltime;
    char timestr[16]; // Time string format: HH:MM:SS
    ltime = localtime(&header->ts.tv_sec);
    strftime(timestr, sizeof timestr, "%H:%M:%S", ltime);
    printf("[%s.%06u] ", timestr, header->ts.tv_usec);

    // Print packet length
    printf("Packet length: %d bytes\n", header->len);
    
    // Print packet data in hex format
    printf("Packet data: ");
    for (int i = 0; i < header->len; i++) {
        printf("%02x ", packet[i]);
        if (i % 16 == 15) printf("\n");
    }
    printf("\n\n");
}