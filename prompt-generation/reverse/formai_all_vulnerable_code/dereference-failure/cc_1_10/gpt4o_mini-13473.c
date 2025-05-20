//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_THREADS 5
#define MAX_TEMPERATURE 40
#define MIN_TEMPERATURE -10

typedef struct {
    int city_id;
    int temperature;
} CityWeather;

CityWeather cityWeather[NUM_THREADS];

void* simulate_weather(void* arg) {
    int city_id = *((int*)arg);
    free(arg);
    
    while (1) {
        // Randomly generate temperature between MIN_TEMPERATURE and MAX_TEMPERATURE
        cityWeather[city_id].temperature = (rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1)) + MIN_TEMPERATURE;
        printf("City %d: Current Temperature: %d°C\n", cityWeather[city_id].city_id, cityWeather[city_id].temperature);
        
        // Simulate time passage
        sleep(2); // Adjust this value for simulation speed
    }
    
    return NULL;
}

void* alert_weather(void* arg) {
    int city_id = *((int*)arg);
    free(arg);
    
    while (1) {
        if (cityWeather[city_id].temperature > 30) {
            printf("Alert! City %d: High Temperature: %d°C\n", cityWeather[city_id].city_id, cityWeather[city_id].temperature);
        } else if (cityWeather[city_id].temperature < 0) {
            printf("Alert! City %d: Low Temperature: %d°C\n", cityWeather[city_id].city_id, cityWeather[city_id].temperature);
        }
        
        // Check the weather every 3 seconds
        sleep(3);
    }
    
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    srand(time(NULL));
    
    for (int i = 0; i < NUM_THREADS; i++) {
        cityWeather[i].city_id = i;
        int* city_id = malloc(sizeof(int)); // Allocate memory for thread arguments
        *city_id = i;
        
        // Create weather simulation thread
        pthread_create(&threads[i], NULL, simulate_weather, city_id);
        
        // Create weather alert thread
        city_id = malloc(sizeof(int)); // Allocate new memory for alert thread
        *city_id = i;
        pthread_create(&threads[i + NUM_THREADS], NULL, alert_weather, city_id);
    }
    
    // Monitor threads (in this case, we just let them run indefinitely)
    for (int i = 0; i < NUM_THREADS * 2; i++) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}