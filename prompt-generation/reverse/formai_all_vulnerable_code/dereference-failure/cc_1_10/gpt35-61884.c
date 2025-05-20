//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SSID_LENGTH 32
#define MAX_RSSI_VALUE (-50)
#define MIN_RSSI_VALUE (-100)

typedef struct {
    char ssid[MAX_SSID_LENGTH + 1];
    int rssi;
} WifiAP;

void analyzeWifiSignalStrength(WifiAP *apList, int numAPs) {
    int total = 0;
    int max = MIN_RSSI_VALUE;
    int min = MAX_RSSI_VALUE;

    for (int i = 0; i < numAPs; i++) {
        if (apList[i].rssi > max) {
            max = apList[i].rssi;
        }
        if (apList[i].rssi < min) {
            min = apList[i].rssi;
        }
        total += apList[i].rssi;
    }

    double avg = (double)total / numAPs;
    printf("\nSignal strength report:\n");
    printf("========================\n");
    printf("Average signal strength: %.2f dBm\n", avg);
    printf("Maximum signal strength: %d dBm\n", max);
    printf("Minimum signal strength: %d dBm\n", min);
}

int main() {
    int numAPs, i;
    WifiAP *apList;

    printf("===============================\n");
    printf("Welcome to Wi-Fi Analyzer Tool.\n");
    printf("===============================\n");

    printf("\nHow many Wi-Fi access points (APs) are available in the area?\n");
    scanf("%d", &numAPs);

    apList = (WifiAP *)malloc(numAPs * sizeof(WifiAP));

    printf("\nOK, let's get started! Please input the SSID and RSSI value for each AP.\n");
    for (i = 0; i < numAPs; i++) {
        printf("AP %d:\n", i + 1);
        printf("\tSSID: ");
        scanf("%s", apList[i].ssid);
        printf("\tRSSI: ");
        scanf("%d", &apList[i].rssi);
        if (apList[i].rssi > MAX_RSSI_VALUE) {
            printf("\t*** Invalid RSSI value! The maximum valid value is %d dBm. ***\n", MAX_RSSI_VALUE);
            i--;
        }
        if (apList[i].rssi < MIN_RSSI_VALUE) {
            printf("\t*** Invalid RSSI value! The minimum valid value is %d dBm. ***\n", MIN_RSSI_VALUE);
            i--;
        }
    }

    analyzeWifiSignalStrength(apList, numAPs);

    free(apList);

    printf("\nThank you for using Wi-Fi Analyzer Tool! Have a nice day!\n");

    return 0;
}