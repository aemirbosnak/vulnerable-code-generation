//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LANES 4
#define MIN_CAR_LENGTH 3
#define MAX_CAR_LENGTH 6
#define MIN_CAR_SPEED 30
#define MAX_CAR_SPEED 65

struct Car {
    int length;
    int speed;
};

struct Lane {
    int num_cars;
    struct Car* cars;
};

struct Road {
    struct Lane lanes[NUM_LANES];
};

void initialize(struct Road* road) {
    for (int i = 0; i < NUM_LANES; i++) {
        int num_cars = rand() % 15 + 10; // generate number of cars between 10 and 25
        road->lanes[i].num_cars = num_cars;
        road->lanes[i].cars = (struct Car*)malloc(num_cars * sizeof(struct Car));
        for (int j = 0; j < num_cars; j++) {
            int length = rand() % (MAX_CAR_LENGTH - MIN_CAR_LENGTH + 1) + MIN_CAR_LENGTH; // generate car length between MIN_CAR_LENGTH and MAX_CAR_LENGTH inclusive
            int speed = rand() % (MAX_CAR_SPEED - MIN_CAR_SPEED + 1) + MIN_CAR_SPEED; // generate car speed between MIN_CAR_SPEED and MAX_CAR_SPEED inclusive
            road->lanes[i].cars[j] = (struct Car){ length, speed };
        }
    }
}

void update(struct Road* road) {
    // update the position of each car based on its speed and length
    for (int i = 0; i < NUM_LANES; i++) {
        for (int j = 0; j < road->lanes[i].num_cars; j++) {
            int prev_pos = j > 0 ? road->lanes[i].cars[j - 1].length : 0;
            int curr_pos = prev_pos + road->lanes[i].cars[j].speed;
            road->lanes[i].cars[j].length = curr_pos;
        }
    }
}

void render(struct Road* road) {
    // output the current state of the road to the console
    printf("+");
    for (int i = 0; i < NUM_LANES; i++) {
        for (int j = 0; j < road->lanes[i].num_cars; j++) {
            for (int k = 0; k < road->lanes[i].cars[j].length; k++) {
                printf("-");
            }
            printf("+");
        }
        printf("\n+");
    }
    for (int i = 0; i < NUM_LANES; i++) {
        printf(" | ");
    }
    printf("\n");
}

int main() {
    struct Road road;
    initialize(&road);

    for (int i = 0; i < 10; i++) { // run simulation for 10 steps
        update(&road);
        render(&road);
        printf("Press Enter to continue.\n");
        getchar(); // wait for user input
    }

    // free memory allocated for cars in each lane
    for (int i = 0; i < NUM_LANES; i++) {
        free(road.lanes[i].cars);
    }

    return 0;
}