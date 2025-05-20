//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <stdbool.h>

// Structure to store the SSID and BSSID of a wireless network
typedef struct {
    char *ssid;
    char *bssid;
} WirelessNetwork;

// Function to print the SSID and BSSID of a wireless network
void print_wireless_network(WirelessNetwork *network) {
    printf("SSID: %s\n", network->ssid);
    printf("BSSID: %s\n\n", network->bssid);
}

// Function to scan for wireless networks
void scan_for_wireless_networks() {
    // Initialize the pcap library
    pcap_t *handle = pcap_open_live("wlan0", 65535, 1, 1000, NULL);
    if (handle == NULL) {
        perror("pcap_open_live");
        return;
    }

    // Set the filter to capture only beacon frames
    char *filter = "type mgt subtype beacon";
    bpf_u_int32 netmask;
    struct bpf_program fp;
    if (pcap_compile(handle, &fp, filter, 0, netmask) == -1) {
        perror("pcap_compile");
        return;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        perror("pcap_setfilter");
        return;
    }

    // Capture packets
    int packets_to_capture = 100;
    struct pcap_pkthdr *header;
    const unsigned char *data;
    while (packets_to_capture-- > 0) {
        int res = pcap_next_ex(handle, &header, &data);
        if (res == -1) {
            perror("pcap_next_ex");
            return;
        } else if (res == 0) {
            continue;
        }

        // Parse the beacon frame
        const unsigned char *ie = data + header->caplen - 1;
        while (ie > data) {
            // Check if this is an SSID element
            if (*ie == 0) {
                // Check if this is a valid SSID element
                if (ie[1] >= 1 && ie[1] + 2 <= ie - data) {
                    // Get the SSID
                    char *ssid = malloc(ie[1] + 1);
                    memcpy(ssid, ie + 2, ie[1]);
                    ssid[ie[1]] = '\0';

                    // Get the BSSID
                    char *bssid = malloc(6);
                    memcpy(bssid, data + header->caplen - 11, 6);

                    // Create a new wireless network structure
                    WirelessNetwork *network = malloc(sizeof(WirelessNetwork));
                    network->ssid = ssid;
                    network->bssid = bssid;

                    // Print the wireless network
                    print_wireless_network(network);

                    // Free the memory allocated for the SSID and BSSID
                    free(ssid);
                    free(bssid);
                }
            }

            // Move to the next IE
            ie -= ie[1] + 2;
        }
    }

    // Close the pcap handle
    pcap_close(handle);
}

int main() {
    // Scan for wireless networks
    scan_for_wireless_networks();

    return 0;
}