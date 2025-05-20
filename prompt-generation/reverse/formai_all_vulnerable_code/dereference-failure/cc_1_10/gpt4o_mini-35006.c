//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ether.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <linux/wireless.h>
#include <stdint.h>

#define MAX_SSID_LENGTH 32
#define MAX_NETWORKS 128

struct WiFiNetwork {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
};

struct WiFiNetwork networks[MAX_NETWORKS];
int network_count = 0;

// Function to clear previous results
void clear_results() {
    memset(networks, 0, sizeof(networks));
    network_count = 0;
}

// Signal handler for graceful exit
void handle_sigint(int sig) {
    printf("\nExiting the Wireless Network Scanner. Goodbye!\n");
    exit(0);
}

// Function to scan for WiFi networks
void scan_networks() {
    int sockfd;
    struct iwreq request;
    struct iw_scan_req scan_settings;

    // Clear previous results
    clear_results();

    // Open a socket for scanning
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Specify the wireless interface (you can modify this)
    strncpy(request.ifr_name, "wlan0", IFNAMSIZ);
    if (ioctl(sockfd, SIOCGIWSCAN, &request) < 0) {
        perror("Device does not support scanning");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Perform the scan
    memset(&scan_settings, 0, sizeof(scan_settings));
    scan_settings.essid_len = 0;
    scan_settings.scan_type = IW_SCAN_TYPE_ACTIVE;
    if (ioctl(sockfd, SIOCSIWSCAN, &request) < 0) {
        perror("Scanning failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Introduce a delay to wait for the scan to finish
    sleep(5);

    // Fetch scan results
    while (1) {
        struct iw_event iwe;

        // Getting the network information
        if (ioctl(sockfd, SIOCGIWESSID, &request) < 0) {
            break; // No more networks
        }

        strcpy(networks[network_count].ssid, (char *)request.u.essid.pointer);
        networks[network_count].signal_strength = request.u.freq.m * 100; // This is just a fictitious way to depict strength
        network_count++;

        if (network_count >= MAX_NETWORKS) {
            break; // Reached the limit of networks
        }
    }

    close(sockfd);
}

// Function to display the scanned networks
void display_networks() {
    if (network_count == 0) {
        printf("No networks found!\n");
        return;
    }

    printf("\nAvailable Wireless Networks:\n");
    printf("-----------------------------------------------------------------\n");
    printf("%-30s | Signal Strength\n", "SSID");
    printf("-----------------------------------------------------------------\n");
    for (int i = 0; i < network_count; i++) {
        printf("%-30s | %d%%\n", networks[i].ssid, networks[i].signal_strength);
    }
    printf("-----------------------------------------------------------------\n");
}

int main(int argc, char *argv[]) {
    // Handle Ctrl+C signal to exit gracefully
    signal(SIGINT, handle_sigint);

    printf("=============================================\n");
    printf("     🎉 WELCOME TO WIRELESS NETWORK SCANNER! 🎉\n");
    printf("=============================================\n");

    // Scan networks
    scan_networks();

    // Display found networks
    display_networks();

    printf("Thank you for using the Wireless Network Scanner!\n");
    return 0;
}