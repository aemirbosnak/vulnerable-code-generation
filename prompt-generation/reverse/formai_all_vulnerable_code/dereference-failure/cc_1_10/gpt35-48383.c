//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIFI_SIGNALS 100

struct wifiSignal {
    char ssid[50];
    int strength;
};

int main() {
    struct wifiSignal signals[MAX_WIFI_SIGNALS];
    int signalCount = 0;
    char input[50];

    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n\n");

    while (strcmp(input, "exit") != 0) {
        printf("Enter a Wi-Fi SSID and signal strength in the format 'SSID,signal':\n");
        printf("(Type 'exit' to stop inputting signals)\n");
        fgets(input, 50, stdin);

        if (strcmp(input, "exit\n") == 0) {
            break;
        }

        char *ssid = strtok(input, ",");
        char *strengthString = strtok(NULL, ",");
        int strength = atoi(strengthString);

        struct wifiSignal newSignal;
        strcpy(newSignal.ssid, ssid);
        newSignal.strength = strength;

        signals[signalCount++] = newSignal;
    }

    printf("\n");

    if (signalCount == 0) {
        printf("No signals were inputted\n");
        return 0;
    }

    printf("Signal strength report:\n");
    printf("SSID\t\tSignal Strength\n");

    for (int i = 0; i < signalCount; i++) {
        printf("%s\t\t%d\n", signals[i].ssid, signals[i].strength);
    }

    int totalStrength = 0;
    float averageStrength = 0;

    for (int i = 0; i < signalCount; i++) {
        totalStrength += signals[i].strength;
    }

    averageStrength = (float) totalStrength / signalCount;

    printf("Average Wi-Fi signal strength: %.2f\n", averageStrength);

    int strongCount = 0;
    int weakCount = 0;
    for (int i = 0; i < signalCount; i++) {
        if (signals[i].strength >= 80) {
            strongCount++;
        } else {
            weakCount++;
        }
    }
    printf("%d signals are strong while %d signals are weak.\n", strongCount, weakCount);

    return 0;
}