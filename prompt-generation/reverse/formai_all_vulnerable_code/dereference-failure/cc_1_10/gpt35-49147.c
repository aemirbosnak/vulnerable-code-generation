//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIRELESS_FILE "/proc/net/wireless" // path to the wireless file

// struct to store wifi signal strength info
typedef struct {
    char interface[20];
    int signal;
    float quality;
} SignalInfo;

// function to parse wireless file and retrieve signal strength and quality
SignalInfo* parseWirelessFile() {
    FILE* file = fopen(WIRELESS_FILE, "r");

    if (!file) {
        printf("Error opening wireless file!\n");
        exit(1);
    }

    SignalInfo* signal = (SignalInfo*)malloc(sizeof(SignalInfo));

    if (!signal) {
        printf("Error allocating memory!\n");
        exit(1);
    }

    char line[256];
    int i = 0;

    while (fgets(line, sizeof(line), file)) {
        if (i == 2) {
            sscanf(line, "%s %d %f", signal->interface, &signal->signal, &signal->quality);
            break;
        }
        i++;
    }

    fclose(file);

    return signal;
}

int main() {
    SignalInfo* signal = parseWirelessFile();

    printf("Interface: %s\n", signal->interface);
    printf("Signal Strength: %d dBm\n", signal->signal);
    printf("Quality: %.2f/70\n", signal->quality);

    free(signal);

    return 0;
}