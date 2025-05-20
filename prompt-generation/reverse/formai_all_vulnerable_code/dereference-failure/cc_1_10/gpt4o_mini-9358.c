//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>

#define MAX_LEN 1518 // Maximum Ethernet frame length
#define PARTY_NAME "Packet Party"

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("🎉 A new guest has arrived at the %s! 🎉\n", PARTY_NAME);
    printf("Packet length: %d bytes\n", header->len);
    printf("Arriving with some interesting contents: ");

    // Print the first 16 bytes of the packet in hexadecimal format
    for (int i = 0; i < 16 && i < header->len; i++) {
        printf("%02x ", packet[i]);
    }
    printf("\n\n");
}

void list_devices() {
    pcap_if_t *alldevs;
    char errbuf[PCAP_ERRBUF_SIZE];

    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "🤖 Error finding devices: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    printf("🎈 Welcome to the Packet Party! 🎈\n");
    printf("We have the following devices joining us:\n");
    
    for (pcap_if_t *d = alldevs; d != NULL; d = d->next) {
        printf("🎤 - %s\n", d->name);
    }

    pcap_freealldevs(alldevs);
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_if_t *dev;
    char *device;

    // Do some device listing to excite our guests
    list_devices();

    // Select the first device found for this party
    device = "lo"; // Loopback interface, you can change this to any device name!
    printf("🚀 We're choosing the guest of honor: %s\n", device);

    // Open the device for packet capturing
    pcap_t *handle = pcap_open_live(device, MAX_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "😱 Couldn't open device %s: %s\n", device, errbuf);
        return 2;
    }

    printf("🎉 Let the Packet Party Begin! 🎊\n");

    // Start capturing packets until we decide to leave the party
    pcap_loop(handle, 10, packet_handler, NULL); // Capture 10 packets

    printf("🥳 The party is over! Thanks for joining!\n");

    // Close the handle and clean up
    pcap_close(handle);
    return 0;
}