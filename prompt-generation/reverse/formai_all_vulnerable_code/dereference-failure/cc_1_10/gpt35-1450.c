//FormAI DATASET v1.0 Category: Smart home light control ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/* Define the state of the light */
typedef enum {
    OFF,
    ON
} LightState;

/* Define the time period for which the light stays on */
typedef enum {
    MORNING,
    AFTERNOON,
    EVENING,
    NIGHT
} TimePeriod;

/* Define the light struct */
typedef struct {
    LightState state;
    TimePeriod period;
} Light;

/* Function to toggle the light */
void toggleLight(Light *light) {
    if (light->state == OFF) {
        light->state = ON;
    } else {
        light->state = OFF;
    }
}

/* Function to get the current time */
TimePeriod getCurrentTime() {
    time_t rawTime;
    struct tm *currentTime;

    time(&rawTime);
    currentTime = localtime(&rawTime);

    int hour = currentTime->tm_hour;

    if (hour >= 5 && hour < 10) {
        return MORNING;
    } else if (hour >= 10 && hour < 18) {
        return AFTERNOON;
    } else if (hour >= 18 && hour < 22) {
        return EVENING;
    } else {
        return NIGHT;
    }
}

int main() {
    // Create a new light
    Light livingRoomLight = {OFF, MORNING};

    // Toggle the light
    toggleLight(&livingRoomLight);

    // Print the current state of the light
    printf("Living Room Light: %s\n", livingRoomLight.state == ON ? "ON" : "OFF");

    // Wait for some time
    sleep(5);

    // Toggle the light again
    toggleLight(&livingRoomLight);

    // Print the current state of the light
    printf("Living Room Light: %s\n", livingRoomLight.state == ON ? "ON" : "OFF");

    // Get the current time
    TimePeriod currentTimePeriod = getCurrentTime();

    // Set the time period for the living room light
    livingRoomLight.period = currentTimePeriod;

    // Print the current time period for the living room light
    switch (livingRoomLight.period) {
        case MORNING:
            printf("Living Room Light Time Period: MORNING\n");
            break;
        case AFTERNOON:
            printf("Living Room Light Time Period: AFTERNOON\n");
            break;
        case EVENING:
            printf("Living Room Light Time Period: EVENING\n");
            break;
        case NIGHT:
            printf("Living Room Light Time Period: NIGHT\n");
            break;
    }

    return 0;
}