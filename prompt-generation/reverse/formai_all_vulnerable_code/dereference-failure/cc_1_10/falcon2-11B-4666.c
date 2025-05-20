//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    int start_pos;
    int end_pos;
    int speed;
} car;

int main() {
    srand(time(NULL));

    int num_cars = 100;
    int num_lanes = 10;
    int num_steps = 1000000;

    car* cars = (car*)malloc(num_cars * sizeof(car));
    int* lanes = (int*)malloc(num_lanes * sizeof(int));

    for (int i = 0; i < num_cars; i++) {
        cars[i].id = i;
        cars[i].start_pos = rand() % num_lanes;
        cars[i].end_pos = cars[i].start_pos + rand() % (num_lanes - cars[i].start_pos);
        cars[i].speed = rand() % 10;
    }

    for (int step = 0; step < num_steps; step++) {
        for (int i = 0; i < num_cars; i++) {
            if (cars[i].start_pos == cars[i].end_pos) {
                cars[i].end_pos = cars[i].start_pos + rand() % (num_lanes - cars[i].start_pos);
            }

            int pos = cars[i].start_pos;
            int next_pos = cars[i].end_pos;

            for (int lane = pos; lane < next_pos; lane++) {
                lanes[lane]++;
            }
        }

        for (int lane = 0; lane < num_lanes; lane++) {
            lanes[lane] = (lanes[lane] > 0)? lanes[lane] - 1 : 0;
        }
    }

    for (int i = 0; i < num_cars; i++) {
        printf("%d: %d - %d @ %d\n", i, cars[i].start_pos, cars[i].end_pos, cars[i].speed);
    }

    free(cars);
    free(lanes);

    return 0;
}