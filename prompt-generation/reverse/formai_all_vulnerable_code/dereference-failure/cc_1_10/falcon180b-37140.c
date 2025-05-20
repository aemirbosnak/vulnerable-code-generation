//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365

typedef struct {
    char name[50];
    int temperature;
    int humidity;
    int windSpeed;
} City;

void generateRandomCity(City* city) {
    city->temperature = rand() % 40 + 1;
    city->humidity = rand() % 101;
    city->windSpeed = rand() % 101;
}

void printCity(City city) {
    printf("%s: Temperature %dC, Humidity %d%% Wind Speed %d km/h\n", city.name, city.temperature, city.humidity, city.windSpeed);
}

int main(int argc, char* argv[]) {
    if(argc < 3) {
        printf("Usage: %s <number_of_cities> <number_of_days>\n", argv[0]);
        return 1;
    }

    int numCities = atoi(argv[1]);
    int numDays = atoi(argv[2]);

    City cities[MAX_CITIES];
    for(int i=0; i<numCities; i++) {
        generateRandomCity(&cities[i]);
        printf("Generated city %s\n", cities[i].name);
    }

    for(int day=1; day<=numDays; day++) {
        for(int i=0; i<numCities; i++) {
            City* city = &cities[i];
            city->temperature += rand() % 6 - 3;
            if(city->temperature < 0) city->temperature = 0;
            if(city->temperature > 40) city->temperature = 40;

            city->humidity += rand() % 6 - 3;
            if(city->humidity < 0) city->humidity = 0;
            if(city->humidity > 101) city->humidity = 101;

            city->windSpeed += rand() % 6 - 3;
            if(city->windSpeed < 0) city->windSpeed = 0;
            if(city->windSpeed > 101) city->windSpeed = 101;
        }
    }

    for(int i=0; i<numCities; i++) {
        printCity(cities[i]);
    }

    return 0;
}