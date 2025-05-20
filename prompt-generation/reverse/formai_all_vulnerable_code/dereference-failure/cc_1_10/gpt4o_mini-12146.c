//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <errno.h>

#define MAX_SSID_LENGTH 32
#define MAX_BSSID_LENGTH 18
#define MAX_SIGNAL_STRENGTH 100
#define NUM_SAMPLES 5

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    char bssid[MAX_BSSID_LENGTH];
    int signal_strength;
} WiFiNetwork;

void print_header() {
    printf("===========================================\n");
    printf("        Wi-Fi Signal Strength Analyzer     \n");
    printf("===========================================\n");
    printf("| %-30s | %-17s | %-15s |\n", "SSID", "BSSID", "Signal Strength (dBm)");
    printf("===========================================\n");
}

void print_network_info(WiFiNetwork network) {
    printf("| %-30s | %-17s | %-15d |\n", network.ssid, network.bssid, network.signal_strength);
}

void analyze_wifi_signals() {
    FILE *fp;
    char buffer[255];
    WiFiNetwork networks[NUM_SAMPLES];
    int count = 0;

    fp = popen("iwlist wlan0 scan | grep -E 'ESSID|Address|Signal level'", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command: %s\n", strerror(errno));
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (strstr(buffer, "ESSID:") != NULL) {
            // Extract SSID
            char *ssid = strchr(buffer, '\"') + 1;
            // Cut off the closing quote
            ssid[strcspn(ssid, "\"")] = 0;
            strncpy(networks[count].ssid, ssid, MAX_SSID_LENGTH);
        }
        else if (strstr(buffer, "Address:") != NULL) {
            // Extract BSSID
            sscanf(buffer, "          Address: %s", networks[count].bssid);
        }
        else if (strstr(buffer, "Signal level=") != NULL) {
            // Extract Signal level
            sscanf(buffer, "          Signal level=%d dBm", &networks[count].signal_strength);
            count++;
            if (count == NUM_SAMPLES) {
                break; // limit to NUM_SAMPLES networks
            }
        }
    }
    pclose(fp);

    print_header();
    for (int i = 0; i < count; i++) {
        print_network_info(networks[i]);
    }
    printf("===========================================\n");
}

int main() {
    printf("Welcome to Wi-Fi Analyzer!\n");
    printf("Press Ctrl+C to exit the program at any time.\n");

    while (1) {
        analyze_wifi_signals();
        sleep(5); // Refresh every 5 seconds
    }

    return 0;
}