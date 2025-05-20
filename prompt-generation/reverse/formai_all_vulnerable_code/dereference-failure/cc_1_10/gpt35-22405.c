//FormAI DATASET v1.0 Category: Smart home automation ; Style: interoperable
#include <stdio.h>
#include <stdbool.h>

// function to check if lights are on
bool areLightsOn(bool *lights, int numLights) {
    for(int i = 0; i < numLights; i++) {
        if(lights[i]) {
            return true;
        }
    }
    return false;
}

// function to turn lights on/off
void toggleLights(bool *lights, int numLights) {
    for(int i = 0; i < numLights; i++) {
        lights[i] = !lights[i];
    }
    printf("Lights are now %s.\n", areLightsOn(lights, numLights) ? "on" : "off");
}

// function to check if thermostat is at desired temperature
bool isTempAtDesired(int currentTemp, int desiredTemp) {
    return currentTemp == desiredTemp;
}

// function to adjust thermostat temperature
void adjustTemp(int *currentTemp, int desiredTemp) {
    if(*currentTemp < desiredTemp) {
        *currentTemp++;
    } else if(*currentTemp > desiredTemp) {
        *currentTemp--;
    }
    printf("Thermostat temperature is now %d.\n", *currentTemp);
}

int main() {
    // initialize lights and thermostat
    bool livingRoomLights[2] = {false, false};
    int thermostatTemp = 72;

    // print out startup message
    printf("Welcome to Smart Home Automation!\n");
    printf("Living room lights: %s.\n", areLightsOn(livingRoomLights, 2) ? "on" : "off");
    printf("Thermostat temperature: %d.\n\n", thermostatTemp);

    // simulate user input
    char input = ' ';
    while(input != 'q') {
        printf("Press 'l' to toggle living room lights, 't' to adjust thermostat temperature, or 'q' to quit: ");
        scanf(" %c", &input);

        if(input == 'l') {
            toggleLights(livingRoomLights, 2);
        } else if(input == 't') {
            printf("Enter desired temperature: ");
            int desiredTemp;
            scanf("%d", &desiredTemp);
            while(!isTempAtDesired(thermostatTemp, desiredTemp)) {
                adjustTemp(&thermostatTemp, desiredTemp);
            }
        } else if(input != 'q') {
            printf("Invalid input. Try again.\n");
        }
    }

    printf("\nGoodbye!\n");
    return 0;
}