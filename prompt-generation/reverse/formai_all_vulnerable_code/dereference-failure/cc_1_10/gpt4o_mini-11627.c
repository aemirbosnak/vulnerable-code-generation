//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_SENSORS 5
#define REPORT_INTERVAL 3

typedef struct {
    int id;
    float temperature;
} SensorData;

SensorData sensors[NUM_SENSORS];
pthread_mutex_t mutex;

void* read_temperature(void* arg) {
    int sensor_id = *((int*)arg);
    free(arg);

    while (1) {
        // Simulate reading a temperature between -10 and 35 degrees Celsius
        float random_temp = (rand() % 460) / 10.0 - 10; // -10 to 35
        pthread_mutex_lock(&mutex);
        sensors[sensor_id].temperature = random_temp;
        pthread_mutex_unlock(&mutex);

        sleep(REPORT_INTERVAL);
    }
    return NULL;
}

void print_sensor_data() {
    while (1) {
        pthread_mutex_lock(&mutex);
        printf("Current Temperature Readings:\n");
        for (int i = 0; i < NUM_SENSORS; i++) {
            printf("Sensor %d: %.1f°C\n", sensors[i].id, sensors[i].temperature);
        }
        printf("\n");
        pthread_mutex_unlock(&mutex);
        sleep(REPORT_INTERVAL);
    }
}

int main() {
    srand(time(NULL));
    pthread_t threads[NUM_SENSORS];
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NUM_SENSORS; i++) {
        sensors[i].id = i;
        int* sensor_id = malloc(sizeof(int)); // Avoids data race
        *sensor_id = i;
        pthread_create(&threads[i], NULL, read_temperature, sensor_id);
    }

    print_sensor_data();

    // Join all sensor threads (this will essentially never be reached)
    for (int i = 0; i < NUM_SENSORS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}