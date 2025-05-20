//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap/pcap.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Structure to store the wireless network information
typedef struct {
    char *essid;
    char *bssid;
    char *channel;
    int frequency;
    int signal_level;
} wireless_network;

// Function to print the wireless network information
void print_network(wireless_network *network) {
    printf("ESSID: %s\n", network->essid);
    printf("BSSID: %s\n", network->bssid);
    printf("Channel: %s\n", network->channel);
    printf("Frequency: %d MHz\n", network->frequency);
    printf("Signal level: %d dBm\n\n", network->signal_level);
}

// Function to scan for wireless networks
void scan_networks() {
    // Open the network interface
    char *interface = "wlan0";
    pcap_t *handle = pcap_open_live(interface, BUFSIZ, 1, 1000, NULL);
    if (handle == NULL) {
        perror("pcap_open_live");
        exit(1);
    }

    // Set the filter to only capture beacon frames
    struct bpf_program filter;
    if (pcap_compile(handle, &filter, "type mgt subtype beacon", 1, 0) == -1) {
        perror("pcap_compile");
        exit(1);
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        perror("pcap_setfilter");
        exit(1);
    }

    // Loop through the packets
    int count = 0;
    while (1) {
        // Get the next packet
        struct pcap_pkthdr *header;
        const u_char *packet;
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == -1) {
            perror("pcap_next_ex");
            exit(1);
        }
        if (res == 0) {
            continue;
        }

        // Parse the beacon frame
        const u_char *beacon = packet + header->caplen - header->len;
        const u_char *essid = beacon + 36;
        const u_char *bssid = beacon + 42;
        int channel = beacon[76];
        int frequency = (channel <= 14) ? 2407 + channel * 5 : 5000 + channel * 5;
        int signal_level = (int)packet[27] - (int)packet[30] - 95;

        // Allocate memory for the wireless network information
        wireless_network *network = malloc(sizeof(wireless_network));
        network->essid = malloc(header->len - 36);
        network->bssid = malloc(18);
        network->channel = malloc(4);
        network->frequency = frequency;
        network->signal_level = signal_level;

        // Copy the wireless network information
        memcpy(network->essid, essid, header->len - 36);
        memcpy(network->bssid, bssid, 18);
        sprintf(network->channel, "%d", channel);

        // Print the wireless network information
        print_network(network);

        // Free the memory allocated for the wireless network information
        free(network->essid);
        free(network->bssid);
        free(network->channel);
        free(network);

        count++;
    }

    // Close the network interface
    pcap_close(handle);
}

int main() {
    scan_networks();
    return 0;
}