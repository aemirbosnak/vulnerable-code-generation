//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pcap.h>

// Function to get the signal strength of a specific access point
int get_signal_strength(char *interface, char *ssid) {
    // Open the network interface
    pcap_t *handle = pcap_open_live(interface, 65535, 1, 100, NULL);
    if (handle == NULL) {
        fprintf(stderr, "Error opening network interface: %s\n", pcap_geterr(handle));
        return -1;
    }

    // Compile the filter expression to match the SSID
    struct bpf_program filter;
    char filter_string[512];
    snprintf(filter_string, sizeof(filter_string), "wlan host %s", ssid);
    if (pcap_compile(handle, &filter, filter_string, 0, 0) != 0) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        return -1;
    }

    // Set the filter
    if (pcap_setfilter(handle, &filter) != 0) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        return -1;
    }

    // Capture the next packet
    struct pcap_pkthdr *header;
    const unsigned char *packet;
    int ret = pcap_next_ex(handle, &header, &packet);
    if (ret == 1) {
        // Get the signal strength from the packet
        int signal_strength = (int)packet[27] - 100;
        
        // Print the signal strength
        printf("Signal strength for %s: %d dBm\n", ssid, signal_strength);
        
        // Close the network interface
        pcap_close(handle);
        return signal_strength;
    } else {
        // No packet was captured
        fprintf(stderr, "No packet captured\n");
        pcap_close(handle);
        return -1;
    }
}

// Main function
int main(int argc, char **argv) {
    // Check if the correct number of arguments was provided
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <interface> <ssid>\n", argv[0]);
        return -1;
    }

    // Get the signal strength for the specified access point
    int signal_strength = get_signal_strength(argv[1], argv[2]);

    // Return the signal strength
    return signal_strength;
}