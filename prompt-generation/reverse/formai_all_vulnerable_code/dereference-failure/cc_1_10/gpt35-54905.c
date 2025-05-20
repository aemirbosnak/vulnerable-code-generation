//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#define MAX_CARS 50
#define MAX_SPEED 60

int n_cars = 0; // number of cars on the road
int total_cars = 0; // total number of cars that will be generated
int speed[MAX_CARS] = {0}; // speed of each car

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // mutex for accessing the shared variables
pthread_cond_t cond = PTHREAD_COND_INITIALIZER; // condition variable

void *car_thread(void *arg) {
    long id = (long) arg;
    srand(time(NULL) + id); // seed the random number generator for this car
    
    while (1) {
        pthread_mutex_lock(&mutex);
        while (n_cars >= MAX_CARS) { // wait if the road is full
            pthread_cond_wait(&cond, &mutex);
        }
        if (total_cars == 0) { // if all cars generated, exit the loop
            pthread_mutex_unlock(&mutex);
            break;
        }
        speed[id] = rand() % MAX_SPEED + 1; // generate a random speed for this car
        printf("Car %ld is entering the road with speed %d\n", id, speed[id]);
        n_cars++; // increment the number of cars on the road
        total_cars--; // decrement the total number of cars that will be generated
        pthread_mutex_unlock(&mutex);
        
        usleep(1000000 / speed[id]); // simulate the time taken to travel the road
        
        pthread_mutex_lock(&mutex);
        n_cars--; // decrement the number of cars on the road
        printf("Car %ld has left the road\n", id);
        pthread_cond_signal(&cond); // signal that the road is no longer full
        pthread_mutex_unlock(&mutex);
    }
    
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <number of cars>\n", argv[0]);
        return 1;
    }
    total_cars = atoi(argv[1]);
    if (total_cars > MAX_CARS) {
        printf("Error: Maximum number of cars allowed is %d\n", MAX_CARS);
        return 1;
    }
    
    pthread_t cars_thread[MAX_CARS];
    for (long i = 0; i < total_cars; i++) {
        pthread_create(&cars_thread[i], NULL, car_thread, (void *) i);
        usleep(500000); // add a delay between generating each car
    }
    
    for (int i = 0; i < total_cars; i++) {
        pthread_join(cars_thread[i], NULL);
    }
    
    printf("All cars have left the road.\n");
    
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    
    return 0;
}