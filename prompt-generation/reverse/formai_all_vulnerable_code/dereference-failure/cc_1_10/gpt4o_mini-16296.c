//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256
#define WIFI_INFO_CMD "iwlist wlan0 scan | grep 'Signal level'"

typedef struct {
    char ssid[33];
    int signal_strength;
} WiFiNetwork;

void parse_wifi_info(char *line, WiFiNetwork *network) {
    char *ssid_start, *ssid_end, *signal_start;

    // Extract SSID
    ssid_start = strstr(line, "ESSID:\"") + 8;
    ssid_end = strstr(ssid_start, "\"");
    if (ssid_end != NULL) {
        strncpy(network->ssid, ssid_start, ssid_end - ssid_start);
        network->ssid[ssid_end - ssid_start] = '\0';
    } else {
        strcpy(network->ssid, "Unknown");
    }

    // Extract Signal Strength
    signal_start = strstr(line, "level=") + 6;
    if (signal_start != NULL) {
        network->signal_strength = atoi(signal_start);
    } else {
        network->signal_strength = 0;
    }
}

void scan_wifi_networks() {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    WiFiNetwork networks[20];
    int count = 0;

    // Open the command for reading
    fp = popen(WIFI_INFO_CMD, "r");
    if (fp == NULL) {
        perror("Failed to run command");
        exit(EXIT_FAILURE);
    }

    // Read the output a line at a time
    while (fgets(buffer, sizeof(buffer), fp) != NULL && count < 20) {
        parse_wifi_info(buffer, &networks[count++]);
    }

    // Close the command
    pclose(fp);

    // Display the results
    printf("%-32s | Signal Strength (dBm)\n", "SSID");
    printf("-----------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-32s | %d\n", networks[i].ssid, networks[i].signal_strength);
    }
}

int main() {
    printf("Wi-Fi Signal Strength Analyzer\n");
    printf("-----------------------------------------------\n");
    scan_wifi_networks();
    return 0;
}