//LLAMA2-13B DATASET v1.0 Category: Weather simulation ; Style: satisfied
// Weather Simulation v1.0

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WEATHER_TYPES 4
#define DAY_LENGTH 24

// Struct to store weather data
typedef struct {
    int temperature;
    char weather_type[10];
} weather_data_t;

// Function to generate random weather data
weather_data_t *generate_weather(void) {
    int i, j;
    weather_data_t *data;

    data = (weather_data_t *)malloc(sizeof(weather_data_t));

    // Generate random temperature (0-50)
    data->temperature = (int)(rand() % 50) - 25;

    // Generate random weather type (sunny, rainy, cloudy, snowy)
    for (i = 0; i < 4; i++) {
        j = (int)(rand() % 4);
        switch (j) {
            case 0:
                strcpy(data->weather_type, "sunny");
                break;
            case 1:
                strcpy(data->weather_type, "rainy");
                break;
            case 2:
                strcpy(data->weather_type, "cloudy");
                break;
            case 3:
                strcpy(data->weather_type, "snowy");
                break;
        }
    }

    return data;
}

// Function to print weather data
void print_weather(weather_data_t *data) {
    printf("Weather: %s\n", data->weather_type);
    printf("Temperature: %d\n", data->temperature);
}

// Main function
int main(void) {
    weather_data_t *data;
    int i, day;

    // Initialize weather data
    data = generate_weather();

    // Print weather data
    print_weather(data);

    // Loop for DAY_LENGTH days
    for (day = 0; day < DAY_LENGTH; day++) {
        // Generate random time (0-23)
        int time = (int)(rand() % 24);

        // Update weather data based on time
        switch (time / 6) {
            case 0:
                data->temperature += (int)(rand() % 10) - 5;
                break;
            case 6:
                data->temperature -= (int)(rand() % 10) - 5;
                break;
            default:
                break;
        }

        // Print weather data
        print_weather(data);

        // Sleep for 1 minute
        sleep(60);
    }

    // Free weather data
    free(data);

    return 0;
}