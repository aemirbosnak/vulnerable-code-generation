//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_NETWORKS 100
#define MAX_SSID_LENGTH 32

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    char signal_level[10];
    char frequency[10];
} WifiNetwork;

void clearBuffer(char *buffer) {
    memset(buffer, 0, BUFFER_SIZE);
}

void printNetwork(WifiNetwork *network) {
    printf("------------------------------------------------------\n");
    printf("SSID: %-30s | Signal Level: %-10s | Frequency: %-10s\n",
           network->ssid, network->signal_level, network->frequency);
    printf("------------------------------------------------------\n");
}

void scanNetworks() {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    
    fp = popen("sudo iwlist wlan0 scan | grep -E 'ESSID|Signal|Frequency'", "r");
    if (fp == NULL) {
        printf("Failed to run iwlist command\n");
        exit(1);
    }

    WifiNetwork networks[MAX_NETWORKS];
    int networkCount = 0;

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        char *token = strtok(buffer, ":");
        if (strcmp(token, " ESSID") == 0) {
            if (networkCount < MAX_NETWORKS) {
                token = strtok(NULL, "\n");
                strcpy(networks[networkCount].ssid, token + 1); // skip the first quote
            }
        } else if (strcmp(token, " Signal level") == 0) {
            if (networkCount < MAX_NETWORKS) {
                char *levelToken = strtok(NULL, " ");
                strcpy(networks[networkCount].signal_level, levelToken);
            }
        } else if (strcmp(token, " Frequency") == 0) {
            if (networkCount < MAX_NETWORKS) {
                char *freqToken = strtok(NULL, " ");
                strcpy(networks[networkCount].frequency, freqToken);
                networkCount++;
            }
        }
    }

    pclose(fp);

    printf("\n-------------------- Available Wireless Networks --------------------\n");
    for (int i = 0; i < networkCount; i++) {
        printNetwork(&networks[i]);
    }
    printf("Total Networks Found: %d\n", networkCount);
}

int main() {
    printf("🚀 Starting Wireless Network Scanner... 🚀\n");
    printf("------------------------------------------------------\n");
    scanNetworks();
    printf("🎉 Scan Completed! 🎉\n");
    return 0;
}