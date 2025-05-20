//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_VEHICLES 10
#define TRAFFIC_LIGHT_DURATION 5

typedef enum { RED, GREEN } LightStatus;

typedef struct {
    int id;
    LightStatus light;
    int delay;
} Vehicle;

void* simulate_vehicle(void* arg) {
    Vehicle* v = (Vehicle*)arg;

    while (1) {
        if (v->light == GREEN) {
            printf("Vehicle %d is passing through the intersection.\n", v->id);
            sleep(v->delay); // Simulate time to cross
            break; // Exit once the vehicle passes
        } else {
            printf("Vehicle %d is waiting at the red light.\n", v->id);
            sleep(1);
        }
    }
    return NULL;
}

LightStatus light = RED; // Global traffic light

void* traffic_light_controller() {
    while (1) {
        light = GREEN;
        printf("Traffic light is GREEN.\n");
        sleep(TRAFFIC_LIGHT_DURATION);
        light = RED;
        printf("Traffic light is RED.\n");
        sleep(TRAFFIC_LIGHT_DURATION);
    }
    return NULL;
}

int main() {
    pthread_t vehicles[NUM_VEHICLES];
    pthread_t light_thread;
    
    srand(time(NULL));
    pthread_create(&light_thread, NULL, traffic_light_controller, NULL);

    for (int i = 0; i < NUM_VEHICLES; i++) {
        Vehicle* v = (Vehicle*)malloc(sizeof(Vehicle));
        v->id = i + 1;
        v->light = light; // Initially set to RED

        // Random delay for each vehicle (1 to 3 seconds for crossing)
        v->delay = rand() % 3 + 1;
        
        pthread_create(&vehicles[i], NULL, simulate_vehicle, (void*)v);
    }

    // Join threads
    for (int i = 0; i < NUM_VEHICLES; i++) {
        pthread_join(vehicles[i], NULL);
    }

    pthread_cancel(light_thread);
    pthread_join(light_thread, NULL);
    return 0;
}