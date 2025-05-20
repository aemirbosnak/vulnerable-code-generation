//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_NUM_OF_NETWORKS 100
#define MAX_SSID_LENGTH 64

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} wifi_network;

void analyze_wifi_strength();
void sort_networks_by_signal_strength(wifi_network* networks, int num_of_networks);
bool validate_signal_strength(char* signal_string);
bool validate_ssid(char* ssid);

int main() {
    // Program starts here
    analyze_wifi_strength();
    return 0;
}

void analyze_wifi_strength() {
    int num_of_networks = 0;
    char input[MAX_SSID_LENGTH + 5]; // ssid + signal + '\0' + 2xspaces
    wifi_network networks[MAX_NUM_OF_NETWORKS];

    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n\n");
    printf("Please enter the number of networks you want to analyze (1 to 100): ");

    fgets(input, sizeof(input), stdin);
    num_of_networks = atoi(input);

    if (num_of_networks < 1 || num_of_networks > 100) {
        printf("\nInvalid number of networks. Please try again.\n");
        return;
    }

    printf("\nOkay, let's analyze the signal strengths of %d networks. Please enter their SSIDs and signal strengths:\n", num_of_networks);
    for (int i = 0; i < num_of_networks; i++) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // remove trailing newline character

        char* ssid = strtok(input, " ");
        char* signal_str = strtok(NULL, " ");

        if (!validate_ssid(ssid) || !validate_signal_strength(signal_str)) {
            printf("\nInvalid input detected for network %d. Please try again.\n", i + 1);
            i--; // decrement i for re-entry of same network
            continue;
        }

        strcpy(networks[i].ssid, ssid);
        networks[i].signal_strength = atoi(signal_str);
    }

    sort_networks_by_signal_strength(networks, num_of_networks); // sort the networks by signal strength

    printf("\nThe networks sorted by signal strength (strongest to weakest) are:\n\n");

    for (int i = 0; i < num_of_networks; i++) {
        printf("%d. %s - %d dBm\n", i + 1, networks[i].ssid, networks[i].signal_strength);
    }

    printf("\nThe strongest network is '%s' with a signal strength of %d dBm.\n", networks[0].ssid, networks[0].signal_strength);
}

void sort_networks_by_signal_strength(wifi_network* networks, int num_of_networks) {
    int i, j;
    wifi_network temp;

    for (i = 0; i < num_of_networks - 1; i++) {
        for (j = i + 1; j < num_of_networks; j++) {
            if (networks[i].signal_strength < networks[j].signal_strength) {
                temp = networks[i];
                networks[i] = networks[j];
                networks[j] = temp;
            }
        }
    }
}

bool validate_signal_strength(char* signal_string) {
    int signal = atoi(signal_string);

    if (signal < -100 || signal > 0) {
        return false;
    }

    return true;
}

bool validate_ssid(char* ssid) {
    if (strlen(ssid) > MAX_SSID_LENGTH) {
        return false;
    }

    return true;
}