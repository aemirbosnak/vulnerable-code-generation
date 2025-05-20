//FormAI DATASET v1.0 Category: Smart home light control ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// Define the structure for our lightbulbs
typedef struct Lightbulb {
    uint8_t id;
    bool isOn;
    uint8_t brightness;
} Lightbulb;

// Define the structure for our smart home light system
typedef struct SmartHomeLightControl {
    Lightbulb* bulbs;
    uint8_t numBulbs;
} SmartHomeLightControl;

// Initialize the smart home light control system with the desired number of bulbs
SmartHomeLightControl* initSmartHomeLightControl(uint8_t numBulbs) {
    SmartHomeLightControl* shlc = (SmartHomeLightControl*) malloc(sizeof(SmartHomeLightControl));
    shlc->numBulbs = numBulbs;
    shlc->bulbs = (Lightbulb*) calloc(numBulbs, sizeof(Lightbulb));
    for (int i = 0; i < numBulbs; i++) {
        shlc->bulbs[i].id = i+1;
        shlc->bulbs[i].isOn = false;
        shlc->bulbs[i].brightness = 0;
    }
    return shlc;
}

// Set the state of a specific lightbulb
void setLightbulbState(SmartHomeLightControl* shlc, uint8_t bulbId, bool isOn, uint8_t brightness) {
    for (int i = 0; i < shlc->numBulbs; i++) {
        if (shlc->bulbs[i].id == bulbId) {
            shlc->bulbs[i].isOn = isOn;
            shlc->bulbs[i].brightness = brightness;
            printf("Set bulb %d to state %s with brightness %d\n", bulbId, shlc->bulbs[i].isOn ? "ON" : "OFF", shlc->bulbs[i].brightness);
            return;
        }
    }
    printf("Could not find lightbulb with id %d\n", bulbId);
}

int main() {
    // Initialize the smart home light control system with 3 bulbs
    SmartHomeLightControl* shlc = initSmartHomeLightControl(3);
    
    // Turn on bulb 2 and set brightness to 50%
    setLightbulbState(shlc, 2, true, 128);
    
    // Turn off bulb 1
    setLightbulbState(shlc, 1, false, 0);
    
    // Free memory for smart home light control system
    free(shlc->bulbs);
    free(shlc);
    
    return 0;
}