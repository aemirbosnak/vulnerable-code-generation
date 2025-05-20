//GEMINI-pro DATASET v1.0 Category: Weather simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the weather types
enum weather_type {
    SUNNY,
    CLOUDY,
    RAINY,
    STORMY
};

// Define the temperature range
#define MIN_TEMP 0
#define MAX_TEMP 40

// Define the humidity range
#define MIN_HUMIDITY 0
#define MAX_HUMIDITY 100

// Define the wind speed range
#define MIN_WIND_SPEED 0
#define MAX_WIND_SPEED 100

// Define the precipitation range
#define MIN_PRECIPITATION 0
#define MAX_PRECIPITATION 100

// Define the number of days to simulate
#define NUM_DAYS 30

// Generate a random number between min and max
int random_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Simulate the weather for a single day
void simulate_weather(int *weather, int *temperature, int *humidity, int *wind_speed, int *precipitation) {
    // Generate a random weather type
    *weather = random_range(SUNNY, STORMY);

    // Generate a random temperature
    *temperature = random_range(MIN_TEMP, MAX_TEMP);

    // Generate a random humidity
    *humidity = random_range(MIN_HUMIDITY, MAX_HUMIDITY);

    // Generate a random wind speed
    *wind_speed = random_range(MIN_WIND_SPEED, MAX_WIND_SPEED);

    // Generate a random precipitation
    *precipitation = random_range(MIN_PRECIPITATION, MAX_PRECIPITATION);
}

// Print the weather forecast for a single day
void print_weather_forecast(int weather, int temperature, int humidity, int wind_speed, int precipitation) {
    // Print the weather type
    switch (weather) {
        case SUNNY:
            printf("Sunny");
            break;
        case CLOUDY:
            printf("Cloudy");
            break;
        case RAINY:
            printf("Rainy");
            break;
        case STORMY:
            printf("Stormy");
            break;
    }

    // Print the temperature
    printf(", %d degrees Celsius", temperature);

    // Print the humidity
    printf(", %d%% humidity", humidity);

    // Print the wind speed
    printf(", %d km/h wind speed", wind_speed);

    // Print the precipitation
    printf(", %d%% chance of precipitation", precipitation);

    // Print a newline
    printf("\n");
}

// Simulate the weather for a number of days
void simulate_weather_forecast(int num_days) {
    // Allocate memory for the weather forecast
    int *weather = malloc(num_days * sizeof(int));
    int *temperature = malloc(num_days * sizeof(int));
    int *humidity = malloc(num_days * sizeof(int));
    int *wind_speed = malloc(num_days * sizeof(int));
    int *precipitation = malloc(num_days * sizeof(int));

    // Simulate the weather for each day
    for (int i = 0; i < num_days; i++) {
        simulate_weather(&weather[i], &temperature[i], &humidity[i], &wind_speed[i], &precipitation[i]);
    }

    // Print the weather forecast for each day
    for (int i = 0; i < num_days; i++) {
        print_weather_forecast(weather[i], temperature[i], humidity[i], wind_speed[i], precipitation[i]);
    }

    // Free the memory allocated for the weather forecast
    free(weather);
    free(temperature);
    free(humidity);
    free(wind_speed);
    free(precipitation);
}

// Main function
int main(void) {
    // Seed the random number generator
    srand(time(NULL));

    // Simulate the weather forecast for a number of days
    simulate_weather_forecast(NUM_DAYS);

    return 0;
}