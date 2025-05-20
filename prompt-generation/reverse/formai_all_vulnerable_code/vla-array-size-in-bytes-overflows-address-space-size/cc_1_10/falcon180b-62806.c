//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_DAYS 30

struct City {
    char name[20];
    int temperature;
    int humidity;
    int windSpeed;
};

void initializeCities(struct City cities[], int numCities) {
    for (int i = 0; i < numCities; i++) {
        cities[i].temperature = rand() % 100;
        cities[i].humidity = rand() % 100;
        cities[i].windSpeed = rand() % 50;
    }
}

void printCities(struct City cities[], int numCities) {
    for (int i = 0; i < numCities; i++) {
        printf("City %d: Temperature - %d, Humidity - %d, Wind Speed - %d\n", i+1, cities[i].temperature, cities[i].humidity, cities[i].windSpeed);
    }
}

void simulateWeather(struct City cities[], int numCities) {
    for (int i = 0; i < numCities; i++) {
        cities[i].temperature += rand() % 10 - 5;
        cities[i].humidity += rand() % 10 - 5;
        cities[i].windSpeed += rand() % 10 - 5;
    }
}

int main() {
    srand(time(NULL));

    int numCities;
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);

    struct City cities[numCities];

    initializeCities(cities, numCities);

    int numDays;
    printf("Enter the number of days to simulate: ");
    scanf("%d", &numDays);

    for (int i = 0; i < numDays; i++) {
        simulateWeather(cities, numCities);
        printCities(cities, numCities);
    }

    return 0;
}