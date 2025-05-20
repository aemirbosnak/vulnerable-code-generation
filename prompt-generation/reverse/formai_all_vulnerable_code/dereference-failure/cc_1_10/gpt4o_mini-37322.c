//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_VEHICLES 10
#define GREEN_LIGHT_DURATION 5
#define RED_LIGHT_DURATION 2

typedef struct {
    int id;
    int waiting_time;
} Vehicle;

pthread_mutex_t lock;
int green_light = 1;

void* vehicle_action(void* arg) {
    Vehicle* vehicle = (Vehicle*)arg;
    
    printf("Vehicle %d: Waiting to cross.\n", vehicle->id);
    
    while (1) {
        pthread_mutex_lock(&lock);
        
        if (green_light) {
            printf("Vehicle %d: Crossing the intersection.\n", vehicle->id);
            sleep(GREEN_LIGHT_DURATION);  // Cross the intersection
            printf("Vehicle %d: Finished crossing.\n", vehicle->id);
            pthread_mutex_unlock(&lock);
            break;  // Vehicle has crossed and can terminate
        }
        
        pthread_mutex_unlock(&lock);
        vehicle->waiting_time++;
        printf("Vehicle %d: Waiting for green light. Time waited: %d seconds.\n", vehicle->id, vehicle->waiting_time);
        sleep(1);  // Wait before checking the light again
    }
    
    free(vehicle);  // Free allocated memory
    return NULL;
}

void* traffic_light() {
    while (1) {
        sleep(GREEN_LIGHT_DURATION);
        pthread_mutex_lock(&lock);
        green_light = 0;  // Change to red light
        printf("Traffic light: Turning RED.\n");
        pthread_mutex_unlock(&lock);
        
        sleep(RED_LIGHT_DURATION);
        pthread_mutex_lock(&lock);
        green_light = 1;  // Change to green light
        printf("Traffic light: Turning GREEN.\n");
        pthread_mutex_unlock(&lock);
    }
}

int main() {
    pthread_t vehicles[NUM_VEHICLES];
    pthread_t light_thread;

    srand(time(0));
    pthread_mutex_init(&lock, NULL);

    // Start the traffic light thread
    pthread_create(&light_thread, NULL, traffic_light, NULL);

    // Start vehicle threads
    for (int i = 0; i < NUM_VEHICLES; i++) {
        Vehicle* vehicle = (Vehicle*)malloc(sizeof(Vehicle));
        vehicle->id = i + 1;
        vehicle->waiting_time = 0;
        pthread_create(&vehicles[i], NULL, vehicle_action, vehicle);
        sleep(rand() % 3);  // Randomly stagger vehicle arrivals
    }

    // Wait for vehicle threads to finish
    for (int i = 0; i < NUM_VEHICLES; i++) {
        pthread_join(vehicles[i], NULL);
    }
    
    pthread_cancel(light_thread);  // Stop the traffic light thread
    pthread_mutex_destroy(&lock);
    printf("All vehicles have crossed the intersection.\n");
    
    return 0;
}