//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Donald Knuth
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_PACKET_SIZE 65536
#define PROMISCUOUS_MODE 1
#define TIMEOUT 1000

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // Print packet length and the time it was captured
    printf("Packet captured at %s Length: %d bytes\n",
           ctime((const time_t *)&header->ts.tv_sec), header->len);

    // Print the packet contents in hexadecimal format
    printf("Packet data (hex): ");
    for (int i = 0; i < header->len; i++) {
        printf("%02x ", packet[i]);
        // Print a new line every 16 bytes for better readability
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n\n");
}

void capture_packets(char *device) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // Open the device for packet capture
    handle = pcap_open_live(device, MAX_PACKET_SIZE, PROMISCUOUS_MODE, TIMEOUT, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device, errbuf);
        exit(EXIT_FAILURE);
    }

    // Capture packets indefinitely
    pcap_loop(handle, 0, packet_handler, NULL);

    // Close the pcap handle
    pcap_close(handle);
}

void list_devices() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_if_t *interfaces, *temp;

    // Get the list of available devices
    if (pcap_findalldevs(&interfaces, errbuf) == -1) {
        fprintf(stderr, "Could not find any devices: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    printf("Available network devices:\n");
    for (temp = interfaces; temp != NULL; temp = temp->next) {
        printf(" - %s\n", temp->name);
    }

    // Free the device list
    pcap_freealldevs(interfaces);
}

int main() {
    printf("Welcome to the C Packet Capturer!\n");
    printf("This program will capture and display network packets.\n\n");

    list_devices();

    // User selects the device on which to capture packets
    char device[100];
    printf("Enter the device name to capture packets from (e.g., eth0): ");
    fgets(device, sizeof(device), stdin);
    device[strcspn(device, "\n")] = 0; // Remove newline character

    // Start capturing packets on the selected device
    printf("Starting packet capture on %s...\n", device);
    capture_packets(device);

    return 0;
}