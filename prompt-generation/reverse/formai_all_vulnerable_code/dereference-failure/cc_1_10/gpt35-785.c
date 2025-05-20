//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORKS 10
#define SIGNAL_THRESHOLD -70

typedef struct {
    char ssid[20];
    int signal_strength;
} network;

int main() {
    network networks[MAX_NETWORKS];
    int n_networks = 0;
    char input[40];
    char* token;

    printf("Enter the number of networks to analyze (up to %d): ", MAX_NETWORKS);
    fgets(input, 40, stdin);
    strtok(input, "\n");
    n_networks = atoi(input);

    if(n_networks > MAX_NETWORKS) {
        printf("Error: Too many networks, maximum is %d\n", MAX_NETWORKS);
        return 1;
    }

    printf("Enter the name and signal strength of each network:\n");
    for(int i = 0; i < n_networks; i++) {
        printf("Network %d: ", i+1);
        fgets(input, 40, stdin);
        strtok(input, "\n");
        token = strtok(input, " ");
        strcpy(networks[i].ssid, token);
        token = strtok(NULL, " ");
        networks[i].signal_strength = atoi(token);
    }

    printf("\nResults:\n");

    for(int i = 0; i < n_networks; i++) {
        printf("%s has a signal strength of %d\n", networks[i].ssid, networks[i].signal_strength);
        if(networks[i].signal_strength < SIGNAL_THRESHOLD) {
            printf("Signal is too weak, consider moving closer to the network\n");
        }
    }

    return 0;
}