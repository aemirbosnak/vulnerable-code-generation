//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct access_point {
    char SSID[50];
    int signal_strength;
};

int main() {
    int num_of_aps;
    printf("Enter the number of access points you want to analyze: ");
    scanf("%d", &num_of_aps);

    struct access_point aps[num_of_aps];

    for (int i = 0; i < num_of_aps; i++) {
        char ssid[50];
        int signal_strength;
        printf("Enter SSID of access point #%d: ", i+1);
        scanf("%s", ssid);
        printf("Enter signal strength (in dBm) of access point #%d: ", i+1);
        scanf("%d", &signal_strength);

        strcpy(aps[i].SSID, ssid);
        aps[i].signal_strength = signal_strength;
    }

    printf("Access Points Found:\n");
    for (int i = 0; i < num_of_aps; i++) {
        printf("SSID: %s\tSignal Strength: %ddBm\n", aps[i].SSID, aps[i].signal_strength);
    }

    int strongest_signal_index = 0;
    int strongest_signal_strength = aps[0].signal_strength;

    for (int i = 1; i < num_of_aps; i++) {
        if (aps[i].signal_strength > strongest_signal_strength) {
            strongest_signal_index = i;
            strongest_signal_strength = aps[i].signal_strength;
        }
    }

    printf("Strongest Signal:\n");
    printf("SSID: %s\tSignal Strength: %ddBm\n", aps[strongest_signal_index].SSID, aps[strongest_signal_index].signal_strength);

    int avg_signal_strength = 0;
    for (int i = 0; i < num_of_aps; i++) {
        avg_signal_strength += aps[i].signal_strength;
    }
    avg_signal_strength /= num_of_aps;

    printf("Average Signal Strength: %ddBm\n", avg_signal_strength);

    return 0;
}