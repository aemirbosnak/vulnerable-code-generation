//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_VEHICLES 5
#define ROAD_CAPACITY 3
#define INTERSECTION_TIME 2

typedef enum { ELF, DRAGON, UNICORN, TROLL } VehicleType;

typedef struct {
    VehicleType type;
    int id;
} Vehicle;

pthread_mutex_t intersection_lock;
int current_count = 0;

const char *vehicle_names[] = { "Elf", "Dragon", "Unicorn", "Troll" };

void *cross_intersection(void *arg) {
    Vehicle *vehicle = (Vehicle *)arg;

    printf("%s %d is approaching the intersection...\n", vehicle_names[vehicle->type], vehicle->id);

    pthread_mutex_lock(&intersection_lock);
    if (current_count < ROAD_CAPACITY) {
        current_count++;
        printf("%s %d is crossing the intersection. Current count: %d\n", vehicle_names[vehicle->type], vehicle->id, current_count);
        
        sleep(INTERSECTION_TIME); // Simulates the time taken to cross
        current_count--;
        printf("%s %d has crossed the intersection. Current count: %d\n", vehicle_names[vehicle->type], vehicle->id, current_count);
    } else {
        printf("%s %d was waiting to cross the intersection, but it's too busy!\n", vehicle_names[vehicle->type], vehicle->id);
    }
    pthread_mutex_unlock(&intersection_lock);

    free(vehicle);
    return NULL;
}

int main() {
    pthread_t threads[NUM_VEHICLES];
    srand(time(NULL));
    
    pthread_mutex_init(&intersection_lock, NULL);

    for (int i = 0; i < NUM_VEHICLES; i++) {
        Vehicle *vehicle = (Vehicle *)malloc(sizeof(Vehicle));
        vehicle->id = i + 1;
        vehicle->type = rand() % 4; // randomly assign a vehicle type

        pthread_create(&threads[i], NULL, cross_intersection, (void *)vehicle);
        
        sleep(rand() % 3); // staggering the arrival of vehicles
    }

    for (int i = 0; i < NUM_VEHICLES; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&intersection_lock);
    
    printf("All vehicles have crossed the magical intersection!\n");
    return 0;
}