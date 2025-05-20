//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct wireless_network {
    char ssid[32];
    char bssid[18];
    int channel;
    int rssi;
    bool secured;
} WirelessNetwork;

const char *SECURITY_TYPES[] = {"Open", "WEP", "WPA", "WPA2"};

void print_network(WirelessNetwork network) {
    printf("SSID: %s\n", network.ssid);
    printf("BSSID: %s\n", network.bssid);
    printf("Channel: %d\n", network.channel);
    printf("RSSI: %d dBm\n", network.rssi);
    printf("Security: %s\n\n", SECURITY_TYPES[network.secured]);
}

int main() {
    WirelessNetwork networks[10] = {0};
    int num_networks = 0;
    FILE *fp = fopen("wireless_networks.txt", "r");
    if (fp == NULL) {
        printf("Error: wireless_networks.txt could not be opened.\n");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof line, fp) != NULL) {
        if (isspace(line[0])) {
            // this line is a continuation of the previous network's description
            // modify the previous network's description accordingly
            char *field_value = strtok(line, ":");
            char *value = strtok(NULL, "\n");
            if (strcmp(field_value, "BSSID") == 0) {
                strcpy(networks[num_networks - 1].bssid, value);
            }
            else if (strcmp(field_value, "channel") == 0) {
                networks[num_networks - 1].channel = atoi(value);
            }
            else if (strcmp(field_value, "RSSI") == 0) {
                networks[num_networks - 1].rssi = atoi(value);
            }
            else if (strcmp(field_value, "Security") == 0) {
                networks[num_networks - 1].secured = (strcmp(value, "yes") == 0);
            }
        }
        else {
            // this line is a new network description
            char *field_value = strtok(line, ":");
            char *value = strtok(NULL, "\n");
            if (strcmp(field_value, "SSID") == 0) {
                strcpy(networks[num_networks].ssid, value);
                num_networks++;
            }
        }
    }
    fclose(fp);

    for (int i = 0; i < num_networks; i++) {
        print_network(networks[i]);
    }

    return 0;
}