//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SSID_LEN 32
#define MAX_CHANNEL 14
#define MAX_BSSID_LEN 18
#define MAX_SIGNAL_STRENGTH 100

typedef struct {
    char ssid[MAX_SSID_LEN];
    int channel;
    char bssid[MAX_BSSID_LEN];
    int signal_strength;
} wifi_network_t;

int main() {
    int num_networks = 0;
    wifi_network_t networks[MAX_SSID_LEN];

    FILE *fp = fopen("wifi_networks.txt", "r");
    if (fp == NULL) {
        printf("Error: Failed to open wifi_networks.txt file.\n");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (num_networks >= MAX_SSID_LEN) {
            printf("Error: Maximum number of networks reached.\n");
            exit(1);
        }
        char *ssid = strtok(line, ",");
        int channel = atoi(strtok(NULL, ","));
        char *bssid = strtok(NULL, ",");
        int signal_strength = atoi(strtok(NULL, ","));

        strcpy(networks[num_networks].ssid, ssid);
        networks[num_networks].channel = channel;
        strcpy(networks[num_networks].bssid, bssid);
        networks[num_networks].signal_strength = signal_strength;

        num_networks++;
    }

    fclose(fp);

    printf("Number of networks found: %d\n", num_networks);

    for (int i = 0; i < num_networks; i++) {
        printf("Network %d:\n", i + 1);
        printf("SSID: %s\n", networks[i].ssid);
        printf("Channel: %d\n", networks[i].channel);
        printf("BSSID: %s\n", networks[i].bssid);
        printf("Signal strength: %d\n", networks[i].signal_strength);
        printf("\n");
    }

    return 0;
}