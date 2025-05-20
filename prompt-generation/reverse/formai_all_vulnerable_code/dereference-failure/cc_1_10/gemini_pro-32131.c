//GEMINI-pro DATASET v1.0 Category: Weather simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Weather {
    float temperature;
    float humidity;
    float wind_speed;
    float precipitation;
} Weather;

typedef struct City {
    char* name;
    Weather weather;
} City;

typedef struct World {
    int num_cities;
    City* cities;
} World;

World* create_world(int num_cities) {
    World* world = malloc(sizeof(World));
    world->num_cities = num_cities;
    world->cities = malloc(sizeof(City) * num_cities);
    for (int i = 0; i < num_cities; i++) {
        world->cities[i].name = malloc(sizeof(char) * 10);
        sprintf(world->cities[i].name, "City %d", i);
        world->cities[i].weather.temperature = (float)(rand() % 50);
        world->cities[i].weather.humidity = (float)(rand() % 100);
        world->cities[i].weather.wind_speed = (float)(rand() % 10);
        world->cities[i].weather.precipitation = (float)(rand() % 100);
    }
    return world;
}

void print_world(World* world) {
    for (int i = 0; i < world->num_cities; i++) {
        printf("City: %s\n", world->cities[i].name);
        printf("Temperature: %.2f\n", world->cities[i].weather.temperature);
        printf("Humidity: %.2f\n", world->cities[i].weather.humidity);
        printf("Wind speed: %.2f\n", world->cities[i].weather.wind_speed);
        printf("Precipitation: %.2f\n", world->cities[i].weather.precipitation);
        printf("\n");
    }
}

void update_world(World* world) {
    for (int i = 0; i < world->num_cities; i++) {
        world->cities[i].weather.temperature += (float)(rand() % 10 - 5);
        world->cities[i].weather.humidity += (float)(rand() % 10 - 5);
        world->cities[i].weather.wind_speed += (float)(rand() % 10 - 5);
        world->cities[i].weather.precipitation += (float)(rand() % 10 - 5);
    }
}

int main() {
    srand(time(NULL));
    World* world = create_world(10);
    print_world(world);
    update_world(world);
    print_world(world);
    return 0;
}