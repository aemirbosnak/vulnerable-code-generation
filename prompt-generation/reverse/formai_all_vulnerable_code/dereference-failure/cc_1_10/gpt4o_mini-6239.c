//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: mind-bending
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <arpa/inet.h>
#include <time.h>

#define SNAP_LEN 65535 // max number of bytes to capture
#define SIZE_ETHERNET 14 // ethernet header length
#define ETHER_ADDR_LEN 6 // length of ethernet address
#define MAX_PACKETS 10 // Limit the number of packets captured

// Ethernet header structure
struct ethernet_header {
    u_char dest[ETHER_ADDR_LEN];
    u_char src[ETHER_ADDR_LEN];
    u_short type;
};

// Function to print the packet timestamp
void print_time(const struct pcap_pkthdr *header) {
    struct tm *ltime;
    char timestr[16]; // YYYY-MM-DD HH:MM:SS
    ltime = localtime(&header->ts.tv_sec);
    strftime(timestr, sizeof timestr, "%Y-%m-%d %H:%M:%S", ltime);
    printf("%s.%06ld ", timestr, header->ts.tv_usec);
}

// Function to capture and process packets
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ethernet_header *eth_header;
    eth_header = (struct ethernet_header *)(packet);

    // Print timestamp of the packet
    print_time(header);

    // Print source and destination MAC addresses
    printf("Source MAC: ");
    for(int i = 0; i < ETHER_ADDR_LEN; i++) {
        printf("%s%02x", i == 0 ? "" : ":", eth_header->src[i]);
    }
    printf(" | Destination MAC: ");
    for(int i = 0; i < ETHER_ADDR_LEN; i++) {
        printf("%s%02x", i == 0 ? "" : ":", eth_header->dest[i]);
    }
    
    // Print packet length
    printf(" | Packet Length: %d bytes\n", header->len);
}

// Signal handler to end the capture gracefully
void handle_signal(int sig) {
    pcap_breakloop((pcap_t *)sig);
}

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    int packet_count = 0;

    // Get the list of available devices
    if(pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Show available devices
    printf("Available devices:\n");
    for(device = alldevs; device; device = device->next) {
        printf("%s\n", device->name);
    }

    // Select the first device
    device = alldevs;
    
    // Open the device for capturing
    handle = pcap_open_live(device->name, SNAP_LEN, 1, 1000, errbuf);
    if(handle == NULL) {
        fprintf(stderr, "Error opening device %s: %s\n", device->name, errbuf);
        pcap_freealldevs(alldevs);
        return EXIT_FAILURE;
    }

    // Setup the signal handler
    signal(SIGINT, handle_signal);
    printf("Starting packet capture... Press Ctrl+C to stop.\n");

    // Start capturing packets
    pcap_loop(handle, MAX_PACKETS, packet_handler, (u_char *)&packet_count);

    // Cleanup and close the handle
    pcap_freealldevs(alldevs);
    pcap_close(handle);

    printf("Captured %d packets.\n", packet_count);
    return EXIT_SUCCESS;
}