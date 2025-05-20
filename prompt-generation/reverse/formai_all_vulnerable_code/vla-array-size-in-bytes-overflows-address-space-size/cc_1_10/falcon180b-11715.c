//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_DAYS 30

typedef struct {
    char name[50];
    int temperature;
    int humidity;
    int precipitation;
} City;

void generate_random_weather(City* city) {
    city->temperature = rand() % 40 + 1;
    city->humidity = rand() % 101;
    city->precipitation = rand() % 4;
}

int main() {
    int num_cities;
    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);

    if (num_cities > MAX_CITIES) {
        printf("Error: too many cities.\n");
        return 1;
    }

    City cities[num_cities];

    for (int i = 0; i < num_cities; i++) {
        printf("Enter the name of city %d: ", i + 1);
        scanf("%s", cities[i].name);
        generate_random_weather(&cities[i]);
    }

    int num_days;
    printf("Enter the number of days to simulate: ");
    scanf("%d", &num_days);

    if (num_days > MAX_DAYS) {
        printf("Error: too many days.\n");
        return 1;
    }

    for (int day = 1; day <= num_days; day++) {
        for (int i = 0; i < num_cities; i++) {
            printf("Day %d weather in %s: %d degrees, %d%% humidity, %d mm precipitation\n", day, cities[i].name, cities[i].temperature, cities[i].humidity, cities[i].precipitation);
        }
    }

    return 0;
}