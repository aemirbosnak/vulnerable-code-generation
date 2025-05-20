//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: standalone
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Packet capture callback function
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct timeval ts = header->ts;
    time_t nowtime = ts.tv_sec;
    struct tm *nowtm = localtime(&nowtime);
    char time_str[64];
    strftime(time_str, sizeof(time_str), "%H:%M:%S", nowtm);
    
    printf("Packet captured at %s.%ld: \n", time_str, ts.tv_usec);
    printf("Packet length: %d bytes\n", header->len);
    
    // Print first 16 bytes of the packet in hex
    printf("Data: ");
    for (int i = 0; i < 16 && i < header->len; i++) {
        printf("%02x ", packet[i]);
    }
    printf("\n\n");
}

// Function to setup and start packet capturing
void start_capture(const char* interface) {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Open the interface for capturing packets
    handle = pcap_open_live(interface, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", interface, errbuf);
        exit(EXIT_FAILURE);
    }

    printf("Listening on %s...\n", interface);

    // Start capturing packets
    pcap_loop(handle, 0, packet_handler, NULL);

    // Close the packet capture handle
    pcap_close(handle);
}

// Function to list available devices
void list_devices() {
    pcap_if_t *alldevs;
    pcap_if_t *device;

    char errbuf[PCAP_ERRBUF_SIZE];

    // Retrieve the available devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    printf("Available devices:\n");
    for (device = alldevs; device != NULL; device = device->next) {
        printf(" - %s\n", device->name);
    }

    // Free the device list
    pcap_freealldevs(alldevs);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        list_devices();
        return EXIT_FAILURE;
    }

    // Start packet capturing on the specified interface
    start_capture(argv[1]);

    return EXIT_SUCCESS;
}