//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <time.h>

#define NUM_CARS 10
#define TRAFFIC_LIGHT_GREEN 1
#define TRAFFIC_LIGHT_RED 0

typedef struct {
    int traffic_light;
    int cars_waiting;
} TrafficIntersection;

void light_cycle(TrafficIntersection *intersection) {
    while (1) {
        // Green light
        intersection->traffic_light = TRAFFIC_LIGHT_GREEN;
        printf("Traffic light is GREEN. Cars can go!\n");
        sleep(10);  // Duration of the green light

        // Switch to red light
        intersection->traffic_light = TRAFFIC_LIGHT_RED;
        printf("Traffic light is RED. Cars must stop.\n");
        sleep(5);  // Duration of the red light
    }
}

void car_process(int car_id, TrafficIntersection *intersection) {
    while (1) {
        if (intersection->traffic_light == TRAFFIC_LIGHT_GREEN) {
            printf("Car %d is crossing the intersection.\n", car_id);
            sleep(rand() % 3 + 1);  // Simulate time taken to cross
            printf("Car %d has crossed the intersection.\n", car_id);
        } else {
            intersection->cars_waiting++;
            printf("Car %d is waiting at the red light.\n", car_id);
            sleep(1);  // Wait before trying again
            intersection->cars_waiting--;
        }
        sleep(1);  // Delay before the next attempt
    }
}

int main() {
    srand(time(NULL));
    int shmid;
  
    // Create shared memory for TrafficIntersection
    shmid = shmget(IPC_PRIVATE, sizeof(TrafficIntersection), IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget failed");
        exit(1);
    }

    TrafficIntersection *intersection = (TrafficIntersection *)shmat(shmid, NULL, 0);
    if (intersection == (TrafficIntersection *) -1) {
        perror("shmat failed");
        exit(1);
    }

    intersection->traffic_light = TRAFFIC_LIGHT_RED;
    intersection->cars_waiting = 0;

    // Fork to create the traffic light control process
    if (fork() == 0) {
        light_cycle(intersection);
        exit(0);
    }

    // Create car processes
    for (int i = 0; i < NUM_CARS; i++) {
        if (fork() == 0) {
            car_process(i + 1, intersection);
            exit(0);
        }
    }

    // Wait for all child processes to finish
    for (int i = 0; i < NUM_CARS + 1; i++) {
        wait(NULL);
    }

    // Detach and remove shared memory
    shmdt(intersection);
    shmctl(shmid, IPC_RMID, NULL);
    
    return 0;
}