//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365

struct city {
    char name[20];
    int x;
    int y;
    int temp;
    int humidity;
    int pressure;
};

void generate_cities(struct city cities[], int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        sprintf(cities[i].name, "City %d", i + 1);
        cities[i].x = rand() % 100;
        cities[i].y = rand() % 100;
        cities[i].temp = rand() % 50 + 1;
        cities[i].humidity = rand() % 101;
        cities[i].pressure = rand() % 101;
    }
}

void print_city(struct city city) {
    printf("Name: %s\n", city.name);
    printf("Coordinates: (%d, %d)\n", city.x, city.y);
    printf("Temperature: %d\n", city.temp);
    printf("Humidity: %d\n", city.humidity);
    printf("Pressure: %d\n", city.pressure);
}

void simulate_day(struct city cities[], int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        cities[i].temp = (cities[i].temp + rand() % 10 - 5) % 50 + 1;
        cities[i].humidity = (cities[i].humidity + rand() % 10 - 5) % 101;
        cities[i].pressure = (cities[i].pressure + rand() % 10 - 5) % 101;
    }
}

int main() {
    srand(time(NULL));

    int num_cities;
    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);

    struct city cities[num_cities];
    generate_cities(cities, num_cities);

    int num_days;
    printf("Enter the number of days to simulate: ");
    scanf("%d", &num_days);

    for (int day = 1; day <= num_days; day++) {
        printf("Day %d:\n", day);
        for (int i = 0; i < num_cities; i++) {
            print_city(cities[i]);
        }
        simulate_day(cities, num_cities);
    }

    return 0;
}