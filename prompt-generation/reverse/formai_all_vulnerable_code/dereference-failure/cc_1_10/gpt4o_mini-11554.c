//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

#define MAX_WIFI_NETWORKS 100
#define MAX_SSID_LENGTH 32
#define DEFAULT_SCAN_INTERVAL 5 // in seconds

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength; // dBm
} wifi_network_t;

wifi_network_t networks[MAX_WIFI_NETWORKS];
int network_count = 0;

void scan_wifi_networks() {
    FILE *fp;
    char path[1035];
    
    // Clear previous data
    network_count = 0;

    // Run the command to scan Wi-Fi networks
    fp = popen("nmcli -f SSID,SIGNAL dev wifi", "r");
    if (fp == NULL) {
        printf("Error running the command: %s\n", strerror(errno));
        return;
    }
    
    // Parse the output
    while (fgets(path, sizeof(path), fp) != NULL) {
        if(network_count >= MAX_WIFI_NETWORKS) break;

        char ssid[MAX_SSID_LENGTH];
        int signal;

        // Tokenize the output
        sscanf(path, "%31[^ \t]\t%d", ssid, &signal);

        // Collect the SSID and Signal Strength
        strncpy(networks[network_count].ssid, ssid, MAX_SSID_LENGTH);
        networks[network_count].signal_strength = signal;
        network_count++;
    }
    
    pclose(fp);
}

void display_networks() {
    printf("\n--- Wi-Fi Networks ---\n");
    printf("SSID                              | Signal Strength (dBm)\n");
    printf("---------------------------------------------------------\n");

    for (int i = 0; i < network_count; i++) {
        printf("%-32s | %d\n", networks[i].ssid, networks[i].signal_strength);
    }

    printf("\n");
}

void start_signal_strength_analyzer(int scan_interval) {
    while (1) {
        scan_wifi_networks();
        display_networks();
        sleep(scan_interval);
    }
}

int main(int argc, char *argv[]) {
    int scan_interval = DEFAULT_SCAN_INTERVAL;

    // Check for user-defined interval
    if (argc > 1) {
        scan_interval = atoi(argv[1]);
    }

    printf("Starting Wi-Fi Signal Strength Analyzer...\n");
    printf("Scanning every %d seconds. Press Ctrl+C to stop.\n", scan_interval);

    start_signal_strength_analyzer(scan_interval);

    return 0;
}