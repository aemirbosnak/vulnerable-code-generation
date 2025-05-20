//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <signal.h>
#include <unistd.h>

#define BUFSIZE 65536
#define SPACING 2

volatile sig_atomic_t stop;

void intHandler(int dummy) {
    stop = 1;
}

void packetHandler(unsigned char *args, const struct pcap_pkthdr *header, const unsigned char *packet) {
    static int packet_count = 0;
    packet_count++;

    int width = packet_count % 20 + 1; // Changing width dynamically
    int height = packet_count % 10 + 1; // Changing height dynamically

    printf("\033[H\033[J"); // Clear the console
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("█");
        }
        printf("\n");
        usleep(50000); // Sleep for a short duration for visibility
    }

    printf("\033[0;32mPacket Count: %d\n", packet_count);
    printf("Packet Length: %d bytes\n", header->len);
    printf("\033[0m----------------------------------------\n");

    // Extract Ethernet Header (example)
    printf("Ethernet Header:\n");
    printf("Source MAC: ");
    for (int i = 6; i < 12; i++) {
        if (i != 6) printf(":");
        printf("%02x", packet[i]);
    }
    printf("\nDestination MAC: ");
    for (int i = 0; i < 6; i++) {
        if (i != 0) printf(":");
        printf("%02x", packet[i]);
    }
    printf("\n");
}

int main() {
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    signal(SIGINT, intHandler); // Handle Ctrl+C gracefully

    // Find all available devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Couldn't find devices: %s\n", errbuf);
        return 1;
    }

    // Selecting the first device for simplicity
    device = alldevs;
    printf("Using Device: %s\n", device->name);

    // Open the device for sniffing
    handle = pcap_open_live(device->name, BUFSIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device->name, errbuf);
        return 2;
    }

    printf("Starting packet capture...\n");
    
    // Start the packet capture loop
    pcap_loop(handle, 0, packetHandler, NULL);

    // Cleanup
    pcap_close(handle);
    pcap_freealldevs(alldevs);
    printf("Packet capture stopped.\n");
    return 0;
}