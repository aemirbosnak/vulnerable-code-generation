//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define ETHERNET_HEADER_LEN 14
#define WIFI_MANAGEMENT_FRAME_TYPE 0x00
#define BUFFER_SIZE 2048

// Struct to hold wireless network info
typedef struct {
    char ssid[32];
    char bssid[18];
    int signal_strength;
} WiFiNetwork;

// Function to print Wi-Fi networks
void print_networks(WiFiNetwork *networks, int count) {
    printf("\nDetected Wireless Networks:\n");
    printf("| %-32s | %-18s | Signal Strength |\n", "SSID", "BSSID");
    printf("|--------------------------------|--------------------|-----------------|\n");
    for (int i = 0; i < count; i++) {
        printf("| %-32s | %-18s | %d dBm          |\n", networks[i].ssid, networks[i].bssid, networks[i].signal_strength);
    }
    printf("|-----------------------------------------------------------|\n");
}

// Function to handle packets
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    static WiFiNetwork networks[256];
    static int network_count = 0;

    // Check for a valid wireless management frame
    if (packet[0] == 0x80) {
        // Extract the BSSID (Source Address) and SSID (from the Information Element)
        char bssid[18];
        snprintf(bssid, sizeof(bssid), "%02x:%02x:%02x:%02x:%02x:%02x",
                 packet[10], packet[11], packet[12], packet[13], packet[14], packet[15]);

        // Extract SSID
        const u_char *ssid_ptr = packet + 36;  // Start of SSID
        int ssid_length = *(ssid_ptr + 1);
        
        WiFiNetwork network;
        strncpy(network.ssid, (char *)(ssid_ptr + 2), ssid_length);
        network.ssid[ssid_length] = '\0';  // Null-terminate SSID string
        strcpy(network.bssid, bssid);
        network.signal_strength = (int)(packet[29]) - 256;  // Signal strength (RSSI)

        // Store unique networks only
        int found = 0;
        for (int i = 0; i < network_count; i++) {
            if (strcmp(networks[i].bssid, network.bssid) == 0) {
                found = 1;
                break;
            }
        }
        if (!found && network_count < 256) {
            networks[network_count++] = network;
        }
    }

    // Print networks after receiving a predefined number of packets
    if (network_count == 256) {
        print_networks(networks, network_count);
        exit(0);  // Exit after printing
    }
}

int main() {
    pcap_if_t *interfaces;
    pcap_if_t *temp;
    char error_buffer[PCAP_ERRBUF_SIZE];

    // Find all available interfaces
    if (pcap_findalldevs(&interfaces, error_buffer) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", error_buffer);
        return EXIT_FAILURE;
    }

    // You can modify this to choose a specific interface
    temp = interfaces;
    while (temp != NULL) {
        printf("Device: %s\n", temp->name);
        temp = temp->next;
    }

    // Choose the first interface for sniffing
    pcap_t *handle = pcap_open_live(interfaces->name, BUFFER_SIZE, 1, 1000, error_buffer);
    if (handle == NULL) {
        fprintf(stderr, "Unable to open device %s: %s\n", interfaces->name, error_buffer);
        pcap_freealldevs(interfaces);
        return EXIT_FAILURE;
    }

    // Set a filter for only management frames (beacons)
    struct bpf_program fp;
    pcap_compile(handle, &fp, "type mgt subtype beacon", 0, PCAP_NETMASK_UNKNOWN);
    pcap_setfilter(handle, &fp);

    // Start capturing packets
    pcap_loop(handle, -1, packet_handler, NULL);

    // Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);
    pcap_freealldevs(interfaces);
    return EXIT_SUCCESS;
}