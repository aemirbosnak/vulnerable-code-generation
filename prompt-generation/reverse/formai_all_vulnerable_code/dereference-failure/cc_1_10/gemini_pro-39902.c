//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: dynamic
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>

#define MAX_BYTES_PER_PACKET 2048

// Custom data structure to store packet information
typedef struct PacketInfo {
    struct pcap_pkthdr header; // Packet header
    u_char *data;              // Packet data
} PacketInfo;

// Function to print packet information
void print_packet_info(PacketInfo *packet) {
    printf("Packet length: %d\n", packet->header.len);
    printf("Packet data:\n");
    for (int i = 0; i < packet->header.len; i++) {
        printf("%02x ", packet->data[i]);
    }
    printf("\n");
}

// Function to capture packets
int main(int argc, char *argv[]) {
    // Check if the user specified an interface
    if (argc != 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        return -1;
    }

    char *interface = argv[1];

    // Open the network interface
    pcap_t *handle = pcap_open_live(interface, MAX_BYTES_PER_PACKET, 1, 1000, NULL);
    if (handle == NULL) {
        printf("Error opening interface %s: %s\n", interface, pcap_geterr(handle));
        return -1;
    }

    // Create a buffer to store the packets
    PacketInfo packets[100];
    int packet_index = 0;

    // Capture packets
    while (1) {
        // Wait for a packet to arrive
        int status = pcap_next_ex(handle, &packets[packet_index].header, &packets[packet_index].data);
        if (status == 1) {
            // A packet was captured
            print_packet_info(&packets[packet_index]);
            packet_index++;
        } else if (status == 0) {
            // No packets were captured
            continue;
        } else if (status == -1) {
            // An error occurred
            printf("Error capturing packet: %s\n", pcap_geterr(handle));
            break;
        } else if (status == -2) {
            // The interface was closed
            printf("Interface %s was closed\n", interface);
            break;
        }
    }

    // Close the network interface
    pcap_close(handle);

    return 0;
}