//LLAMA2-13B DATASET v1.0 Category: Weather simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WEATHER_REPORT_WIDTH 80
#define WEATHER_REPORT_HEIGHT 24

// Structure to hold the weather data
typedef struct {
    char day[10];
    char high_temperature[10];
    char low_temperature[10];
    char weather_condition[20];
} weather_data_t;

// Function to generate a random weather condition
void generate_weather(weather_data_t *data) {
    int day_index = rand() % 7; // 0-6 for Sunday-Saturday
    char *day_names[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    strcpy(data->day, day_names[day_index]);

    int high_temperature = (rand() % 30) + 60; // 60-90 degrees Fahrenheit
    int low_temperature = (rand() % 30) + 40; // 40-70 degrees Fahrenheit
    sprintf(data->high_temperature, "%d", high_temperature);
    sprintf(data->low_temperature, "%d", low_temperature);

    // Generate a random weather condition
    if (rand() % 2) {
        strcpy(data->weather_condition, "Partly Cloudy");
    } else {
        strcpy(data->weather_condition, "Sunny");
    }
}

// Function to display the weather report
void display_weather(weather_data_t *data) {
    // Clear the screen
    system("cls");

    // Print the weather report header
    printf("Weather Report for %s\n", data->day);
    printf("High: %s\n", data->high_temperature);
    printf("Low: %s\n", data->low_temperature);
    printf("Weather Condition: %s\n", data->weather_condition);

    // Print a line of weather-themed characters
    for (int i = 0; i < WEATHER_REPORT_WIDTH; i++) {
        printf("-");
    }
    printf("\n");

    // Print the weather data in a table format
    for (int i = 0; i < WEATHER_REPORT_HEIGHT; i++) {
        printf("%s\n", data->weather_condition);
    }

    // Print a final line of weather-themed characters
    for (int i = 0; i < WEATHER_REPORT_WIDTH; i++) {
        printf("-");
    }
    printf("\n");
}

int main() {
    weather_data_t data;

    // Generate the weather data
    generate_weather(&data);

    // Display the weather report
    display_weather(&data);

    return 0;
}