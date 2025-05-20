//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIGNALS 10
#define MAX_SSID_LEN 20

typedef struct wifi_signal_t {
    char ssid[MAX_SSID_LEN];
    int signal_strength;
} WifiSignal;

void analyze_signals(WifiSignal signals[], int num_signals) {
    int avg_strength = 0;

    for (int i = 0; i < num_signals; i++) {
        avg_strength += signals[i].signal_strength;
    }

    avg_strength /= num_signals;

    printf("Average signal strength: %d dBm\n", avg_strength);

    printf("Strongest signals:\n");
    for (int i = 0; i < 3 && i < num_signals; i++) {
        printf("%s (%d dBm)\n", signals[i].ssid, signals[i].signal_strength);
    }
}

int main(int argc, char *argv[]) {
    WifiSignal signals[MAX_SIGNALS];
    int num_signals = 0;

    if (argc < 2) {
        printf("Usage: %s <signal1> <strength1> <signal2> <strength2> ...\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i += 2) {
        if (num_signals == MAX_SIGNALS) {
            printf("Maximum number of signals exceeded\n");
            break;
        }

        strncpy(signals[num_signals].ssid, argv[i], MAX_SSID_LEN - 1);
        signals[num_signals].ssid[MAX_SSID_LEN - 1] = '\0';

        signals[num_signals].signal_strength = atoi(argv[i + 1]);

        num_signals++;
    }

    analyze_signals(signals, num_signals);

    return 0;
}