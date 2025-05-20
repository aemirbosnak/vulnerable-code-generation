//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SSID_LENGTH 32
#define MAX_SIGNAL_STRENGTH 100

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} WifiNetwork;

int main() {
    int num_networks;
    printf("How many Wi-Fi networks would you like to analyze? ");
    scanf("%d", &num_networks);

    WifiNetwork* networks = calloc(num_networks, sizeof(WifiNetwork));

    for (int i = 0; i < num_networks; i++) {
        printf("Enter the SSID for network %d: ", i+1);
        scanf("%s", networks[i].ssid);

        printf("Enter the signal strength for network %d (0 - 100): ", i+1);
        scanf("%d", &networks[i].signal_strength);

        if (networks[i].signal_strength < 0) {
            networks[i].signal_strength = 0;
        } else if (networks[i].signal_strength > MAX_SIGNAL_STRENGTH) {
            networks[i].signal_strength = MAX_SIGNAL_STRENGTH;
        }
    }

    printf("\nSSID\tSignal Strength\n");

    for (int i = 0; i < num_networks; i++) {
        printf("%s\t%d\n", networks[i].ssid, networks[i].signal_strength);
    }

    int max_signal_index = 0;
    for (int i = 1; i < num_networks; i++) {
        if (networks[i].signal_strength > networks[max_signal_index].signal_strength) {
            max_signal_index = i;
        }
    }

    printf("\nThe strongest network is %s with a signal strength of %d.", networks[max_signal_index].ssid, networks[max_signal_index].signal_strength);

    free(networks);

    return 0;
}