//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WEATHER_TYPES 5
#define WEATHER_TYPES_STRINGS { "Sunny", "Rainy", "Cloudy", "Snowy", "Stormy" }

typedef struct {
    char *name;
    int temperature;
    int humidity;
    int windSpeed;
} Weather;

void initWeather(Weather *weather) {
    weather->name = malloc(32 * sizeof(char));
    weather->temperature = rand() % 40 + 1;
    weather->humidity = rand() % 101;
    weather->windSpeed = rand() % 21 + 1;
}

void printWeather(Weather *weather) {
    printf("Weather: %s\n", weather->name);
    printf("Temperature: %d°C\n", weather->temperature);
    printf("Humidity: %d%%\n", weather->humidity);
    printf("Wind Speed: %d m/s\n", weather->windSpeed);
}

int main() {
    srand(time(NULL));

    int numWeathers = rand() % 10 + 1;
    Weather *weathers = malloc(numWeathers * sizeof(Weather));

    for (int i = 0; i < numWeathers; i++) {
        initWeather(&weathers[i]);
    }

    int currentWeather = 0;

    while (1) {
        system("clear");

        printWeather(&weathers[currentWeather]);

        char choice;
        printf("Press any key to change weather or 'q' to quit: ");
        scanf(" %c", &choice);

        if (choice == 'q') {
            break;
        } else if (choice == '\n') {
            currentWeather = (currentWeather + 1) % numWeathers;
        }
    }

    free(weathers);

    return 0;
}