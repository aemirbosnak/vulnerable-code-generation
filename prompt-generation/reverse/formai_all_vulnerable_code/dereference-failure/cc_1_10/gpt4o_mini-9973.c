//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/wireless.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <errno.h>
#include <stdint.h>

// Define constants for scanning
#define MAX_NETWORKS 256
#define SSID_MAX_LENGTH 32
#define BUFFER_SIZE 512

typedef struct {
    char ssid[SSID_MAX_LENGTH]; // Network SSID
    int signal_strength;         // Signal strength (dBm)
} Network;

Network networks[MAX_NETWORKS]; // Array to hold found networks
int network_count = 0;           // Count of found networks

// Function to scan available wireless networks
int scan_networks(const char *interface) {
    int sockfd;
    struct iwreq request;
    uint8_t buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Set the interface to scan
    strncpy(request.ifr_name, interface, IFNAMSIZ);
    if (ioctl(sockfd, SIOCGIWSCAN, &request) < 0) {
        perror("ioctl(SIOCGIWSCAN) failed");
        close(sockfd);
        return -1;
    }

    unsigned long scan_size = request.u.data.length;

    // Check if we have valid results
    if (scan_size == 0) {
        printf("No networks found.\n");
        close(sockfd);
        return 0;
    }

    // Read scan results
    if (read(sockfd, buffer, scan_size) < 0) {
        perror("Failed to read scan results");
        close(sockfd);
        return -1;
    }

    // Parse the results
    // For simplicity, we assume parsing is properly done
    char *ptr = (char *)buffer;
    char *end_ptr = ptr + scan_size;
    
    while (ptr < end_ptr && network_count < MAX_NETWORKS) {
        // Assume SSID and strength are stored correctly in the buffer
        Network *current_network = &networks[network_count];

        // Find and store SSID
        memcpy(current_network->ssid, ptr + 36, SSID_MAX_LENGTH); // Random offset
        current_network->ssid[SSID_MAX_LENGTH - 1] = '\0';

        // Assume signal strength is stored in the offset 20
        current_network->signal_strength = *((int16_t *)(ptr + 20));
        
        // Move pointer forward, it would be better with a more detailed parsing
        ptr += 100; // Adjust for your scanning data structure
        
        network_count++;
    }

    close(sockfd);
    return network_count;
}

// Function to display the results
void display_networks() {
    printf("\nFound Networks:\n");
    printf("---------------------\n");
    for (int i = 0; i < network_count; i++) {
        printf("SSID: %s, Signal Strength: %d dBm\n",
                networks[i].ssid, networks[i].signal_strength);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *interface = argv[1];
    
    // Start scanning for networks
    if (scan_networks(interface) < 0) {
        return EXIT_FAILURE;
    }

    // Display the found networks
    display_networks();

    return EXIT_SUCCESS;
}