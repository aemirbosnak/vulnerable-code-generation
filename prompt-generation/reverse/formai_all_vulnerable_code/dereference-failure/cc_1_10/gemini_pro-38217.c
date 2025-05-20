//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: single-threaded
#include <pcap.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PACKET_SIZE 65535

// Custom structure to store packet data
typedef struct {
    struct pcap_pkthdr header;
    uint8_t *data;
} PacketData;

// Callback function to handle captured packets
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const uint8_t *data) {
    // Get the PacketData structure from the args
    PacketData *packetData = (PacketData *)args;

    // Copy the packet header
    memcpy(&packetData->header, header, sizeof(struct pcap_pkthdr));

    // Copy the packet data
    packetData->data = (uint8_t *)malloc(header->caplen);
    memcpy(packetData->data, data, header->caplen);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    // Open the network interface for packet capture
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(argv[1], MAX_PACKET_SIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening interface: %s\n", errbuf);
        return 1;
    }

    // Allocate memory for the PacketData structure
    PacketData packetData;

    // Set the PacketData structure as the user data for the packet handler
    pcap_loop(handle, 0, packet_handler, (u_char *)&packetData);

    // Print the captured packet data
    printf("Packet header:\n");
    printf("Timestamp: %u\n", packetData.header.ts.tv_sec);
    printf("Captured length: %u\n", packetData.header.caplen);
    printf("Actual length: %u\n", packetData.header.len);

    printf("\nPacket data:\n");
    for (int i = 0; i < packetData.header.caplen; i++) {
        printf("%02X ", packetData.data[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(packetData.data);

    // Close the capture handle
    pcap_close(handle);

    return 0;
}