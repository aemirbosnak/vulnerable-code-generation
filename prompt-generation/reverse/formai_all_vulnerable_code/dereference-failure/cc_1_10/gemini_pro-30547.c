//GEMINI-pro DATASET v1.0 Category: Weather simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the possible weather conditions
enum weather {SUNNY, CLOUDY, RAINING, SNOWING};

// Define the structure of a weather simulation
struct weather_simulation {
    enum weather current_weather;  // The current weather condition
    int temperature;              // The current temperature in degrees Celsius
    int humidity;                 // The current humidity in percentage
    int wind_speed;               // The current wind speed in kilometers per hour
};

// Initialize a weather simulation with default values
struct weather_simulation init_weather_simulation() {
    struct weather_simulation simulation;
    simulation.current_weather = SUNNY;
    simulation.temperature = 20;
    simulation.humidity = 50;
    simulation.wind_speed = 10;
    return simulation;
}

// Update the weather simulation based on the current conditions
void update_weather_simulation(struct weather_simulation *simulation) {
    // Get the current time
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    // Update the current weather condition based on the time of day
    if (tm->tm_hour < 6 || tm->tm_hour >= 18) {
        simulation->current_weather = CLOUDY;
    } else if (tm->tm_hour >= 6 && tm->tm_hour < 12) {
        simulation->current_weather = SUNNY;
    } else if (tm->tm_hour >= 12 && tm->tm_hour < 18) {
        simulation->current_weather = RAINING;
    }

    // Update the temperature based on the current weather condition
    if (simulation->current_weather == SUNNY) {
        simulation->temperature += 5;
    } else if (simulation->current_weather == CLOUDY) {
        simulation->temperature -= 2;
    } else if (simulation->current_weather == RAINING) {
        simulation->temperature -= 5;
    }

    // Update the humidity based on the current weather condition
    if (simulation->current_weather == SUNNY) {
        simulation->humidity -= 5;
    } else if (simulation->current_weather == CLOUDY) {
        simulation->humidity += 5;
    } else if (simulation->current_weather == RAINING) {
        simulation->humidity += 10;
    }

    // Update the wind speed based on the current weather condition
    if (simulation->current_weather == SUNNY) {
        simulation->wind_speed += 2;
    } else if (simulation->current_weather == CLOUDY) {
        simulation->wind_speed -= 1;
    } else if (simulation->current_weather == RAINING) {
        simulation->wind_speed -= 5;
    }
}

// Print the current weather simulation
void print_weather_simulation(struct weather_simulation *simulation) {
    printf("Current weather: ");
    switch (simulation->current_weather) {
        case SUNNY:
            printf("Sunny");
            break;
        case CLOUDY:
            printf("Cloudy");
            break;
        case RAINING:
            printf("Raining");
            break;
        case SNOWING:
            printf("Snowing");
            break;
    }
    printf("\n");

    printf("Temperature: %d degrees Celsius\n", simulation->temperature);
    printf("Humidity: %d%%\n", simulation->humidity);
    printf("Wind speed: %d kilometers per hour\n", simulation->wind_speed);
}

// Main function
int main() {
    // Initialize the weather simulation
    struct weather_simulation simulation = init_weather_simulation();

    // Update the weather simulation for 24 hours
    for (int i = 0; i < 24; i++) {
        update_weather_simulation(&simulation);
        print_weather_simulation(&simulation);
        printf("\n");
    }

    return 0;
}