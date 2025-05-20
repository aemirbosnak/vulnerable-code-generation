//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct {
    int id;
    char* ssid;
    int strength;
    time_t last_seen;
} wifi_signal;

int compare_wifi_signals(const void* a, const void* b) {
    const wifi_signal* signal_a = (const wifi_signal*)a;
    const wifi_signal* signal_b = (const wifi_signal*)b;
    return signal_b->strength - signal_a->strength;
}

int main() {
    // Cyberpunk-inspired variables
    char* cyberpunk_colors[] = {"#00FFFF", "#FF00FF", "#00FF00", "#FFFF00", "#FF0000"};
    char* cyberpunk_prefixes[] = {"Cyber", "Neo", "Digi", "Tron", "Bio"};
    char* cyberpunk_suffixes[] = {"Punk", "Tech", "Ware", "Net", "Code"};

    // Initialize the Wi-Fi signal analyzer
    int num_signals = 10;
    wifi_signal* signals = (wifi_signal*)malloc(sizeof(wifi_signal) * num_signals);

    // Generate random Wi-Fi signals
    srand(time(NULL));
    for (int i = 0; i < num_signals; i++) {
        signals[i].id = i;
        signals[i].ssid = (char*)malloc(32);
        sprintf(signals[i].ssid, "%s%s%s", cyberpunk_prefixes[rand() % 5], cyberpunk_colors[rand() % 5], cyberpunk_suffixes[rand() % 5]);
        signals[i].strength = rand() % 100;
        signals[i].last_seen = time(NULL);
    }

    // Sort the Wi-Fi signals by strength
    qsort(signals, num_signals, sizeof(wifi_signal), compare_wifi_signals);

    // Display the Wi-Fi signal strength analysis
    printf("===========================================================================================================================\n");
    printf("| ID | SSID                                  | Strength | Last Seen                                                        |\n");
    printf("===========================================================================================================================\n");
    for (int i = 0; i < num_signals; i++) {
        printf("| %2d | %-34s | %7d | %s |\n", signals[i].id, signals[i].ssid, signals[i].strength, ctime(&signals[i].last_seen));
    }
    printf("===========================================================================================================================\n");

    // Free the allocated memory
    for (int i = 0; i < num_signals; i++) {
        free(signals[i].ssid);
    }
    free(signals);

    return 0;
}