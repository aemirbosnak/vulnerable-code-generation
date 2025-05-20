//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_NETWORKS 100
#define MAX_SSID_LENGTH 32
#define MAX_LINE_LENGTH 256

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} WirelessNetwork;

void parse_line(const char *line, WirelessNetwork *network) {
    const char *ssid_start = strstr(line, "ESSID:\"");
    if (ssid_start) {
        ssid_start += strlen("ESSID:\"");
        const char *ssid_end = strchr(ssid_start, '\"');
        if (ssid_end) {
            size_t ssid_length = ssid_end - ssid_start;
            if (ssid_length < MAX_SSID_LENGTH) {
                strncpy(network->ssid, ssid_start, ssid_length);
                network->ssid[ssid_length] = '\0';
            }
        }
    }

    const char *signal_start = strstr(line, "Signal level=");
    if (signal_start) {
        signal_start += strlen("Signal level=");
        network->signal_strength = atoi(signal_start);
    }
}

void print_networks(WirelessNetwork networks[], int count) {
    printf("Available Wireless Networks:\n");
    printf("-----------------------------------------------------\n");
    printf("%-30s | %-17s\n", "SSID", "Signal Strength (dBm)");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-30s | %-17d\n", networks[i].ssid, networks[i].signal_strength);
    }
}

int scan_networks(WirelessNetwork networks[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int network_count = 0;

    fp = popen("iwlist scan", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run iwlist command: %s\n", strerror(errno));
        return -1;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, "Cell")) {
            if (network_count >= MAX_NETWORKS) {
                fprintf(stderr, "Reached maximum network limit (%d)\n", MAX_NETWORKS);
                break;
            }
            parse_line(line, &networks[network_count]);
            network_count++;
        }
    }

    pclose(fp);
    return network_count;
}

int main(void) {
    WirelessNetwork networks[MAX_NETWORKS];
    int network_count = scan_networks(networks);

    if (network_count < 0) {
        return EXIT_FAILURE;
    }

    print_networks(networks, network_count);

    return EXIT_SUCCESS;
}