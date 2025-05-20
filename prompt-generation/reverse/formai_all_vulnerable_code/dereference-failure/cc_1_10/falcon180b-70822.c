//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WEATHER_TYPES 10
#define WEATHER_TYPES_STRINGS {"Sunny", "Cloudy", "Rainy", "Thunderstorm", "Hail", "Snow", "Fog", "Windy", "Tornado", "Hurricane"}

typedef struct {
    char *name;
    int icon;
    int temperature;
    int humidity;
    int wind_speed;
    int precipitation;
} Weather;

void initWeather(Weather *weather) {
    weather->name = malloc(20 * sizeof(char));
    weather->icon = rand() % WEATHER_TYPES;
    weather->temperature = rand() % 40 - 10;
    weather->humidity = rand() % 100;
    weather->wind_speed = rand() % 20 + 5;
    weather->precipitation = rand() % 100;

    switch (weather->icon) {
        case 0:
            strcpy(weather->name, "Sunny");
            break;
        case 1:
            strcpy(weather->name, "Cloudy");
            break;
        case 2:
            strcpy(weather->name, "Rainy");
            break;
        case 3:
            strcpy(weather->name, "Thunderstorm");
            break;
        case 4:
            strcpy(weather->name, "Hail");
            break;
        case 5:
            strcpy(weather->name, "Snow");
            break;
        case 6:
            strcpy(weather->name, "Fog");
            break;
        case 7:
            strcpy(weather->name, "Windy");
            break;
        case 8:
            strcpy(weather->name, "Tornado");
            break;
        case 9:
            strcpy(weather->name, "Hurricane");
            break;
    }
}

void printWeather(Weather *weather) {
    printf("Weather: %s\n", weather->name);
    printf("Icon: %d\n", weather->icon);
    printf("Temperature: %d°C\n", weather->temperature);
    printf("Humidity: %d%%\n", weather->humidity);
    printf("Wind Speed: %d km/h\n", weather->wind_speed);
    printf("Precipitation: %d%%\n", weather->precipitation);
    printf("\n");
}

int main() {
    srand(time(NULL));

    int num_days = 7;
    Weather weather[num_days];

    for (int i = 0; i < num_days; i++) {
        initWeather(&weather[i]);
        printWeather(&weather[i]);
    }

    return 0;
}