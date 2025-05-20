//GEMINI-pro DATASET v1.0 Category: Weather simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a weather station
typedef struct {
    char *name;
    double temperature;
    double humidity;
    double wind_speed;
    double wind_direction;
    double pressure;
} weather_station;

// Function to create a new weather station
weather_station *create_weather_station(char *name) {
    weather_station *station = malloc(sizeof(weather_station));
    station->name = name;
    station->temperature = 0.0;
    station->humidity = 0.0;
    station->wind_speed = 0.0;
    station->wind_direction = 0.0;
    station->pressure = 0.0;
    return station;
}

// Function to generate random weather data
void generate_weather_data(weather_station *station) {
    // Generate a random temperature between -20 and 40 degrees Celsius
    station->temperature = -20.0 + (40.0 - -20.0) * ((double) rand() / (double) RAND_MAX);

    // Generate a random humidity between 0 and 100 percent
    station->humidity = 0.0 + (100.0 - 0.0) * ((double) rand() / (double) RAND_MAX);

    // Generate a random wind speed between 0 and 100 kilometers per hour
    station->wind_speed = 0.0 + (100.0 - 0.0) * ((double) rand() / (double) RAND_MAX);

    // Generate a random wind direction between 0 and 360 degrees
    station->wind_direction = 0.0 + (360.0 - 0.0) * ((double) rand() / (double) RAND_MAX);

    // Generate a random pressure between 950 and 1050 millibars
    station->pressure = 950.0 + (1050.0 - 950.0) * ((double) rand() / (double) RAND_MAX);
}

// Function to print the weather data for a weather station
void print_weather_data(weather_station *station) {
    printf("Weather data for %s:\n", station->name);
    printf("Temperature: %.1f degrees Celsius\n", station->temperature);
    printf("Humidity: %.1f percent\n", station->humidity);
    printf("Wind speed: %.1f kilometers per hour\n", station->wind_speed);
    printf("Wind direction: %.1f degrees\n", station->wind_direction);
    printf("Pressure: %.1f millibars\n", station->pressure);
    printf("\n");
}

// Main function
int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Create an array of weather stations
    weather_station *stations[] = {
        create_weather_station("London"),
        create_weather_station("Paris"),
        create_weather_station("Berlin"),
        create_weather_station("Madrid"),
        create_weather_station("Rome"),
    };

    // Generate weather data for each weather station
    for (int i = 0; i < 5; i++) {
        generate_weather_data(stations[i]);
    }

    // Print the weather data for each weather station
    for (int i = 0; i < 5; i++) {
        print_weather_data(stations[i]);
    }

    // Free the memory allocated for each weather station
    for (int i = 0; i < 5; i++) {
        free(stations[i]);
    }

    return 0;
}