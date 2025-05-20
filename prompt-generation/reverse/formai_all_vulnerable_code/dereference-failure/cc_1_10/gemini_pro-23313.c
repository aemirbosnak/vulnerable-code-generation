//GEMINI-pro DATASET v1.0 Category: Weather simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LOCATIONS 10

typedef enum {
    SUNNY,
    CLOUDY,
    RAINING,
    SNOWING
} WeatherCondition;

typedef struct {
    WeatherCondition *weather;
    size_t num_weather_conditions;
} Location;

void print_weather(WeatherCondition weather) {
    switch (weather) {
        case SUNNY:
            printf("Sunny");
            break;
        case CLOUDY:
            printf("Cloudy");
            break;
        case RAINING:
            printf("Raining");
            break;
        case SNOWING:
            printf("Snowing");
            break;
    }
}

int random_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

WeatherCondition *generate_weather_conditions(size_t num_conditions) {
    WeatherCondition *weather = malloc(sizeof(WeatherCondition) * num_conditions);
    for (size_t i = 0; i < num_conditions; i++) {
        weather[i] = random_int(SUNNY, SNOWING);
    }
    return weather;
}

Location *generate_locations(size_t num_locations) {
    Location *locations = malloc(sizeof(Location) * num_locations);
    for (size_t i = 0; i < num_locations; i++) {
        locations[i].num_weather_conditions = random_int(1, 10);
        locations[i].weather = generate_weather_conditions(locations[i].num_weather_conditions);
    }
    return locations;
}

void print_locations(Location *locations, size_t num_locations) {
    for (size_t i = 0; i < num_locations; i++) {
        printf("Location %zu: ", i + 1);
        for (size_t j = 0; j < locations[i].num_weather_conditions; j++) {
            print_weather(locations[i].weather[j]);
            if (j != locations[i].num_weather_conditions - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    Location *locations = generate_locations(NUM_LOCATIONS);
    print_locations(locations, NUM_LOCATIONS);
    free(locations);
    return 0;
}