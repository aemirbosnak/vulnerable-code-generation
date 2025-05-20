//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// Car struct
typedef struct car {
    int id;
    int speed;
    int position;
    struct car *next;
} car;

// Road struct
typedef struct road {
    car *head;
    car *tail;
} road;

// Create a new car
car *create_car(int id, int speed, int position) {
    car *new_car = malloc(sizeof(car));
    new_car->id = id;
    new_car->speed = speed;
    new_car->position = position;
    new_car->next = NULL;
    return new_car;
}

// Create a new road
road *create_road() {
    road *new_road = malloc(sizeof(road));
    new_road->head = NULL;
    new_road->tail = NULL;
    return new_road;
}

// Add a car to the road
void add_car(road *road, car *new_car) {
    if (road->head == NULL) {
        road->head = new_car;
        road->tail = new_car;
    } else {
        road->tail->next = new_car;
        road->tail = new_car;
    }
}

// Move all cars on the road
void move_cars(road *road) {
    car *current_car = road->head;
    while (current_car != NULL) {
        current_car->position += current_car->speed;
        current_car = current_car->next;
    }
}

// Print the state of the road
void print_road(road *road) {
    car *current_car = road->head;
    while (current_car != NULL) {
        printf("Car %d: position %d\n", current_car->id, current_car->position);
        current_car = current_car->next;
    }
}

// Main function
int main() {
    // Create a new road
    road *road = create_road();

    // Create some cars
    car *car1 = create_car(1, 10, 0);
    car *car2 = create_car(2, 15, 50);
    car *car3 = create_car(3, 20, 100);

    // Add the cars to the road
    add_car(road, car1);
    add_car(road, car2);
    add_car(road, car3);

    // Move the cars for 10 time units
    for (int i = 0; i < 10; i++) {
        move_cars(road);
    }

    // Print the state of the road
    print_road(road);

    return 0;
}