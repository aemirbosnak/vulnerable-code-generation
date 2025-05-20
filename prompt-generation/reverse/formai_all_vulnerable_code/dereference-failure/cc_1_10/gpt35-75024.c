//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SSID_LEN 32
#define MAX_SIGNAL_STRENGTH 100

typedef struct wifi_network{
    char ssid[MAX_SSID_LEN];
    int signal_strength;
} wifi_network;

int main(){

    int num_networks;
    wifi_network *networks;

    // Get number of available Wi-Fi networks
    printf("Enter the number of available Wi-Fi networks: ");
    scanf("%d", &num_networks);

    // Allocate memory for the Wi-Fi network array
    networks = (wifi_network*) malloc(sizeof(wifi_network) * num_networks);

    // Get details for each Wi-Fi network
    for(int i=0; i<num_networks; i++){
        printf("\nEnter details for Network #%d:\n", i+1);
        printf("SSID: ");
        scanf("%s", networks[i].ssid);

        // Validate signal strength
        int signal_strength;
        do{
            printf("Signal Strength (0-100): ");
            scanf("%d", &signal_strength);

            if(signal_strength < 0 || signal_strength > MAX_SIGNAL_STRENGTH)
                printf("Invalid signal strength. Please enter a value between 0-100.\n");

        } while(signal_strength < 0 || signal_strength > MAX_SIGNAL_STRENGTH);

        networks[i].signal_strength = signal_strength;
    }

    // Sort Wi-Fi networks by signal strength
    for(int i=0; i<num_networks-1; i++){
        for(int j=i+1; j<num_networks; j++){
            if(networks[i].signal_strength < networks[j].signal_strength){
                // Swap the positions of the network with higher signal strength
                wifi_network temp = networks[i];
                networks[i] = networks[j];
                networks[j] = temp;
            }
        }
    }

    // Print the Wi-Fi networks in descending order of signal strength
    printf("\nAvailable Wi-Fi Networks Sorted by Signal Strength:\n\n");
    printf("%-32s %s\n", "SSID", "Signal Strength (%)");
    printf("----------------------------------\n");
    for(int i=0; i<num_networks; i++){
        printf("%-32s %d\n", networks[i].ssid, networks[i].signal_strength);
    }

    // Free the memory allocated for the Wi-Fi network array
    free(networks);

    return 0;
}