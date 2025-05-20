//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct wifi {
    char ssid[20];
    int signal_strength;
};

int main() {
    int n;
    printf("Enter the number of Wi-Fi networks: ");
    scanf("%d", &n);
    struct wifi networks[n];
    
    for(int i = 0; i < n; i++) {
        printf("\nEnter the SSID of the Wi-Fi network %d: ", i+1);
        scanf("%s", networks[i].ssid);
        printf("Enter the signal strength of the Wi-Fi network %d (in dBm): ", i+1);
        scanf("%d", &networks[i].signal_strength);
    }
    
    printf("\n\nSSID\tSignal Strength (dBm)\n");
    printf("----------------------------------\n");
    for(int i = 0; i < n; i++) {
        printf("%s\t%d\n", networks[i].ssid, networks[i].signal_strength);
    }
    
    //Sorting the networks based on signal strength in descending order
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(networks[j].signal_strength < networks[j+1].signal_strength) {
                struct wifi temp = networks[j];
                networks[j] = networks[j+1];
                networks[j+1] = temp;
            }
        }
    }
    
    printf("\n\nSSID\tSignal Strength (dBm)\n");
    printf("----------------------------------\n");
    for(int i = 0; i < n; i++) {
        printf("%s\t%d\n", networks[i].ssid, networks[i].signal_strength);
    }
    
    //Finding the network with the highest and lowest signal strength
    int max = networks[0].signal_strength;
    int min = networks[0].signal_strength;
    char max_ssid[20];
    char min_ssid[20];
    for(int i = 1; i < n; i++) {
        if(networks[i].signal_strength > max) {
            max = networks[i].signal_strength;
            strcpy(max_ssid, networks[i].ssid);
        }
        if(networks[i].signal_strength < min) {
            min = networks[i].signal_strength;
            strcpy(min_ssid, networks[i].ssid);
        }
    }
    
    printf("\n\nNetwork with highest signal strength:\nSSID: %s\tSignal Strength: %d dBm\n", max_ssid, max);
    printf("Network with lowest signal strength:\nSSID: %s\tSignal Strength: %d dBm\n", min_ssid, min);
    
    return 0;
}