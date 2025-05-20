//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <errno.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 2048

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // Function to process each captured packet
    struct tm *timeinfo;
    char timestamp[64];
    
    timeinfo = localtime(&header->ts.tv_sec);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);
    
    printf("Packet captured at: %s.%03ld\n", timestamp, header->ts.tv_usec / 1000);
    printf("Packet length: %d bytes\n", header->len);
    printf("Packet data:\n");

    for(int i = 0; i < header->len; i++) {
        if (i % 16 == 0) printf("\n");
        printf("%02x ", packet[i]);
    }
    
    printf("\n\n");
}

void start_capture(const char *device) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // Open the capture interface
    handle = pcap_open_live(device, BUFFER_SIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Unable to open device %s: %s\n", device, errbuf);
        exit(EXIT_FAILURE);
    }

    // Start the packet capture loop
    printf("Starting packet capture on %s...\n", device);
    pcap_loop(handle, 0, packet_handler, NULL);

    // Cleanup
    pcap_close(handle);
}

void list_devices() {
    pcap_if_t *alldevs;
    pcap_if_t *device;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Retrieve the list of devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    printf("Available devices:\n");
    for (device = alldevs; device != NULL; device = device->next) {
        printf("%s\n", device->name);
    }

    pcap_freealldevs(alldevs);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <device>\n", argv[0]);
        list_devices();
        exit(EXIT_FAILURE);
    }

    const char *device = argv[1];

    // Start packet capture
    start_capture(device);

    return 0;
}