//LLAMA2-13B DATASET v1.0 Category: Weather simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for weather elements
#define MAX_TEMP 30
#define MIN_TEMP 0
#define MAX_WIND_SPEED 20
#define MIN_WIND_SPEED 5
#define MAX_HUMIDITY 90
#define MIN_HUMIDITY 50
#define MAX_PRESSURE 1000
#define MIN_PRESSURE 800

// Define structures for weather data
typedef struct {
    int temperature;
    int windSpeed;
    int humidity;
    int pressure;
} weather_data_t;

// Function to generate random weather data
weather_data_t *generate_weather() {
    int temperature, windSpeed, humidity, pressure;

    // Generate random temperature
    temperature = (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP;

    // Generate random wind speed
    windSpeed = (rand() % (MAX_WIND_SPEED - MIN_WIND_SPEED + 1)) + MIN_WIND_SPEED;

    // Generate random humidity
    humidity = (rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1)) + MIN_HUMIDITY;

    // Generate random pressure
    pressure = (rand() % (MAX_PRESSURE - MIN_PRESSURE + 1)) + MIN_PRESSURE;

    // Create weather data structure
    weather_data_t *weather = malloc(sizeof(weather_data_t));
    weather->temperature = temperature;
    weather->windSpeed = windSpeed;
    weather->humidity = humidity;
    weather->pressure = pressure;

    return weather;
}

// Function to print weather data
void print_weather(weather_data_t *weather) {
    printf("Weather Conditions:\n");
    printf("Temperature: %d degrees Celsius\n", weather->temperature);
    printf("Wind Speed: %d km/h\n", weather->windSpeed);
    printf("Humidity: %d %%\n", weather->humidity);
    printf("Pressure: %d mbar\n", weather->pressure);
}

int main() {
    // Create weather data structure
    weather_data_t *weather = generate_weather();

    // Print weather data
    print_weather(weather);

    // Free memory
    free(weather);

    return 0;
}