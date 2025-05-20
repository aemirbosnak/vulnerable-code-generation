//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365

struct City {
    char name[20];
    int temperature[MAX_DAYS];
    int humidity[MAX_DAYS];
};

void generateWeather(struct City *cities, int numCities, int day) {
    srand(time(NULL));
    for (int i = 0; i < numCities; i++) {
        int temp = rand() % 50 + 1;
        int humidity = rand() % 101;
        cities[i].temperature[day] = temp;
        cities[i].humidity[day] = humidity;
    }
}

void printWeather(struct City *cities, int numCities, int day) {
    printf("Weather report for day %d:\n", day);
    for (int i = 0; i < numCities; i++) {
        printf("%s: %d degrees Celsius, %d%% humidity\n", cities[i].name, cities[i].temperature[day], cities[i].humidity[day]);
    }
}

int main() {
    int numCities;
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);

    struct City cities[numCities];

    for (int i = 0; i < numCities; i++) {
        printf("Enter the name of city %d: ", i + 1);
        scanf("%s", cities[i].name);
    }

    int day = 0;
    while (day < MAX_DAYS) {
        generateWeather(cities, numCities, day);
        printWeather(cities, numCities, day);
        day++;
    }

    return 0;
}