//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of networks to scan for
#define MAX_NETWORKS 100

// Define the structure of a network
typedef struct {
    char *ssid;
    char *bssid;
    int channel;
    int signal_strength;
} network_t;

// Define the function to scan for wireless networks
int scan_for_networks(network_t **networks) {
    // Allocate memory for the array of networks
    *networks = (network_t *)malloc(sizeof(network_t) * MAX_NETWORKS);

    // Initialize the number of networks found to 0
    int num_networks = 0;

    // Open the file containing the list of wireless networks
    FILE *fp = fopen("/proc/net/wireless", "r");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    // Read the header line from the file
    char line[1024];
    if (fgets(line, sizeof(line), fp) == NULL) {
        perror("fgets");
        fclose(fp);
        return -1;
    }

    // Read each line from the file and parse the network information
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Parse the SSID, BSSID, channel, and signal strength from the line
        char *ssid = strtok(line, " ");
        char *bssid = strtok(NULL, " ");
        int channel = atoi(strtok(NULL, " "));
        int signal_strength = atoi(strtok(NULL, " "));

        // Allocate memory for the network and copy the information into it
        network_t *network = (network_t *)malloc(sizeof(network_t));
        network->ssid = strdup(ssid);
        network->bssid = strdup(bssid);
        network->channel = channel;
        network->signal_strength = signal_strength;

        // Add the network to the array of networks
        (*networks)[num_networks] = *network;
        num_networks++;
    }

    // Close the file
    fclose(fp);

    // Return the number of networks found
    return num_networks;
}

// Define the function to print the list of networks
void print_networks(network_t *networks, int num_networks) {
    // Print the header
    printf("SSID\t\tBSSID\t\tChannel\tSignal Strength\n");

    // Print each network
    for (int i = 0; i < num_networks; i++) {
        printf("%s\t%s\t\t%d\t\t%d\n", networks[i].ssid, networks[i].bssid, networks[i].channel, networks[i].signal_strength);
    }
}

// Define the main function
int main() {
    // Allocate memory for the array of networks
    network_t *networks;

    // Scan for wireless networks
    int num_networks = scan_for_networks(&networks);
    if (num_networks == -1) {
        perror("scan_for_networks");
        return -1;
    }

    // Print the list of networks
    print_networks(networks, num_networks);

    // Free the memory allocated for the array of networks
    for (int i = 0; i < num_networks; i++) {
        free(networks[i].ssid);
        free(networks[i].bssid);
    }
    free(networks);

    return 0;
}