//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_ROADS 4
#define MAX_SPEED 50
#define MIN_SPEED 10
#define MAX_CARS 30

typedef struct {
    int id;
    int speed;
} Car;

typedef struct {
    int road_id;
    Car** cars;
    int num_of_cars;
} Road;

Road* roads[NUM_OF_ROADS];
int time_elapsed = 0;

void initialize_roads() {
    for(int i=0; i<NUM_OF_ROADS; i++) {
        roads[i] = (Road*)malloc(sizeof(Road));
        roads[i]->road_id = i;
        roads[i]->num_of_cars = rand()%(MAX_CARS-10) + 10;
        roads[i]->cars = (Car**)malloc(sizeof(Car*)*roads[i]->num_of_cars);
        for(int j=0; j<roads[i]->num_of_cars; j++) {
            roads[i]->cars[j] = (Car*)malloc(sizeof(Car));
            roads[i]->cars[j]->id = j+1;
            roads[i]->cars[j]->speed = rand()%(MAX_SPEED-MIN_SPEED) + MIN_SPEED;
        }
    }
}

void display_roads() {
    printf("\nTime elapsed: %d sec\n\n", time_elapsed);
    for(int i=0; i<NUM_OF_ROADS; i++) {
        printf("Road %d:\n", i+1);
        for(int j=0; j<roads[i]->num_of_cars; j++) {
            printf("Car %d (Speed: %d)\n", roads[i]->cars[j]->id, roads[i]->cars[j]->speed);
        }
        printf("\n");
    }
}

void simulate_traffic() {
    while(1) {
        display_roads();
        time_elapsed++;
        if(time_elapsed == 10) {
            break;
        }
        // update car positions and check collisions
        for(int i=0; i<NUM_OF_ROADS; i++) {
            int prev_pos = -1;
            for(int j=0; j<roads[i]->num_of_cars; j++) {
                int new_pos = prev_pos + roads[i]->cars[j]->speed;
                if(new_pos >= 100) {
                    new_pos = -1;
                }
                if(new_pos != -1) {
                    prev_pos = new_pos;
                } else {
                    prev_pos = prev_pos + 10;
                }
                roads[i]->cars[j]->speed = rand()%(MAX_SPEED-MIN_SPEED) + MIN_SPEED;
            }
        }
        // add new car to random road
        if(rand()%2 == 0) {
            int road_index = rand()%NUM_OF_ROADS;
            if(roads[road_index]->num_of_cars < MAX_CARS) {
                roads[road_index]->num_of_cars++;
                roads[road_index]->cars = (Car**)realloc(roads[road_index]->cars, sizeof(Car*)*roads[road_index]->num_of_cars);
                roads[road_index]->cars[roads[road_index]->num_of_cars-1] = (Car*)malloc(sizeof(Car));
                roads[road_index]->cars[roads[road_index]->num_of_cars-1]->id = roads[road_index]->num_of_cars;
                roads[road_index]->cars[roads[road_index]->num_of_cars-1]->speed = rand()%(MAX_SPEED-MIN_SPEED) + MIN_SPEED;
            }
        }
        // wait for 1 sec
        sleep(1);
        system("clear");
    }
}

int main() {
    srand(time(NULL));
    initialize_roads();
    simulate_traffic();
    return 0;
}