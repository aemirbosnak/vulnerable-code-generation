//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

// Grateful Wireless Network Scanner.
// Written with humility and appreciation for the world wide web.

// Function to print usage information.
void printUsage() {
    printf("Usage: wireless_scanner <interface>\n");
    printf("Example: wireless_scanner wlan0\n");
    exit(1);
}

// Function to capture packets and print their information.
void capturePackets(char *interface) {
    // Open the network interface for capturing packets.
    pcap_t *handle = pcap_open_live(interface, 65535, 1, 1000, NULL);
    if (handle == NULL) {
        perror("pcap_open_live()");
        exit(1);
    }

    // Create a filter to capture only beacon frames.
    struct bpf_program filter;
    if (pcap_compile(handle, &filter, "type mgt subtype beacon", 1, 0) == -1) {
        perror("pcap_compile()");
        exit(1);
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        perror("pcap_setfilter()");
        exit(1);
    }

    // Capture packets and print their information.
    while (1) {
        struct pcap_pkthdr *header;
        const u_char *packet;
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == -1) {
            perror("pcap_next_ex()");
            exit(1);
        } else if (res == 0) {
            continue;
        }

        // Parse the beacon frame.
        const u_char *beacon_frame = packet + header->caplen - header->len;
        const u_char *ssid = beacon_frame + 36;
        int ssid_len = *beacon_frame + 2;
        const u_char *bssid = beacon_frame + 4;
        const u_char *channel = beacon_frame + 42;

        // Print the beacon frame information.
        printf("--------------------------------------------------\n");
        printf("SSID: %.*s\n", ssid_len, ssid);
        printf("BSSID: %02x:%02x:%02x:%02x:%02x:%02x\n", bssid[0], bssid[1], bssid[2], bssid[3], bssid[4], bssid[5]);
        printf("Channel: %d\n", *channel);
        printf("--------------------------------------------------\n");
    }

    // Close the network interface.
    pcap_close(handle);
}

// Main function.
int main(int argc, char **argv) {
    // Check if the user provided an interface.
    if (argc != 2) {
        printUsage();
    }

    // Capture packets and print their information.
    capturePackets(argv[1]);

    return 0;
}