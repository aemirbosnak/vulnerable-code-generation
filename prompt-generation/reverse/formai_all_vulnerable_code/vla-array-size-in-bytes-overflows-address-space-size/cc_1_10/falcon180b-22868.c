//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_CITIES 20
#define MAX_DAYS 30

struct City {
    char name[50];
    int temperature[MAX_DAYS];
    int precipitation[MAX_DAYS];
};

void generateWeather(struct City *cities, int numCities, int numDays) {
    int i, j;
    for (i = 0; i < numCities; i++) {
        for (j = 0; j < numDays; j++) {
            cities[i].temperature[j] = rand() % 30 + 1;
            cities[i].precipitation[j] = rand() % 10 + 1;
        }
    }
}

void printWeather(struct City *cities, int numCities, int numDays) {
    int i, j;
    for (i = 0; i < numCities; i++) {
        printf("City: %s\n", cities[i].name);
        printf("Weather forecast for the next %d days:\n", numDays);
        for (j = 0; j < numDays; j++) {
            printf("Day %d: Temperature = %d°C, Precipitation = %d mm\n", j+1, cities[i].temperature[j], cities[i].precipitation[j]);
        }
        printf("\n");
    }
}

int main() {
    int numCities, numDays;
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);
    printf("Enter the number of days for the weather forecast: ");
    scanf("%d", &numDays);

    struct City cities[numCities];

    printf("Enter the names of the cities:\n");
    for (int i = 0; i < numCities; i++) {
        scanf("%s", cities[i].name);
    }

    generateWeather(cities, numCities, numDays);

    printf("The weather forecast for the next %d days is as follows:\n", numDays);

    printWeather(cities, numCities, numDays);

    return 0;
}