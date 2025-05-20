//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: calm
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Define the Ethernet header size
#define SIZE_ETHERNET 14

// Structure for the wireless management frame
struct ieee80211_hdr {
    uint16_t frame_control;
    uint16_t duration;
    uint8_t addr1[6]; // Destination MAC
    uint8_t addr2[6]; // Source MAC
    uint8_t addr3[6]; // BSSID
    uint16_t seq_ctrl;
};

// Function to print the SSID found in the packet
void print_ssid(const u_char *packet, int size) {
    const struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)(packet + SIZE_ETHERNET);
    int header_len = SIZE_ETHERNET + sizeof(struct ieee80211_hdr);

    const u_char *end = packet + size;
    const u_char *pos = packet + header_len;

    while (pos < end) {
        if (*pos == 0x00) { // Tag Number for SSID
            int ssid_length = *(pos + 1);
            if (ssid_length > 0) {
                printf("SSID: ");
                for (int i = 0; i < ssid_length; i++) {
                    printf("%c", *(pos + 2 + i));
                }
                printf("\n");
            }
            break; // We only need the first SSID
        }
        pos += *(pos + 1) + 2; // Move to the next tag
    }
}

// Packet capture callback function
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet captured...\n");
    print_ssid(packet, header->len);
}

// Main function
int main(int argc, char *argv[]) {
    pcap_if_t *alldevs;
    pcap_if_t *device;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Check for proper command-line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    // Find all the devices available for capture
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return 1;
    }

    // Find the specified device
    for (device = alldevs; device != NULL; device = device->next) {
        if (strcmp(device->name, argv[1]) == 0) {
            break;
        }
    }

    // Check if the device was found
    if (device == NULL) {
        fprintf(stderr, "Device not found. Available devices:\n");
        for (device = alldevs; device != NULL; device = device->next) {
            printf("%s\n", device->name);
        }
        pcap_freealldevs(alldevs);
        return 1;
    }

    // Open the device for capturing packets in promiscuous mode
    pcap_t *handle = pcap_open_live(device->name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        pcap_freealldevs(alldevs);
        return 1;
    }

    printf("Listening on %s...\n", device->name);

    // Start capturing packets
    pcap_loop(handle, 0, packet_handler, NULL);

    // Clean up
    pcap_freealldevs(alldevs);
    pcap_close(handle);
    return 0;
}