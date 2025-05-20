//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char ssid[20];
    int channel;
    int strength;
} AP; // Access Point

void scan(AP **accessPoints, int *numberOfAPs);
void print(AP **accessPoints, int numberOfAPs);

int main() {
    AP **accessPoints;
    int numberOfAPs = 0;
    bool scannerOn = true;

    while(scannerOn) {
        char userInput;
        printf("Enter 's' to scan for WiFi networks, 'p' to print available networks, or 'q' to quit: ");
        scanf(" %c", &userInput);

        switch(userInput) {
            case 's':
                scan(accessPoints, &numberOfAPs);
                break;
            case 'p':
                print(accessPoints, numberOfAPs);
                break;
            case 'q':
                scannerOn = false;
                break;
            default:
                printf("Invalid input!\n");
        }
    }

    for(int i=0; i<numberOfAPs; i++) {
        free(accessPoints[i]);
    }
    free(accessPoints);

    return 0;
}

void scan(AP **accessPoints, int *numberOfAPs) {
    printf("Scanning...\n");

    int numNewAPs = rand() % 10; // randomly generate number of new access points
    accessPoints = (AP**)realloc(accessPoints, (*numberOfAPs + numNewAPs) * sizeof(AP*));

    for(int i=0; i<numNewAPs; i++) {
        AP *newAP = (AP*)malloc(sizeof(AP));
        sprintf(newAP->ssid, "AP%d", *numberOfAPs + i); // generate a unique name for the access point
        newAP->channel = rand() % 12 + 1; // randomly generate channel number between 1-12
        newAP->strength = rand() % 100; // randomly generate signal strength between 0-99

        accessPoints[*numberOfAPs + i] = newAP;
    }

    *numberOfAPs += numNewAPs;
    printf("Scan complete. %d new networks found.\n", numNewAPs);
}

void print(AP **accessPoints, int numberOfAPs) {
    printf("%d networks found:\n", numberOfAPs);

    for(int i=0; i<numberOfAPs; i++) {
        printf("Network %d - SSID: %s, Channel: %d, Strength: %d\n", i+1, accessPoints[i]->ssid, accessPoints[i]->channel, accessPoints[i]->strength);
    }
}