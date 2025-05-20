//LLAMA2-13B DATASET v1.0 Category: Weather simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 30
#define MIN_TEMP 0

// Structure to store weather data
typedef struct {
    int temperature;  // Current temperature
    int humidity;    // Current humidity
    int pressure;   // Current pressure
    int windSpeed;  // Current wind speed
} weather_data_t;

// Function to generate random weather data
weather_data_t* generate_weather() {
    weather_data_t* weather = (weather_data_t*) malloc(sizeof(weather_data_t));

    // Generate random temperature
    weather->temperature = (int) (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP;

    // Generate random humidity
    weather->humidity = (int) (rand() % (100 - 0 + 1)) + 0;

    // Generate random pressure
    weather->pressure = (int) (rand() % (1000 - 0 + 1)) + 0;

    // Generate random wind speed
    weather->windSpeed = (int) (rand() % (100 - 0 + 1)) + 0;

    return weather;
}

// Function to print weather data
void print_weather(weather_data_t* weather) {
    printf("Weather Report:\n");
    printf("Temperature: %d\n", weather->temperature);
    printf("Humidity: %d\n", weather->humidity);
    printf("Pressure: %d\n", weather->pressure);
    printf("Wind Speed: %d\n", weather->windSpeed);
}

// Main function
int main() {
    // Create a weather data structure
    weather_data_t* weather = generate_weather();

    // Print the weather data
    print_weather(weather);

    // Free the weather data structure
    free(weather);

    return 0;
}