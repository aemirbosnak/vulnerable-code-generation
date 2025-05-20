//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_CITIES 5
#define WEATHER_TYPES 3

struct city {
    int id;
    int temperature;
    int humidity;
};

struct weather_data {
    int temperature;
    int humidity;
};

void *update_weather(void *arg) {
    struct city *city = (struct city *) arg;
    struct weather_data *weather_data = (struct weather_data *) malloc(sizeof(struct weather_data));

    weather_data->temperature = rand() % 101;
    weather_data->humidity = rand() % 101;

    printf("Weather update for city %d: Temperature = %d, Humidity = %d\n", city->id, weather_data->temperature, weather_data->humidity);

    free(weather_data);
    return NULL;
}

int main() {
    pthread_t threads[NUM_CITIES];
    struct city cities[NUM_CITIES] = {{1, 0, 0}, {2, 0, 0}, {3, 0, 0}, {4, 0, 0}, {5, 0, 0}};

    srand(time(NULL));

    int i;
    for (i = 0; i < NUM_CITIES; i++) {
        pthread_create(&threads[i], NULL, update_weather, &cities[i]);
        sleep(1);
    }

    for (i = 0; i < NUM_CITIES; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}