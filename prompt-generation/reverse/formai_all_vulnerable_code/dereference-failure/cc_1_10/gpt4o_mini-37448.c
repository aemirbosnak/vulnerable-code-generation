//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORKS 100
#define BUFFER_SIZE 1024

typedef struct {
    char ssid[33]; // Max SSID length is 32 bytes + 1 for null terminator
    char signal[10]; // Signal strength
} Network;

void parse_networks(const char *buffer, Network networks[], int *network_count) {
    char *line;
    char *temp_line = strdup(buffer);
    char *save_ptr = NULL;

    *network_count = 0;
    
    line = strtok_r(temp_line, "\n", &save_ptr);
    while (line != NULL && *network_count < MAX_NETWORKS) {
        if (strstr(line, "ESSID:")) {
            sscanf(line, " ESSID:\"%[^\"]\"", networks[*network_count].ssid);
        }
        else if (strstr(line, "Signal level=")) {
            sscanf(line, " Signal level=%[^\n]", networks[*network_count].signal);
            (*network_count)++;
        }
        line = strtok_r(NULL, "\n", &save_ptr);
    }
    free(temp_line);
}

void scan_wifi_networks(Network networks[], int *network_count) {
    char command[BUFFER_SIZE] = "sudo iwlist scan 2>/dev/null";
    char buffer[BUFFER_SIZE * 5]; // Adjust based on expected output size.
    
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        perror("Failed to run command");
        exit(1);
    }

    fread(buffer, sizeof(char), sizeof(buffer) - 1, fp);
    pclose(fp);
    
    buffer[sizeof(buffer) - 1] = '\0'; // Ensure string termination
    
    parse_networks(buffer, networks, network_count);
}

void print_networks(const Network networks[], int network_count) {
    printf("\nAvailable Wireless Networks:\n");
    printf("-------------------------------------\n");
    printf("%-32s | %s\n", "SSID", "Signal Strength");
    printf("-------------------------------------\n");
    
    for (int i = 0; i < network_count; i++) {
        printf("%-32s | %s\n", networks[i].ssid, networks[i].signal);
    }
}

int main() {
    Network networks[MAX_NETWORKS];
    int network_count = 0;

    printf("Scanning for available wireless networks...\n");
    
    scan_wifi_networks(networks, &network_count);
    
    if (network_count > 0) {
        print_networks(networks, network_count);
    } else {
        printf("No wireless networks found.\n");
    }
    
    return 0;
}