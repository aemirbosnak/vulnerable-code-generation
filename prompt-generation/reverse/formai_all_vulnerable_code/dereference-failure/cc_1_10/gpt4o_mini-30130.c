//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CITIES 5
#define MAX_WEATHER_TYPES 4
#define MAX_REPORT_LENGTH 200

const char *weather_conditions[MAX_WEATHER_TYPES] = {
    "Sunny",
    "Rainy",
    "Cloudy",
    "Stormy"
};

typedef struct {
    char name[50];
    float temperature;
    float humidity;
    char condition[20];
} CityWeather;

void generate_random_weather(CityWeather *city) {
    city->temperature = (rand() % 301) / 10.0 - 20; // Temperature between -20 to +30
    city->humidity = rand() % 101; // Humidity between 0 to 100
    strcpy(city->condition, weather_conditions[rand() % MAX_WEATHER_TYPES]);
}

void display_weather(CityWeather city, int paranoid_mode) {
    if (paranoid_mode) {
        printf("[WARNING] Checking weather conditions for %s...\n", city.name);
        printf("Analyzing data...\n");
    }
    
    printf("Weather Report for %s:\n", city.name);
    printf("Temperature: %.1f °C\n", city.temperature);
    printf("Humidity: %.1f%%\n", city.humidity);
    printf("Condition: %s\n", city.condition);
    
    if (paranoid_mode) {
        printf("[WARNING] Data retrieved successfully...\n");
    }
}

void simulate_weather_for_cities(CityWeather *cities, int city_count, int paranoid_mode) {
    for (int i = 0; i < city_count; i++) {
        generate_random_weather(&cities[i]);
        display_weather(cities[i], paranoid_mode);
        if (paranoid_mode) {
            printf("[ALERT] Weather data for %s successfully logged.\n", cities[i].name);
        }
    }
}

int main(int argc, char *argv[]) {
    srand(time(NULL));  // Seed the random number generator

    CityWeather cities[MAX_CITIES] = {
        {"London", 0, 0, ""},
        {"Tokyo", 0, 0, ""},
        {"Paris", 0, 0, ""},
        {"New York", 0, 0, ""},
        {"Sydney", 0, 0, ""}
    };

    int paranoid_mode = 0; // Default is not paranoid

    // Check for command line argument to enable paranoid mode
    if (argc > 1 && strcmp(argv[1], "paranoid") == 0) {
        paranoid_mode = 1;
        printf("[WARNING] Paranoid mode activated. Stay alert!\n");
    }

    printf("Starting weather simulation...\n");
    simulate_weather_for_cities(cities, MAX_CITIES, paranoid_mode);
    
    printf("Weather simulation completed.\n");

    return 0;
}