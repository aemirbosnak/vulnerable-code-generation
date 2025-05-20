//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Maximum number of cars on the road
#define MAX_CARS 100

// Car structure
typedef struct {
    int id;
    int speed;
    int position;
} Car;

// Road structure
typedef struct {
    int length;
    char *cars;
} Road;

// Function to initialize the road with no cars
void init_road(Road *road, int length) {
    road->length = length;
    road->cars = (char*)calloc(length, sizeof(char));
}

// Function to add a car to the road
void add_car_to_road(Road *road, Car car) {
    road->cars[car.position] = '*';
}

// Function to simulate the traffic flow
void simulate_traffic_flow(Road *road, Car *cars, int num_cars) {
    int i, j;
    int speed, position;

    while(1) {
        // Clear the road
        for(i=0; i<road->length; i++) {
            road->cars[i] = ' ';
        }

        // Move the cars
        for(i=0; i<num_cars; i++) {
            speed = cars[i].speed;
            position = cars[i].position;

            // Check if there is a car in front
            for(j=position+1; j<position+speed+1; j++) {
                if(road->cars[j] == '*') {
                    speed = j-position-1;
                    break;
                }
            }

            // Update the position of the car
            cars[i].position += speed;
            if(cars[i].position >= road->length) {
                printf("Car %d has reached the end of the road!\n", cars[i].id);
                return;
            }

            // Add the car to the road
            add_car_to_road(road, cars[i]);
        }

        // Display the road
        printf("%s\n", road->cars);
    }
}

int main() {
    int length, num_cars;
    int i;

    srand(time(NULL));

    printf("Enter the length of the road: ");
    scanf("%d", &length);

    printf("Enter the number of cars: ");
    scanf("%d", &num_cars);

    // Initialize the road
    Road road;
    init_road(&road, length);

    // Initialize the cars
    Car cars[MAX_CARS];
    for(i=0; i<num_cars; i++) {
        cars[i].id = i+1;
        cars[i].speed = rand()%5+1;
        cars[i].position = rand()%(length-10);
    }

    // Simulate traffic flow
    simulate_traffic_flow(&road, cars, num_cars);

    return 0;
}