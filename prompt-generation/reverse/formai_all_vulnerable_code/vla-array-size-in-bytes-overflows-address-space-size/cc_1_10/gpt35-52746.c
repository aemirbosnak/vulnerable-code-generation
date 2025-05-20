//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

struct wifi_signal {
    char ssid[MAX_SIZE];
    int strength;
};

typedef struct wifi_signal WIFI_SIGNAL;

void readwifi(WIFI_SIGNAL* signal) {
    printf("Enter SSID name: ");
    scanf("%s", signal->ssid);
    printf("Enter strength (in dBm): ");
    scanf("%d", &signal->strength);
}

void printwifi(WIFI_SIGNAL* signal) {
    printf("SSID name: %s, Strength: %d dBm\n", signal->ssid, signal->strength);
}

int compare_wifi_strength(const void* a, const void* b) {
    WIFI_SIGNAL* signal_a = (WIFI_SIGNAL*) a;
    WIFI_SIGNAL* signal_b = (WIFI_SIGNAL*) b;
    return signal_a->strength - signal_b->strength;
}

int main() {
    int num_signals;
    printf("Enter number of Wi-Fi signals to analyze: ");
    scanf("%d", &num_signals);

    WIFI_SIGNAL signals[num_signals];
    for (int i = 0; i < num_signals; i++) {
        printf("Input signal #%d:\n", i+1);
        readwifi(&signals[i]);
    }

    qsort(signals, num_signals, sizeof(WIFI_SIGNAL), compare_wifi_strength);

    printf("\n\nWi-Fi signals sorted by signal strength:\n");
    for (int i = 0; i < num_signals; i++) {
        printwifi(&signals[i]);
    }

    return 0;
}