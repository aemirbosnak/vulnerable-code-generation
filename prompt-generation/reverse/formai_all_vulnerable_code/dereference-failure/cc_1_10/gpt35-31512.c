//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_SPEED 5
#define MIN_SPEED 1

struct Car {
    int speed;
    int position;
};

int main() {
    srand(time(NULL));
    int num_cars = rand() % MAX_CARS + 1;
    struct Car* cars = malloc(num_cars * sizeof(struct Car));
    int road[MAX_CARS] = {0};

    // initialize cars and road
    for (int i = 0; i < num_cars; i++) {
        cars[i].speed = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
        cars[i].position = rand() % MAX_CARS;
        road[cars[i].position]++;
    }

    // simulate time steps
    int num_time_steps = 10;
    for (int t = 0; t < num_time_steps; t++) {
        // update positions
        for (int i = 0; i < num_cars; i++) {
            int old_pos = cars[i].position;
            int new_pos = (old_pos + cars[i].speed) % MAX_CARS;

            // check for collision
            if (road[new_pos] > 0) {
                cars[i].speed = 0;
            } else {
                road[old_pos]--;
                cars[i].position = new_pos;
                road[new_pos]++;
            }
        }

        // print road
        for (int i = 0; i < MAX_CARS; i++) {
            if (road[i] > 0) {
                printf("x");
            } else {
                printf("-");
            }
        }
        printf("\n");

        // update speeds
        for (int i = 0; i < num_cars; i++) {
            int front_pos = (cars[i].position + 1) % MAX_CARS;
            int gap_size = 1;
            while (road[front_pos] == 0) {
                gap_size++;
                front_pos = (front_pos + 1) % MAX_CARS;
            }
            int desired_speed = gap_size - 1;
            cars[i].speed = (desired_speed < cars[i].speed) ? (desired_speed) : (cars[i].speed + 1);
        }
    }

    free(cars);
    return 0;
}