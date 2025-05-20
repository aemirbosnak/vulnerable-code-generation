//LLAMA2-13B DATASET v1.0 Category: Weather simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WEATHER_TYPES 5
#define DAYS_IN_WEEK 7

// Structure to hold weather data
typedef struct {
    char day_name[7][10];  // Day names (e.g. "Monday", "Tuesday", etc.)
    char weather_type[5][20];  // Weather types (e.g. "Sunny", "Rainy", etc.)
    int temperature[7];  // Temperature ranges for each day
} weather_data_t;

// Function to generate random weather data
weather_data_t *generate_weather_data(void) {
    weather_data_t *data = malloc(sizeof(weather_data_t));

    // Generate random day names
    for (int i = 0; i < DAYS_IN_WEEK; i++) {
        data->day_name[i][0] = 'M';  // Monday
        data->day_name[i][1] = 'T';  // Tuesday
        data->day_name[i][2] = 'W';  // Wednesday
        data->day_name[i][3] = 'T';  // Thursday
        data->day_name[i][4] = 'F';  // Friday
        data->day_name[i][5] = 'S';  // Saturday
        data->day_name[i][6] = 'D';  // Sunday
    }

    // Generate random weather types
    for (int i = 0; i < WEATHER_TYPES; i++) {
        data->weather_type[i][0] = 'S';  // Sunny
        data->weather_type[i][1] = 'R';  // Rainy
        data->weather_type[i][2] = 'C';  // Cloudy
        data->weather_type[i][3] = 'P';  // Partly Cloudy
        data->weather_type[i][4] = 'H';  // Hazy
        data->weather_type[i][5] = 'O';  // Overcast
    }

    // Generate random temperature ranges
    for (int i = 0; i < DAYS_IN_WEEK; i++) {
        data->temperature[i] = rand() % 100 + 20;  // Temperature range between 20°C and 80°C
    }

    return data;
}

// Function to print weather data
void print_weather(weather_data_t *data) {
    printf("🌞 Happy Weather Report 🌞\n");

    for (int i = 0; i < DAYS_IN_WEEK; i++) {
        printf("Day %d: %s\n", i + 1, data->day_name[i]);

        for (int j = 0; j < WEATHER_TYPES; j++) {
            printf("  Weather: %s\n", data->weather_type[j]);
        }

        printf("  Temperature: %d°C\n\n", data->temperature[i]);
    }
}

int main(void) {
    weather_data_t *data = generate_weather_data();
    print_weather(data);

    return 0;
}