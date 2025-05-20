//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_SSID_LENGTH 32
#define MAX_BSSID_LENGTH 19
#define MAX_SIGNAL_STRENGTH_LENGTH 4

typedef struct {
    char ssid[MAX_SSID_LENGTH+1];
    char bssid[MAX_BSSID_LENGTH+1];
    int signal_strength;
} WiFiAP;

void readWiFiAP(FILE *file, WiFiAP *ap) {
    fscanf(file, "%[^,],%[^,],%d\n", ap->ssid, ap->bssid, &ap->signal_strength);
}

void printWiFiAP(WiFiAP ap) {
    printf("%s,%s,%d\n", ap.ssid, ap.bssid, ap.signal_strength);
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if(file == NULL) {
        fprintf(stderr, "Unable to open file: %s\n", strerror(errno));
        return 1;
    }

    WiFiAP aps[100];
    int num_aps = 0;

    while(!feof(file)) {
        readWiFiAP(file, &aps[num_aps++]);
    }

    fclose(file);

    int sum_strength = 0;
    int max_strength = -100;

    for(int i = 0; i < num_aps; i++) {
        sum_strength += aps[i].signal_strength;

        if(aps[i].signal_strength > max_strength) {
            max_strength = aps[i].signal_strength;
        }
    }

    double avg_strength = (double)sum_strength / num_aps;

    printf("Average Signal Strength: %.2f\n", avg_strength);
    printf("Max Signal Strength: %d\n", max_strength);

    return 0;
}