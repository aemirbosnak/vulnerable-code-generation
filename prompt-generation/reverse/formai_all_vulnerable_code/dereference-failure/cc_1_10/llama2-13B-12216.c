//LLAMA2-13B DATASET v1.0 Category: Weather simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a weather condition
typedef struct {
    char type; // Type of weather (e.g. rain, sunny, cloudy)
    int temperature; // Temperature in degrees Celsius
    int humidity; // Humidity as a percentage
} weather_t;

// Function to generate a random weather condition
weather_t *generate_weather() {
    int type = rand() % 3; // 0: rain, 1: sunny, 2: cloudy
    int temperature = rand() % 20 - 10; // Temperature between 0 and 20 degrees Celsius
    int humidity = rand() % 100; // Humidity between 0 and 100%

    weather_t *weather = malloc(sizeof(weather_t));
    weather->type = type;
    weather->temperature = temperature;
    weather->humidity = humidity;

    return weather;
}

// Function to simulate the weather for a given number of days
void simulate_weather(int days) {
    weather_t *current_weather = generate_weather();

    for (int i = 0; i < days; i++) {
        // Print the current weather condition
        printf("Day %d: %c, %d degrees Celsius, %d%% humidity\n",
               i + 1, current_weather->type, current_weather->temperature, current_weather->humidity);

        // Generate a new weather condition for the next day
        weather_t *next_weather = generate_weather();

        // Check if the next weather condition is different from the current one
        if (next_weather->type != current_weather->type ||
            next_weather->temperature != current_weather->temperature ||
            next_weather->humidity != current_weather->humidity) {
            // If the next weather condition is different, print a transition message
            printf("Transitioning from %c to %c...\n", current_weather->type, next_weather->type);
        }

        // Update the current weather condition with the new one
        current_weather = next_weather;
    }

    // Print a final message indicating the end of the simulation
    printf("Simulation ended after %d days\n", days);
}

int main() {
    simulate_weather(7); // Simulate the weather for 7 days
    return 0;
}