//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

typedef struct wifi{
    char ssid[20];
    int signal_strength;
    char security_protocol[20];
} wifi;

int main(){
    int n;
    printf("Enter the number of Wi-Fi signals to be analyzed: ");
    scanf("%d", &n);

    wifi w[n];

    printf("\nEnter the details of the Wi-Fi networks:\n");

    for(int i=0; i<n; i++){
        printf("\nFor Wi-Fi network %d:\n", i+1);

        printf("SSID: ");
        scanf("%s", w[i].ssid);

        printf("Signal Strength (in dBm): ");
        scanf("%d", &w[i].signal_strength);

        printf("Security Protocol: ");
        scanf("%s", w[i].security_protocol);

    }

    printf("\nDetails of Wi-Fi networks with Signal Strength greater than or equal to -50 dBm and using WPA2 security protocol:\n");

    for(int i=0; i<n; i++){
        if(w[i].signal_strength>=-50 && strcmp(w[i].security_protocol, "WPA2")==0){
            printf("\nSSID: %s\nSignal Strength: %d dBm\nSecurity Protocol: %s\n", w[i].ssid, w[i].signal_strength, w[i].security_protocol);
        }
    }

    printf("\nDetails of Wi-Fi networks with Signal Strength greater than or equal to -70 dBm:\n");

    for(int i=0; i<n; i++){
        if(w[i].signal_strength>=-70){
            printf("\nSSID: %s\nSignal Strength: %d dBm\nSecurity Protocol: %s\n", w[i].ssid, w[i].signal_strength, w[i].security_protocol);
        }
    }

    return 0;
}