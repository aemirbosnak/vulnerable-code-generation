//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_WEATHER_TYPES 10

typedef struct {
    char name[20];
    int temperature;
    int humidity;
    int windSpeed;
    int weatherType;
} City;

City cities[MAX_CITIES];
char weatherTypes[MAX_WEATHER_TYPES][20];
int numCities = 0;
int numWeatherTypes = 0;

void generateRandomCity() {
    int i;
    for (i = 0; i < MAX_CITIES; i++) {
        if (cities[i].name[0] == '\0') {
            sprintf(cities[i].name, "City %d", i + 1);
            cities[i].temperature = rand() % 100;
            cities[i].humidity = rand() % 100;
            cities[i].windSpeed = rand() % 100;
            cities[i].weatherType = rand() % numWeatherTypes;
            numCities++;
            break;
        }
    }
}

void generateRandomWeatherType() {
    char input[20];
    printf("Enter a new weather type: ");
    scanf("%s", input);
    strcpy(weatherTypes[numWeatherTypes], input);
    numWeatherTypes++;
}

void printCityWeather(int cityIndex) {
    printf("City: %s\n", cities[cityIndex].name);
    printf("Temperature: %d\n", cities[cityIndex].temperature);
    printf("Humidity: %d\n", cities[cityIndex].humidity);
    printf("Wind Speed: %d\n", cities[cityIndex].windSpeed);
    printf("Weather Type: %s\n\n", weatherTypes[cities[cityIndex].weatherType]);
}

void printAllCityWeather() {
    int i;
    for (i = 0; i < numCities; i++) {
        printCityWeather(i);
    }
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("\nWeather Simulation\n");
        printf("1. Generate random city\n");
        printf("2. Generate random weather type\n");
        printf("3. Print all city weather\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            generateRandomCity();
            break;
        case 2:
            generateRandomWeatherType();
            break;
        case 3:
            printAllCityWeather();
            break;
        case 4:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}