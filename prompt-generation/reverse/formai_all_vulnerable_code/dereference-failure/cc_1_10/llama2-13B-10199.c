//LLAMA2-13B DATASET v1.0 Category: Weather simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define DAY_COUNT 365
#define HOUR_COUNT 24
#define MINUTE_COUNT 60
#define SECOND_COUNT 60

// Structure to hold weather data
typedef struct {
    int day;      // Day of the year (1-365)
    int hour;     // Hour of the day (1-24)
    int minute;   // Minute of the hour (1-60)
    int second;   // Second of the minute (1-60)
    float temperature; // Temperature in Celsius
    float humidity;   // Humidity as a percentage
    float windSpeed;  // Wind speed in kilometers per hour
} weather_data_t;

// Function to generate random weather data
weather_data_t* generate_weather_data(void) {
    weather_data_t* data = malloc(sizeof(weather_data_t));
    data->day = rand() % DAY_COUNT;
    data->hour = rand() % HOUR_COUNT;
    data->minute = rand() % MINUTE_COUNT;
    data->second = rand() % SECOND_COUNT;
    data->temperature = (float)(rand() % 100) / 10.0;
    data->humidity = (float)(rand() % 100) / 10.0;
    data->windSpeed = (float)(rand() % 100) / 10.0;
    return data;
}

// Function to print the weather data
void print_weather(weather_data_t* data) {
    printf("Weather on %d %d %d %d:\n", data->day, data->hour, data->minute, data->second);
    printf("Temperature: %f C\n", data->temperature);
    printf("Humidity: %f %%\n", data->humidity);
    printf("Wind Speed: %f km/h\n", data->windSpeed);
}

int main(void) {
    srand(time(NULL)); // Seed the random number generator

    // Generate 10000 weather data points
    weather_data_t* data[10000];
    for (int i = 0; i < 10000; i++) {
        data[i] = generate_weather_data();
    }

    // Print the weather data
    for (int i = 0; i < 10000; i++) {
        print_weather(data[i]);
    }

    return 0;
}