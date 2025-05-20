//GEMINI-pro DATASET v1.0 Category: Weather simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Weather conditions
enum WeatherCondition {
    SUNNY,
    CLOUDY,
    RAINY,
    STORMY
};

// Weather simulation
void simulate_weather(enum WeatherCondition* weather, int num_days) {
    // Initialize random number generator
    srand(time(NULL));

    // Simulate weather for each day
    for (int i = 0; i < num_days; i++) {
        // Generate a random weather condition
        *weather = rand() % 4;
    }
}

// Print weather forecast
void print_weather_forecast(enum WeatherCondition* weather, int num_days) {
    printf("Weather Forecast:\n");
    for (int i = 0; i < num_days; i++) {
        switch (weather[i]) {
            case SUNNY:
                printf("Day %d: Sunny\n", i + 1);
                break;
            case CLOUDY:
                printf("Day %d: Cloudy\n", i + 1);
                break;
            case RAINY:
                printf("Day %d: Rainy\n", i + 1);
                break;
            case STORMY:
                printf("Day %d: Stormy\n", i + 1);
                break;
        }
    }
}

int main() {
    // Number of days to simulate weather for
    int num_days = 7;

    // Allocate memory for weather conditions
    enum WeatherCondition* weather = malloc(sizeof(enum WeatherCondition) * num_days);

    // Simulate weather for each day
    simulate_weather(weather, num_days);

    // Print weather forecast
    print_weather_forecast(weather, num_days);

    // Free allocated memory
    free(weather);

    return 0;
}