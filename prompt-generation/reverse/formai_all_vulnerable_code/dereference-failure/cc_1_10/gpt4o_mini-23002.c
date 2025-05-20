//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: irregular
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Error message macro
#define ERR_MSG(err) fprintf(stderr, "Error: %s\n", err)

// Function prototypes
void packet_handler(u_char *user, const struct pcap_pkthdr *pkthdr, const u_char *packet);
void list_network_interfaces();
char* get_device_name();
void start_capture(const char *dev);

int main() {
    // List available network interfaces
    list_network_interfaces();

    // Get the device name from user input
    char *dev = get_device_name();
    if (dev == NULL) {
        ERR_MSG("No valid device found. Exiting...");
        return 1;
    }

    // Start packet capture
    start_capture(dev);

    // Free device name
    free(dev);
    return 0;
}

void list_network_interfaces() {
    pcap_if_t *alldevs, *device;
    char errbuf[PCAP_ERRBUF_SIZE];

    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        ERR_MSG(errbuf);
        return;
    }

    printf("Available network interfaces:\n");
    for (device = alldevs; device != NULL; device = device->next) {
        printf(" - %s\n", device->name);
    }

    pcap_freealldevs(alldevs);
}

char* get_device_name() {
    char *dev = (char *)malloc(100);
    printf("Enter the device name to capture packets: ");
    fgets(dev, 100, stdin);
    dev[strcspn(dev, "\n")] = 0;  // Remove newline character
    return dev;
}

void start_capture(const char *dev) {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    
    // Open the device for packet capture
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        ERR_MSG(errbuf);
        return;
    }

    // Capture packets indefinitely
    printf("Starting packet capture on %s...\n", dev);
    pcap_loop(handle, 0, packet_handler, NULL);
    pcap_close(handle);
}

void packet_handler(u_char *user, const struct pcap_pkthdr *pkthdr, const u_char *packet) {
    // Print packet info: timestamp and length
    printf("Captured a packet!\n");
    printf("Timestamp: %ld.%06ld\n", pkthdr->ts.tv_sec, pkthdr->ts.tv_usec);
    printf("Packet Length: %d bytes\n", pkthdr->len);

    // Optionally analyze packet content
    printf("Packet Data (hex): ");
    for(int i = 0; i < pkthdr->len; i++) {
        printf("%02x ", packet[i]);
        if ((i + 1) % 16 == 0) printf("\n                               ");
    }
    printf("\n\n");
}