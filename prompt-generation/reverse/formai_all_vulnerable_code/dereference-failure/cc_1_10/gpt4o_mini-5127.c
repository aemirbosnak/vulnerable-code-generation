//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORKS 100
#define MAX_SSID_LENGTH 32
#define BUFFER_SIZE 1024

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    char signal_strength[8];
    char encryption[32];
} Network;

void trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null terminate
    end[1] = '\0';
}

void parse_network_info(char *line, Network *network) {
    char *ssid = strstr(line, "ESSID:\"");
    if (ssid) {
        sscanf(ssid, "ESSID:\"%[^\"]\"", network->ssid);
    } else {
        strcpy(network->ssid, "N/A");
    }

    char *signal = strstr(line, "Signal level=");
    if (signal) {
        sscanf(signal, "Signal level=%s", network->signal_strength);
    } else {
        strcpy(network->signal_strength, "N/A");
    }

    char *encryption = strstr(line, "Encryption key:");
    if (encryption) {
        sscanf(encryption, "Encryption key:%s", network->encryption);
    } else {
        strcpy(network->encryption, "Open");
    }
}

void scan_networks(Network networks[], int *network_count) {
    FILE *fp;
    char command[] = "iwlist wlan0 scan"; // Change wlan0 as per your wireless interface
    char buffer[BUFFER_SIZE];

    // Execute the command and open a pipe to read the output
    fp = popen(command, "r");
    if (fp == NULL) {
        perror("Failed to run iwlist command");
        exit(1);
    }

    *network_count = 0;

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        trim_whitespace(buffer);
        if (strstr(buffer, "Cell") != NULL) {
            // Found a new network
            if (*network_count < MAX_NETWORKS) {
                parse_network_info(buffer, &networks[*network_count]);
                (*network_count)++;
            }
        }
    }

    pclose(fp);
}

void print_networks(Network networks[], int network_count) {
    printf("%-32s %-15s %s\n", "SSID", "Signal Strength", "Encryption");
    printf("%-32s %-15s %s\n", "----", "---------------", "----------");

    for (int i = 0; i < network_count; i++) {
        printf("%-32s %-15s %s\n", networks[i].ssid, networks[i].signal_strength, networks[i].encryption);
    }
}

int main() {
    Network networks[MAX_NETWORKS];
    int network_count = 0;

    printf("Scanning for wireless networks...\n");
    
    scan_networks(networks, &network_count);
    
    print_networks(networks, network_count);

    return 0;
}