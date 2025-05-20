//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int channel;
    char* ssid;
    int signalStrength;
} wifi;

wifi* analyzeWifi(wifi* wifis, int size) {
    wifi* strongestWifi = NULL;
    for(int i = 0; i < size; i++) {
        if(strongestWifi == NULL || wifis[i].signalStrength > strongestWifi->signalStrength) {
            strongestWifi = &wifis[i];
        }
    }
    return strongestWifi;
}

int main() {
    int numWifis;
    printf("Enter the number of Wi-Fi networks to analyze: ");
    scanf("%d", &numWifis);

    wifi* wifis = (wifi*) malloc(numWifis * sizeof(wifi));

    for(int i = 0; i < numWifis; i++) {
        printf("Enter the details for Wi-Fi network %d:\n", i+1);
        printf("Channel: ");
        scanf("%d", &wifis[i].channel);

        printf("SSID: ");
        char ssid[20];
        scanf("%s", ssid);
        int ssidLength = strlen(ssid);
        wifis[i].ssid = (char*) malloc((ssidLength+1) * sizeof(char));
        strcpy(wifis[i].ssid, ssid);

        printf("Signal Strength: ");
        scanf("%d", &wifis[i].signalStrength);
        printf("\n");
    }

    wifi* strongestWifi = analyzeWifi(wifis, numWifis);

    printf("The strongest Wi-Fi network is:\n");
    printf("Channel: %d\n", strongestWifi->channel);
    printf("SSID: %s\n", strongestWifi->ssid);
    printf("Signal Strength: %d\n", strongestWifi->signalStrength);

    for(int i = 0; i < numWifis; i++) {
        free(wifis[i].ssid);
    }
    free(wifis);

    return 0;
}