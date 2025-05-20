//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    char *ssid;
    int strength;
    bool is_connected;
} wifi_network;

int compare_wifi_networks(const void *a, const void *b) {
    return strcmp(((wifi_network *)a)->ssid, ((wifi_network *)b)->ssid);
}

void print_wifi_networks(wifi_network *networks, int num_networks) {
    for (int i = 0; i < num_networks; i++) {
        printf("%s: %d%%\n", networks[i].ssid, networks[i].strength);
    }
}

int main() {
    // Get the number of Wi-Fi networks
    int num_networks;
    printf("Enter the number of Wi-Fi networks: ");
    scanf("%d", &num_networks);

    // Allocate memory for the Wi-Fi networks
    wifi_network *networks = malloc(sizeof(wifi_network) * num_networks);

    // Get the SSID and strength of each Wi-Fi network
    for (int i = 0; i < num_networks; i++) {
        networks[i].ssid = malloc(sizeof(char) * 32);
        printf("Enter the SSID of network %d: ", i + 1);
        scanf("%s", networks[i].ssid);
        printf("Enter the strength of network %d: ", i + 1);
        scanf("%d", &networks[i].strength);
        networks[i].is_connected = false;
    }

    // Sort the Wi-Fi networks by SSID
    qsort(networks, num_networks, sizeof(wifi_network), compare_wifi_networks);

    // Print the Wi-Fi networks
    print_wifi_networks(networks, num_networks);

    // Free the memory allocated for the Wi-Fi networks
    for (int i = 0; i < num_networks; i++) {
        free(networks[i].ssid);
    }
    free(networks);

    return 0;
}