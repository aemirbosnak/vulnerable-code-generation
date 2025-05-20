//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SSID_LENGTH 30

typedef struct WifiNetwork {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} WifiNetwork;

WifiNetwork* create_wifi_network(char* ssid, int signal_strength) {
    WifiNetwork* wifi_network = malloc(sizeof(WifiNetwork));
    strncpy(wifi_network->ssid, ssid, MAX_SSID_LENGTH);
    wifi_network->signal_strength = signal_strength;
    return wifi_network;
}

void print_wifi_network(WifiNetwork* wifi_network) {
    printf("SSID: %s\tSignal Strength: %d\n", wifi_network->ssid, wifi_network->signal_strength);
}

int* get_signal_strengths(WifiNetwork** wifi_networks, int num_networks) {
    int* signal_strengths = malloc(sizeof(int) * num_networks);
    for (int i = 0; i < num_networks; i++) {
        signal_strengths[i] = wifi_networks[i]->signal_strength;
    }
    return signal_strengths;
}

void swap(WifiNetwork** wifi_networks, int i, int j) {
    WifiNetwork* temp = wifi_networks[i];
    wifi_networks[i] = wifi_networks[j];
    wifi_networks[j] = temp;
}

void sort_by_signal_strength(WifiNetwork** wifi_networks, int num_networks) {
    int* signal_strengths = get_signal_strengths(wifi_networks, num_networks);
    for (int i = 0; i < num_networks; i++) {
        for (int j = i + 1; j < num_networks; j++) {
            if (signal_strengths[j] > signal_strengths[i]) {
                swap(wifi_networks, i, j);
                int temp = signal_strengths[i];
                signal_strengths[i] = signal_strengths[j];
                signal_strengths[j] = temp;
            }
        }
    }
    free(signal_strengths);
}

int main() {
    int num_networks;
    printf("Enter the number of wifi networks: ");
    scanf("%d", &num_networks);

    WifiNetwork** wifi_networks = malloc(sizeof(WifiNetwork*) * num_networks);
    for (int i = 0; i < num_networks; i++) {
        char* ssid = malloc(sizeof(char) * MAX_SSID_LENGTH);
        printf("Enter the SSID for network %d: ", i+1);
        scanf("%s", ssid);

        int signal_strength;
        do {
            printf("Enter the signal strength (0-100) for network %d: ", i+1);
            scanf("%d", &signal_strength);
        } while (signal_strength < 0 || signal_strength > 100);

        wifi_networks[i] = create_wifi_network(ssid, signal_strength);
    }

    sort_by_signal_strength(wifi_networks, num_networks);

    printf("\nWifi networks sorted by signal strength:\n");
    for (int i = 0; i < num_networks; i++) {
        print_wifi_network(wifi_networks[i]);
    }

    for (int i = 0; i < num_networks; i++) {
        free(wifi_networks[i]->ssid);
        free(wifi_networks[i]);
    }
    free(wifi_networks);

    return 0;
}