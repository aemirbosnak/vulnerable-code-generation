//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIGNAL_STRENGTH 100

void printSignalStrength(int signalStrength) {
    printf("Signal strength: %d", signalStrength);
    if (signalStrength >= 70) {
        printf(" (Strong)\n");
    }
    else if (signalStrength >= 50) {
        printf(" (Medium)\n");
    }
    else {
        printf(" (Weak)\n");
    }
}

int main() {
    int numWifiNetworks;
    printf("Enter the number of Wi-Fi networks to analyze: ");
    scanf("%d", &numWifiNetworks);
    getchar(); // consume newline

    char** wifiNetworks = malloc(numWifiNetworks * sizeof(char*));
    int* signalStrengths = malloc(numWifiNetworks * sizeof(int));

    for (int i=0; i<numWifiNetworks; i++) {
        printf("Enter the name of Wi-Fi network #%d: ", i+1);
        char* ssid = malloc(100 * sizeof(char));
        fgets(ssid, 100, stdin);
        wifiNetworks[i] = strdup(ssid); // allocate and copy ssid to wifiNetworks
        free(ssid); // free temp memory allocated by fgets

        printf("Enter the signal strength (0-100) of Wi-Fi network #%d: ", i+1);
        scanf("%d", &signalStrengths[i]);
        getchar(); // consume newline

        if (signalStrengths[i] > MAX_SIGNAL_STRENGTH || signalStrengths[i] < 0) {
            printf("Invalid signal strength: %d\n", signalStrengths[i]);
            return 1;
        }
    }

    // Sort wifiNetworks and signalStrengths based on signalStrengths in descending order
    for (int i=0; i<numWifiNetworks-1; i++) {
        for (int j=i+1; j<numWifiNetworks; j++) {
            if (signalStrengths[i] < signalStrengths[j]) {
                // Swap signalStrengths and wifiNetworks
                int tempStrength = signalStrengths[i];
                signalStrengths[i] = signalStrengths[j];
                signalStrengths[j] = tempStrength;

                char* tempNetwork = wifiNetworks[i];
                wifiNetworks[i] = wifiNetworks[j];
                wifiNetworks[j] = tempNetwork;
            }
        }
    }

    // Print the sorted Wi-Fi networks with signal strengths
    printf("Sorted Wi-Fi Networks based on Signal Strength\n");
    printf("--------------------------------------------\n");
    for (int i=0; i<numWifiNetworks; i++) {
        printf("%d. ", i+1);
        printf("%s", wifiNetworks[i]);
        printSignalStrength(signalStrengths[i]);
    }

    // Clean up memory
    for (int i=0; i<numWifiNetworks; i++) {
        free(wifiNetworks[i]);
    }
    free(wifiNetworks);
    free(signalStrengths);

    return 0;
}