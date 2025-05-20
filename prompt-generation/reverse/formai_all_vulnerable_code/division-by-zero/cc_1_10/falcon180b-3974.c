//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_WEATHER_TYPES 5
#define MAX_TEMPERATURES 50

typedef struct {
    char name[20];
    int temperature;
} City;

typedef struct {
    char name[20];
    int probability;
} WeatherType;

int main() {
    int numCities;
    printf("Enter the number of cities to simulate: ");
    scanf("%d", &numCities);

    City cities[numCities];
    for (int i = 0; i < numCities; i++) {
        printf("Enter the name of city %d: ", i+1);
        scanf("%s", cities[i].name);
        cities[i].temperature = rand() % MAX_TEMPERATURES;
    }

    int numWeatherTypes;
    printf("Enter the number of weather types to simulate: ");
    scanf("%d", &numWeatherTypes);

    WeatherType weatherTypes[numWeatherTypes];
    for (int i = 0; i < numWeatherTypes; i++) {
        printf("Enter the name of weather type %d: ", i+1);
        scanf("%s", weatherTypes[i].name);
        weatherTypes[i].probability = rand() % 101;
    }

    int currentWeatherType = 0;
    int currentTemperature = rand() % MAX_TEMPERATURES;

    while (1) {
        printf("\nCurrent weather: %s - %d degrees\n", weatherTypes[currentWeatherType].name, currentTemperature);

        for (int i = 0; i < numCities; i++) {
            if (currentTemperature < cities[i].temperature) {
                cities[i].temperature -= 1;
            } else if (currentTemperature > cities[i].temperature) {
                cities[i].temperature += 1;
            }
        }

        int totalProbability = 0;
        for (int i = 0; i < numWeatherTypes; i++) {
            totalProbability += weatherTypes[i].probability;
        }

        int randomNumber = rand() % totalProbability;

        for (int i = 0; i < numWeatherTypes; i++) {
            if (randomNumber <= weatherTypes[i].probability) {
                currentWeatherType = i;
                break;
            }
        }

        currentTemperature = rand() % MAX_TEMPERATURES;
    }

    return 0;
}