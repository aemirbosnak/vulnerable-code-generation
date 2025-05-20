//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_INTERSECTIONS 4  // Number of intersections
#define NUM_ROADS (NUM_INTERSECTIONS - 1)  // Number of roads
#define NUM_VEHICLES 50  // Number of vehicles

typedef struct {
    int id;
    int position;
    int speed;
} Vehicle;

typedef struct {
    int id;
    int length;  // Length of the road (in number of cells)
    int num_vehicles;  // Number of vehicles on the road
    Vehicle* vehicles;  // Array of vehicles on the road
} Road;

typedef struct {
    int id;
    Road* roads[NUM_ROADS];  // Array of roads connected to the intersection
} Intersection;

Intersection* intersections[NUM_INTERSECTIONS];  // Array of intersections
Road* roads[NUM_ROADS];  // Array of roads

// Initialize the traffic flow simulation
void init() {
    // Create intersections
    for (int i = 0; i < NUM_INTERSECTIONS; i++) {
         intersections[i] = (Intersection*)malloc(sizeof(Intersection));
         intersections[i]->id = i;
         for (int j = 0; j < NUM_ROADS; j++) {
             intersections[i]->roads[j] = NULL;
             }
    }

    // Create roads
    for (int i = 0; i < NUM_ROADS; i++) {
        roads[i] = (Road*)malloc(sizeof(Road));
        roads[i]->id = i;
        roads[i]->length = rand() % 10 + 1;  // Random length between 1 and 10
        roads[i]->num_vehicles = 0;
        roads[i]->vehicles = (Vehicle*)malloc(sizeof(Vehicle) * roads[i]->length);
        for (int j = 0; j < roads[i]->length; j++) {
            roads[i]->vehicles[j].id = j;
            roads[i]->vehicles[j].position = 0;
            roads[i]->vehicles[j].speed = rand() % 5 + 1;  // Random speed between 1 and 5
        }
    }

    // Connect intersections to roads
    int road_index = 0;
    for (int i = 0; i < NUM_INTERSECTIONS; i++) {
        for (int j = i + 1; j < NUM_INTERSECTIONS; j++) {
            intersections[i]->roads[road_index] = roads[road_index];
            intersections[j]->roads[road_index] = roads[road_index];
            road_index++;
        }
    }
}

// Update the traffic flow simulation
void update() {
    // Move vehicles on roads
    for (int i = 0; i < NUM_ROADS; i++) {
        for (int j = 0; j < roads[i]->num_vehicles; j++) {
            roads[i]->vehicles[j].position += roads[i]->vehicles[j].speed;
            if (roads[i]->vehicles[j].position >= roads[i]->length) {
                roads[i]->vehicles[j].position -= roads[i]->length;
            }
        }
    }

    // Check for collisions at intersections
    for (int i = 0; i < NUM_INTERSECTIONS; i++) {
        for (int j = 0; j < NUM_ROADS; j++) {
            for (int k = j + 1; k < NUM_ROADS; k++) {
                for (int l = 0; l < roads[j]->num_vehicles; l++) {
                    for (int m = 0; m < roads[k]->num_vehicles; m++) {
                        if (roads[j]->vehicles[l].position == roads[k]->vehicles[m].position) {
                            printf("Collision at intersection %d between vehicles %d and %d\n", intersections[i]->id, roads[j]->vehicles[l].id, roads[k]->vehicles[m].id);
                        }
                    }
                }
            }
        }
    }
}

// Print the traffic flow simulation
void print() {
    // Print intersections
    for (int i = 0; i < NUM_INTERSECTIONS; i++) {
        printf("Intersection %d:\n", intersections[i]->id);
        for (int j = 0; j < NUM_ROADS; j++) {
            printf("  Road %d:\n", intersections[i]->roads[j]->id);
            for (int k = 0; k < intersections[i]->roads[j]->num_vehicles; k++) {
                printf("    Vehicle %d: position %d, speed %d\n", intersections[i]->roads[j]->vehicles[k].id, intersections[i]->roads[j]->vehicles[k].position, intersections[i]->roads[j]->vehicles[k].speed);
            }
        }
    }
}

// Main function
int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Initialize the traffic flow simulation
    init();

    // Update the traffic flow simulation
    for (int i = 0; i < 100; i++) {
        update();
    }

    // Print the traffic flow simulation
    print();

    return 0;
}