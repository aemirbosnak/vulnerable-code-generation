//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define MAX_CARS 20
#define ROAD_LENGTH 50
#define NUM_LANES 2
#define CAR_LENGTH 5
#define SIMULATION_TIME 60

typedef struct {
    int id;
    int position;
    int lane;
} Car;

Car *cars[MAX_CARS];  // Array of cars
pthread_mutex_t road_mutex; // Mutex for protecting road access

void* car_move(void* car_ptr) {
    Car *car = (Car *)car_ptr;
    while (car->position < ROAD_LENGTH) {
        // Simulating car movement
        sleep(rand() % 3 + 1); // Random delay (1 to 3 seconds)

        // Attempt to move forward
        pthread_mutex_lock(&road_mutex);
        if (car->position < ROAD_LENGTH - CAR_LENGTH) {
            car->position += 1;

            // Show car movement
            printf("Car %d moved to position %d in lane %d\n", car->id, car->position, car->lane);
        } else {
            printf("Car %d cannot move. Reached the end of the road.\n", car->id);
        }
        pthread_mutex_unlock(&road_mutex);
    }
    return NULL;
}

void print_road() {
    // Clear console
    printf("\033[H\033[J");
    printf("Traffic Flow Simulation\n");
    for (int i = 0; i < ROAD_LENGTH; i++) {
        int printed = 0;
        for (int j = 0; j < MAX_CARS; j++) {
            if (cars[j] != NULL && cars[j]->position == i) {
                printf("C%d", cars[j]->id);
                printed = 1;
            }
        }
        if (!printed) {
            printf("--");
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    pthread_t car_threads[MAX_CARS];

    // Initialize mutex
    pthread_mutex_init(&road_mutex, NULL);

    // Create cars
    for (int i = 0; i < MAX_CARS; i++) {
        cars[i] = (Car *)malloc(sizeof(Car));
        cars[i]->id = i;
        cars[i]->position = 0;
        cars[i]->lane = i % NUM_LANES;
        pthread_create(&car_threads[i], NULL, car_move, (void *)cars[i]);
    }

    // Simulate for a given time
    for (int time = 0; time < SIMULATION_TIME; time++) {
        print_road();
        sleep(1); // Refresh the display every second
    }

    // Clean up
    for (int i = 0; i < MAX_CARS; i++) {
        pthread_join(car_threads[i], NULL);
        free(cars[i]);
    }
    pthread_mutex_destroy(&road_mutex);
    
    printf("Simulation finished.\n");
    return 0;
}