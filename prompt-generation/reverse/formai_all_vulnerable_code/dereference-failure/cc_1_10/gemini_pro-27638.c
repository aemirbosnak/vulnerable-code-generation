//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Data structure to represent a car
struct Car {
    int position;  // Position on the road
    int speed;     // Speed of the car
};

// Data structure to represent a road
struct Road {
    int length;  // Length of the road
    int num_cars;  // Number of cars on the road
    struct Car *cars;  // Array of cars on the road
};

// Function to initialize a road
struct Road *init_road(int length, int num_cars) {
    struct Road *road = malloc(sizeof(struct Road));
    road->length = length;
    road->num_cars = num_cars;
    road->cars = malloc(sizeof(struct Car) * num_cars);
    return road;
}

// Function to free a road
void free_road(struct Road *road) {
    free(road->cars);
    free(road);
}

// Function to update the position of a car
void update_car(struct Car *car, struct Road *road) {
    // Check if the car is at the end of the road
    if (car->position >= road->length) {
        car->position = 0;
        car->speed = rand() % 10 + 1;  // Randomize the speed of the car
    }
    // Check if the car is in front of another car
    else {
        for (int i = car->position + 1; i < road->length; i++) {
            if (road->cars[i].position == car->position + 1) {
                car->speed = road->cars[i].speed - rand() % 5;  // Slow down the car
                break;
            }
        }
    }
    // Update the position of the car
    car->position += car->speed;
}

// Function to simulate traffic flow on a road
void simulate_traffic(struct Road *road) {
    // Update the position of each car
    for (int i = 0; i < road->num_cars; i++) {
        update_car(&road->cars[i], road);
    }
    // Print the state of the road
    for (int i = 0; i < road->length; i++) {
        printf("%c", road->cars[i].position == i ? 'C' : '_');
    }
    printf("\n");
    // Recursively call the function to continue the simulation
    simulate_traffic(road);
}

int main() {
    // Initialize the road
    struct Road *road = init_road(100, 10);
    // Simulate traffic flow on the road
    simulate_traffic(road);
    // Free the road
    free_road(road);
    return 0;
}