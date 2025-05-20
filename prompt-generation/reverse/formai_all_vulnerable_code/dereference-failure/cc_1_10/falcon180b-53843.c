//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 4

struct thread_data {
    int thread_id;
    int *weather_data;
};

void *update_weather(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    int thread_id = data->thread_id;
    int *weather_data = data->weather_data;

    while (1) {
        int temperature = rand() % 101;
        int humidity = rand() % 101;
        int wind_speed = rand() % 101;

        printf("Thread %d: Current weather - Temperature: %d°C, Humidity: %d%, Wind Speed: %d km/h\n", thread_id, temperature, humidity, wind_speed);

        weather_data[thread_id] = temperature + humidity + wind_speed;

        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS] = {1, 2, 3, 4};
    int weather_data[NUM_THREADS] = {0};

    srand(time(NULL));

    for (int i = 0; i < NUM_THREADS; i++) {
        struct thread_data *data = malloc(sizeof(struct thread_data));
        data->thread_id = thread_ids[i];
        data->weather_data = &weather_data[i];

        pthread_create(&threads[i], NULL, update_weather, data);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}