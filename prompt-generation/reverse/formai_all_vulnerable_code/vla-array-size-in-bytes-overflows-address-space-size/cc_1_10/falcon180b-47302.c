//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365

typedef struct {
    char name[20];
    int x;
    int y;
} City;

typedef struct {
    int temperature;
    int humidity;
} Weather;

int main() {
    srand(time(NULL));

    int num_cities;
    printf("How many cities? ");
    scanf("%d", &num_cities);

    City cities[num_cities];
    for (int i = 0; i < num_cities; i++) {
        printf("City %d name: ", i+1);
        scanf("%s", cities[i].name);
        cities[i].x = rand() % 100;
        cities[i].y = rand() % 100;
    }

    int num_days;
    printf("How many days? ");
    scanf("%d", &num_days);

    Weather weather[num_days];
    for (int i = 0; i < num_days; i++) {
        weather[i].temperature = rand() % 41 - 20;
        weather[i].humidity = rand() % 101;
    }

    for (int day = 1; day <= num_days; day++) {
        printf("Day %d:\n", day);
        for (int i = 0; i < num_cities; i++) {
            int distance = abs(cities[i].x - 50) + abs(cities[i].y - 50);
            weather[day].temperature += (distance / 10) - 5;
            weather[day].humidity += (distance / 20) - 5;
        }
        printf("Weather in city 1: %d°C, %d%% humidity\n", weather[day].temperature, weather[day].humidity);
    }

    return 0;
}