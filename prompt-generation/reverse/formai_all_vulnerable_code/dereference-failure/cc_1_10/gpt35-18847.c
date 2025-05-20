//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 1000
#define MAX_SPEED 3
#define MAX_WAIT_TIME 5

int total_cars = 0;

// Define the structure of a car in the traffic flow simulation
typedef struct {
    int id;
    int speed;
    int time_waiting;
} Car;

void generate_car(Car *car) {
    total_cars++;
    car->id = total_cars;
    car->speed = (rand() % MAX_SPEED) + 1;
    car->time_waiting = (rand() % MAX_WAIT_TIME) + 1;
}

void print_cars(Car **cars) {
    printf("Current Traffic State:\n");
    for(int i=0; i<total_cars; i++) {
        printf("Car %d, Speed: %d, Time Waiting: %d\n", cars[i]->id, cars[i]->speed, cars[i]->time_waiting);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator with current time
    
    // Generate cars for the simulation
    Car *cars[MAX_CARS];
    for(int i=0; i<MAX_CARS; i++) {
        Car *car = (Car *) malloc(sizeof(Car));
        generate_car(car);
        cars[i] = car;
    }
    
    // Start the Traffic Flow Simulation
    int time = 0;
    int total_time_waiting = 0;
    while(1) {
        print_cars(cars);
        
        int flag = 0; // flag to check if all cars have crossed the road
        for(int i=0; i<total_cars; i++) {
            if(cars[i]->time_waiting > 0) {
                cars[i]->time_waiting--;
            } else {
                cars[i]->time_waiting = (rand() % MAX_WAIT_TIME) + 1;
                
                if(i+1 < total_cars && cars[i+1]->time_waiting > 0) {
                    // If the car in front of the current car is still waiting
                    flag = 1;
                    continue;
                }
                
                if(i+1 == total_cars) {
                    // If the current car is the last car in the array
                    flag = 1;
                    continue;
                }
                
                // Swap positions of current car and the car in front
                Car *temp = cars[i];
                cars[i] = cars[i+1];
                cars[i+1] = temp;
            }
        }
        
        if(flag == 0) {
            // All cars have crossed the road
            break;
        }
        
        total_time_waiting++;
        time++;
    }
    
    // Print the final statistics of the Traffic Flow Simulation
    printf("\n\nTraffic Simulation Results:\n");
    for(int i=0; i<total_cars; i++) {
        printf("Car %d, Total Time Waiting: %d\n", cars[i]->id, total_time_waiting);
    }
    
    // Free memory allocated for cars
    for(int i=0; i<total_cars; i++) {
        free(cars[i]);
    }
    
    return 0;
}