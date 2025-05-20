//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: mind-bending
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The ethereal realm where packets reside
struct ether_frame {
    uint8_t dest_mac[6];
    uint8_t src_mac[6];
    uint16_t type;
    uint8_t data[1500];
};

// A mystical device that unveils the unseen
pcap_t *device;

// Shall we traverse this ethereal labyrinth?
int main() {
    // Scrying for a suitable device
    char *device_name = pcap_lookupdev(NULL);
    if (!device_name) {
        printf("No suitable device found. Try again when the stars align better.\n");
        return 1;
    }

    // Invoking the power of pcap
    device = pcap_open_live(device_name, BUFSIZ, 0, 1000, NULL);
    if (!device) {
        printf("Failed to open the device. The ethereal realm remains elusive.\n");
        return 1;
    }

    // A grand ritual to capture packets
    int packet_count = 0;
    while (1) {
        struct pcap_pkthdr *header;
        const uint8_t *packet;
        int res = pcap_next_ex(device, &header, &packet);
        if (res == 1) {
            // We have summoned a packet!
            packet_count++;

            // Parse the ether frame
            struct ether_frame *frame = (struct ether_frame *)packet;

            // Dive into the ether
            printf("Packet #%d\n", packet_count);
            printf("Destination MAC: %02X:%02X:%02X:%02X:%02X:%02X\n",
                frame->dest_mac[0], frame->dest_mac[1], frame->dest_mac[2],
                frame->dest_mac[3], frame->dest_mac[4], frame->dest_mac[5]);
            printf("Source MAC: %02X:%02X:%02X:%02X:%02X:%02X\n",
                frame->src_mac[0], frame->src_mac[1], frame->src_mac[2],
                frame->src_mac[3], frame->src_mac[4], frame->src_mac[5]);
            printf("Type: %04X\n", frame->type);
            printf("Data: %s\n", frame->data);
        } else if (res == -1) {
            // The ritual failed, leaving us in darkness
            printf("Error capturing packet. The ethereal realm taunts us.\n");
            return 1;
        } else {
            // Patience, young Padawan. The ethereal realm is testing our resolve.
        }
    }

    // Farewell, ethereal realm. May our paths cross again in the future.
    pcap_close(device);
    return 0;
}