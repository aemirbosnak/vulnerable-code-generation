//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Car struct to hold individual car information
typedef struct Car {
    int id; // unique ID for each car
    int speed; // speed of the car in mph
    int position; // current position of the car along the road
    struct Car* next; // pointer to the next car in line
} Car;

// Road struct to hold information about the road
typedef struct Road {
    int length; // length of the road in miles
    int max_speed; // maximum speed limit of the road
    Car* first_car; // pointer to first car in line on the road
} Road;

/**
 * Helper function to generate a random speed between min and max
 * @param min the minimum speed
 * @param max the maximum speed
 * @return a random speed between min and max
 */
int generate_speed(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

/**
 * Helper function to create a new car with a unique ID and random speed
 * @param id the ID for the new car
 * @param max_speed the maximum speed limit of the road
 * @param position the starting position of the new car
 * @return a pointer to the new car
 */
Car* create_car(int id, int max_speed, int position) {
    Car* new_car = (Car*) malloc(sizeof(Car));
    new_car->id = id;
    new_car->speed = generate_speed(1, max_speed);
    new_car->position = position;
    new_car->next = NULL;
    return new_car;
}

/**
 * Helper function to add a car to the end of the line of cars on the road
 * @param road the road to add the car to
 * @param new_car the new car to add to the road
 */
void add_car_to_road(Road* road, Car* new_car) {
    if (road->first_car == NULL) {
        road->first_car = new_car;
    } else {
        Car* current_car = road->first_car;
        while (current_car->next != NULL) {
            current_car = current_car->next;
        }
        current_car->next = new_car;
    }
}

/**
 * Function to simulate the flow of cars on the road
 * @param road the road to simulate
 * @param time the amount of time to simulate in seconds
 */
void simulate_traffic_flow(Road* road, int time) {
    int count = 0;
    while (count < time) {
        printf("\nTime: %d seconds\n", count);
        Car* current_car = road->first_car;
        while (current_car != NULL) {
            printf("Car %d currently at position %d going %d mph\n", current_car->id, current_car->position, current_car->speed);
            current_car->position += current_car->speed;
            if (current_car->position > road->length) {
                printf("Car %d has left the road\n", current_car->id);
                if (current_car == road->first_car) {
                    road->first_car = current_car->next;
                } else {
                    Car* previous_car = road->first_car;
                    while (previous_car->next != current_car) {
                        previous_car = previous_car->next;
                    }
                    previous_car->next = current_car->next;
                }
                free(current_car);
            }
            current_car = current_car->next;
        }
        // Add a new car to the road every 10 seconds
        if (count % 10 == 0) {
            Car* new_car = create_car(count/10 + 1, road->max_speed, 0);
            add_car_to_road(road, new_car);
            printf("Added new car with ID %d going %d mph\n", new_car->id, new_car->speed);
        }
        count++;
    }
}

int main() {
    srand(time(NULL)); // seed the random number generator with the current time
    Road road;
    road.length = 10;
    road.max_speed = 70;
    road.first_car = NULL;
    simulate_traffic_flow(&road, 60);
    return 0;
}