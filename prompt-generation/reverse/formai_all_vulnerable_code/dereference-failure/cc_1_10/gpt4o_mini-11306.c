//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define MAX_NETWORKS 100

typedef struct {
    char ssid[100];
    int signal_strength;
} Network;

void parse_output(char *line, Network *network) {
    char *token;
    
    // The line format is: "SSID: [network_name] Signal strength: [value]"
    token = strtok(line, ":");
    if (strcmp(token, "SSID") == 0) {
        token = strtok(NULL, "\n");
        if (token != NULL) {
            sscanf(token, " [%[^]]", network->ssid);
        }
    }

    token = strtok(NULL, ":");
    if (token != NULL) {
        sscanf(token, " [%d]", &network->signal_strength);
    }
}

void print_networks(Network *networks, int count) {
    printf("\n\n------------------------\n");
    printf("Wi-Fi Networks Detected:\n");
    printf("------------------------\n");
    for (int i = 0; i < count; i++) {
        if (networks[i].signal_strength != 0) {
            printf("SSID: %s, Signal Strength: %d dBm\n", networks[i].ssid, networks[i].signal_strength);
        }
    }
    printf("------------------------\n\n");
}

int main() {
    char buffer[BUFFER_SIZE];
    FILE *fp;
    Network networks[MAX_NETWORKS];
    int network_count = 0;

    printf("\nWow, let’s check the Wi-Fi signal strength! Hold on tight!\n");

    // Use the command 'iwlist wlan0 scan' to get the Wi-Fi details
    fp = popen("iwlist wlan0 scan | grep -E 'SSID|Signal level'", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("Analyzing... Please wait for a moment!\n");

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (network_count >= MAX_NETWORKS) {
            printf("Whoa! We've reached the maximum number of networks!\n");
            break;
        }
        parse_output(buffer, &networks[network_count]);
        network_count++;
    }

    pclose(fp);

    print_networks(networks, network_count);

    // Sorting the networks based on signal strength
    for (int i = 0; i < network_count - 1; i++) {
        for (int j = i + 1; j < network_count; j++) {
            if (networks[i].signal_strength < networks[j].signal_strength) {
                Network temp = networks[i];
                networks[i] = networks[j];
                networks[j] = temp;
            }
        }
    }

    printf("Surprise! Here's the sorted list based on signal strength:\n");
    print_networks(networks, network_count);

    printf("All done! Now go enjoy some awesome browsing!\n");
    return 0;
}