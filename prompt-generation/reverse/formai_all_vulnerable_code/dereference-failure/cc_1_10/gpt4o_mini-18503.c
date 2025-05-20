//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CITY_COUNT 5
#define DAYS_COUNT 7

typedef struct {
    char name[30];
    float temperature;
    float humidity;
    float wind_speed;
} Weather;

void initialize_weather(Weather *weather) {
    const char *cities[CITY_COUNT] = {"New York", "Los Angeles", "Chicago", "Houston", "Phoenix"};
    for (int i = 0; i < CITY_COUNT; i++) {
        snprintf(weather[i].name, sizeof(weather[i].name), "%s", cities[i]);
        weather[i].temperature = (rand() % 61) - 20; // Temperature between -20 and 40 degrees Celsius
        weather[i].humidity = (rand() % 101); // Humidity from 0% to 100%
        weather[i].wind_speed = (rand() % 101) / 10.0; // Wind speed between 0.0 and 10.0 m/s
    }
}

void display_weather(Weather *weather) {
    printf("%-15s %-15s %-15s %-15s\n", "City", "Temperature(°C)", "Humidity(%)", "Wind Speed(m/s)");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < CITY_COUNT; i++) {
        printf("%-15s %-15.2f %-15.2f %-15.2f\n", 
                weather[i].name, weather[i].temperature, weather[i].humidity, weather[i].wind_speed);
    }
}

void simulate_weather_forecast(Weather *weather) {
    Weather daily_forecast[CITY_COUNT][DAYS_COUNT];
    
    for (int day = 0; day < DAYS_COUNT; day++) {
        initialize_weather(daily_forecast[day]);
    }

    printf("\nWeekly Weather Forecast:\n");
    for (int day = 0; day < DAYS_COUNT; day++) {
        printf("Day %d:\n", day + 1);
        display_weather(daily_forecast[day]);
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // seed the random number generator
    Weather weather[CITY_COUNT];

    printf("Today's Weather Report:\n");
    initialize_weather(weather);
    display_weather(weather);

    simulate_weather_forecast(weather);

    return 0;
}