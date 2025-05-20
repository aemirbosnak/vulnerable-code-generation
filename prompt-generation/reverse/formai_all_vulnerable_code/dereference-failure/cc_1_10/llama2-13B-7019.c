//LLAMA2-13B DATASET v1.0 Category: Weather simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for weather conditions
#define CLEAR 0
#define CLOUDY 1
#define RAINY 2
#define SUNNY 3

// Define a struct for weather data
typedef struct {
    int condition;
    int temperature;
    int humidity;
} weather_t;

// Function to generate random weather data
weather_t *generate_weather() {
    int i;
    weather_t *weather = (weather_t *)malloc(sizeof(weather_t));
    for (i = 0; i < 3; i++) {
        weather->condition = (int)(rand() % 4) % 2 ? CLOUDY : CLEAR;
        weather->temperature = (int)(rand() % 20) - 10;
        weather->humidity = (int)(rand() % 100) + 50;
    }
    return weather;
}

// Function to print weather data
void print_weather(weather_t *weather) {
    printf("Weather: %s\n", (weather->condition == CLEAR) ? "Clear" : "Cloudy");
    printf("Temperature: %d\n", weather->temperature);
    printf("Humidity: %d\n", weather->humidity);
}

// Function to simulate weather for 5 minutes
void simulate_weather(weather_t *weather) {
    int i;
    for (i = 0; i < 300; i++) {
        if (weather->condition == CLOUDY) {
            // 50% chance of rain
            if (rand() % 2 == 0) {
                weather->condition = RAINY;
            }
        } else if (weather->condition == RAINY) {
            // 50% chance of clearing up
            if (rand() % 2 == 0) {
                weather->condition = CLEAR;
            }
        }
        print_weather(weather);
        sleep(1);
    }
}

int main() {
    weather_t *weather = generate_weather();
    simulate_weather(weather);
    free(weather);
    return 0;
}