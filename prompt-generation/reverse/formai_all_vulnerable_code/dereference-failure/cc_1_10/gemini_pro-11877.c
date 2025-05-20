//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Define the road dimensions
#define ROAD_WIDTH 10
#define ROAD_LENGTH 100

// Define the car parameters
#define CAR_LENGTH 5
#define CAR_WIDTH 2
#define CAR_SPEED_MIN 1
#define CAR_SPEED_MAX 5

// Define the traffic light parameters
#define TRAFFIC_LIGHT_GREEN_TIME 10
#define TRAFFIC_LIGHT_YELLOW_TIME 5
#define TRAFFIC_LIGHT_RED_TIME 10

// Define the car struct
typedef struct car {
    int x; // The x-coordinate of the car
    int y; // The y-coordinate of the car
    int speed; // The speed of the car
    int direction; // The direction of the car (0 = left, 1 = right)
} car;

// Define the road struct
typedef struct road {
    car **cars; // The array of cars on the road
    int num_cars; // The number of cars on the road
    int traffic_light; // The state of the traffic light (0 = red, 1 = yellow, 2 = green)
} road;

// Initialize the road
void init_road(road *r) {
    r->cars = (car **) malloc(sizeof(car *) * ROAD_LENGTH);
    r->num_cars = 0;
    r->traffic_light = 0;
}

// Add a car to the road
void add_car(road *r, int x, int y, int speed, int direction) {
    car *c = (car *) malloc(sizeof(car));
    c->x = x;
    c->y = y;
    c->speed = speed;
    c->direction = direction;
    r->cars[r->num_cars++] = c;
}

// Update the traffic light
void update_traffic_light(road *r) {
    switch (r->traffic_light) {
        case 0: // Red
            if (rand() % 100 < 50) {
                r->traffic_light = 1; // Yellow
            }
            break;
        case 1: // Yellow
            r->traffic_light = 2; // Green
            break;
        case 2: // Green
            if (rand() % 100 < 50) {
                r->traffic_light = 0; // Red
            }
            break;
    }
}

// Update the cars
void update_cars(road *r) {
    for (int i = 0; i < r->num_cars; i++) {
        car *c = r->cars[i];
        
        // Check if the car is at the end of the road
        if (c->x + CAR_LENGTH >= ROAD_LENGTH || c->x <= 0) {
            // Remove the car from the road
            free(c);
            r->cars[i] = r->cars[r->num_cars - 1];
            r->num_cars--;
            i--;
            continue;
        }
        
        // Check if the car is stopped by the traffic light
        if (c->x + CAR_LENGTH >= ROAD_LENGTH / 2 && r->traffic_light == 0) {
            c->speed = 0;
        } else {
            // Update the car's speed
            c->speed = CAR_SPEED_MIN + rand() % (CAR_SPEED_MAX - CAR_SPEED_MIN + 1);
        }
        
        // Update the car's position
        if (c->direction == 0) {
            c->x -= c->speed;
        } else {
            c->x += c->speed;
        }
    }
}

// Draw the road
void draw_road(road *r) {
    for (int i = 0; i < ROAD_LENGTH; i++) {
        for (int j = 0; j < ROAD_WIDTH; j++) {
            // Draw the road
            printf("#");
        }
        printf("\n");
    }
    
    // Draw the cars
    for (int i = 0; i < r->num_cars; i++) {
        car *c = r->cars[i];
        for (int j = 0; j < CAR_LENGTH; j++) {
            // Draw the car
            printf("=");
        }
        printf("\n");
    }
    
    // Draw the traffic light
    switch (r->traffic_light) {
        case 0: // Red
            printf("RED");
            break;
        case 1: // Yellow
            printf("YELLOW");
            break;
        case 2: // Green
            printf("GREEN");
            break;
    }
    printf("\n");
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));
    
    // Initialize the road
    road r;
    init_road(&r);
    
    // Add some cars to the road
    for (int i = 0; i < 10; i++) {
        add_car(&r, rand() % ROAD_LENGTH, rand() % ROAD_WIDTH, CAR_SPEED_MIN + rand() % (CAR_SPEED_MAX - CAR_SPEED_MIN + 1), rand() % 2);
    }
    
    while (1) {
        // Update the traffic light
        update_traffic_light(&r);
        
        // Update the cars
        update_cars(&r);
        
        // Draw the road
        draw_road(&r);
        
        // Sleep for a bit
        usleep(100000);
    }
    
    return 0;
}