//LLAMA2-13B DATASET v1.0 Category: Weather simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 30
#define MIN_TEMP 0

// Define the weather conditions
typedef struct {
    int temperature; // in Celsius
    char weather[20]; // rain, sun, cloud, etc.
} weather_t;

// Function to generate a random weather condition
weather_t* get_weather(void) {
    int temp = (rand() % 100) + MIN_TEMP;
    char weather[20];

    // Generate a random weather condition
    switch (rand() % 4) {
        case 0:
            strcpy(weather, "rain");
            break;
        case 1:
            strcpy(weather, "sun");
            break;
        case 2:
            strcpy(weather, "cloud");
            break;
        case 3:
            strcpy(weather, "snow");
            break;
    }

    // Create a weather struct with the generated values
    weather_t* w = malloc(sizeof(weather_t));
    w->temperature = temp;
    strcpy(w->weather, weather);
    return w;
}

int main(void) {
    // Initialize the weather
    weather_t* current_weather = get_weather();

    // Print the current weather
    printf("Current Weather: %s, %d°C\n", current_weather->weather, current_weather->temperature);

    // Simulate the weather for 5 minutes
    for (int i = 0; i < 5; i++) {
        // Generate a new weather condition every minute
        current_weather = get_weather();

        // Print the new weather
        printf("Current Weather: %s, %d°C\n", current_weather->weather, current_weather->temperature);

        // Sleep for 1 minute
        sleep(1);
    }

    return 0;
}