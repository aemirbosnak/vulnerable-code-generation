//FormAI DATASET v1.0 Category: Smart home light control ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>

// Define the light struct with switch state and brightness level
typedef struct {
    bool on;
    uint8_t brightness;
} Light;

// Define the SmartHome struct with array of lights
typedef struct {
    Light *lights[10];
    uint8_t numLights;
} SmartHome;

// Function to asynchronously control light switch on/off
void *controlSwitch(void* lightPtr) {
    Light *light = (Light*) lightPtr;
    while(1) {
        // Wait for 5 seconds
        sleep(5);
        // Toggle the switch
        if (light->on) {
            light->on = false;
            printf("Light turned off\n");
        }
        else {
            light->on = true;
            printf("Light turned on\n");
        }
    }
}

// Function to asynchronously control light brightness 
void *controlBrightness(void* lightPtr) {
    Light *light = (Light*) lightPtr;
    while(1) {
        // Wait for 10 seconds
        sleep(10);
        // Increase brightness by 10 if light is on
        if (light->on && light->brightness < 100) {
            light->brightness += 10;
            printf("Brightness increased by 10\n");
        }
        // Decrease brightness by 10 if light is on
        else if (light->on && light->brightness > 0) {
            light->brightness -= 10;
            printf("Brightness decreased by 10\n");
        }
    }
}

int main() {
    SmartHome myHome;
    
    // Configure and register lights
    myHome.lights[0] = (Light*) malloc(sizeof(Light));
    myHome.lights[0]->on = true;
    myHome.lights[0]->brightness = 50;
    myHome.numLights = 1;
    
    // Create threads to asynchronously control lights
    pthread_t switchThread, brightnessThread;
    int switchStatus = pthread_create(&switchThread, NULL, controlSwitch, (void*) myHome.lights[0]);
    int brightnessStatus = pthread_create(&brightnessThread, NULL, controlBrightness, (void*) myHome.lights[0]);
    
    // Check if thread creation successful
    if (switchStatus || brightnessStatus) {
        printf("Error creating threads\n");
        exit(EXIT_FAILURE);
    }
    
    // Wait for threads to finish
    pthread_join(switchThread, NULL);
    pthread_join(brightnessThread, NULL);
    
    // Free memory allocated for lights
    free(myHome.lights[0]);
    
    return 0;
}