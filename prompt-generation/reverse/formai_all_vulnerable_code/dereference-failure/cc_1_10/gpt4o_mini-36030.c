//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

#define MAX_NETWORKS 30
#define SSID_MAX_LEN 32

typedef struct {
    char ssid[SSID_MAX_LEN];
    int signal_strength;
} Network;

void parse_line(char *line, Network *network) {
    char *token = strtok(line, " ");
    int index = 0;

    while (token != NULL) {
        if (index == 0) {
            strncpy(network->ssid, token + 8, SSID_MAX_LEN - 1); // Skip "ESSID:\""
            network->ssid[SSID_MAX_LEN - 1] = '\0'; // Ensure null termination
        } else if (index == 1) {
            network->signal_strength = atoi(token + 3); // Skip "Quality="
        }
        token = strtok(NULL, " ");
        index++;
    }
}

int execute_command(char *cmd, Network networks[], int *count) {
    FILE *fp;
    char line[256];

    if ((fp = popen(cmd, "r")) == NULL) {
        fprintf(stderr, "Failed to run command: %s\n", strerror(errno));
        return -1;
    }

    *count = 0; // Initialize count of networks

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, "ESSID") && strstr(line, "Quality")) {
            parse_line(line, &networks[*count]);
            (*count)++;
            if (*count >= MAX_NETWORKS) break; // Prevent overflow
        }
    }

    pclose(fp);
    return 0;
}

void display_networks(Network networks[], int count) {
    printf("\nFound %d networks:\n", count);
    printf("%-30s %s\n", "Network SSID", "Signal Strength (dBm)");
    printf("--------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-30s %d\n", networks[i].ssid, networks[i].signal_strength);
    }

    printf("--------------------------------------------\n");
}

void analyze_signal_strength(Network networks[], int count) {
    int weak_count = 0, moderate_count = 0, strong_count = 0;

    for (int i = 0; i < count; i++) {
        if (networks[i].signal_strength < -80) {
            weak_count++;
        } else if (networks[i].signal_strength >= -80 && networks[i].signal_strength < -50) {
            moderate_count++;
        } else {
            strong_count++;
        }
    }

    printf("Signal Strength Analysis:\n");
    printf("Weak Networks: %d\n", weak_count);
    printf("Moderate Networks: %d\n", moderate_count);
    printf("Strong Networks: %d\n", strong_count);
}

int main() {
    Network networks[MAX_NETWORKS];
    int count = 0;

    char *command = "iwlist wlan0 scan | grep -E 'ESSID|Quality'";
    
    if (execute_command(command, networks, &count) != 0) {
        exit(EXIT_FAILURE);
    }

    display_networks(networks, count);
    analyze_signal_strength(networks, count);

    return 0;
}