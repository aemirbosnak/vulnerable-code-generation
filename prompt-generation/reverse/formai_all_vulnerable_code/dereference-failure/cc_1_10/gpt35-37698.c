//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LANES 3
#define MIN_CAR_SPACING 2
#define MAX_CAR_SPACING 4
#define MIN_CAR_SPEED 40
#define MAX_CAR_SPEED 70
#define TIME_STEP 1
#define SIM_DURATION 60

struct car {
    int speed;
    int lane;
    int position;
};

void print_state(struct car *cars, int num_cars) {
    int i, j;
    int lanes[NUM_LANES][SIM_DURATION];
    
    // initialize empty lanes
    for (i = 0; i < NUM_LANES; i++) {
        for (j = 0; j < SIM_DURATION; j++) {
            lanes[i][j] = 0;
        }
    }
    
    // fill in occupied lanes
    for (i = 0; i < num_cars; i++) {
        lanes[cars[i].lane][cars[i].position] = 1;
    }
    
    // print state
    printf("\n");
    for (i = 0; i < NUM_LANES; i++) {
        printf("|");
        for (j = 0; j < SIM_DURATION; j++) {
            if (lanes[i][j]) {
                printf("*");
            } else {
                printf("-");
            }
        }
        printf("|\n");
    }
}

int move_cars(struct car *cars, int num_cars) {
    int i;
    int collision = 0;
    
    // move cars forward
    for (i = 0; i < num_cars; i++) {
        cars[i].position += cars[i].speed * TIME_STEP;
        
        // check for collisions
        if (i > 0 && cars[i].position - cars[i-1].position <= MIN_CAR_SPACING) {
            collision = 1;
        }
    }
    
    // randomly change lanes
    for (i = 0; i < num_cars; i++) {
        if (rand() % 2 == 0 && cars[i].lane > 0) {
            cars[i].lane--;
        } else if (rand() % 2 == 0 && cars[i].lane < NUM_LANES-1) {
            cars[i].lane++;
        }
    }
    
    return collision;
}

void spawn_car(struct car *cars, int *num_cars) {
    int speed = MIN_CAR_SPEED + rand() % (MAX_CAR_SPEED-MIN_CAR_SPEED+1);
    int lane = rand() % NUM_LANES;
    int position = rand() % (MAX_CAR_SPACING-MIN_CAR_SPACING+1) + MIN_CAR_SPACING;
    
    cars[*num_cars].speed = speed;
    cars[*num_cars].lane = lane;
    cars[*num_cars].position = position;
    
    (*num_cars)++;
}

void simulate_traffic() {
    struct car cars[100];
    int num_cars = 0;
    int time = 0;
    
    while (time < SIM_DURATION) {
        // spawn new cars randomly
        if (rand() % 2 == 0) {
            spawn_car(cars, &num_cars);
        }
        
        // move cars forward and check for collisions
        int collision = move_cars(cars, num_cars);
        if (collision) {
            printf("Collision occurred at time %d!\n", time);
            break;
        }
        
        // print state
        printf("Time: %d\n", time);
        print_state(cars, num_cars);
        
        time++;
    }
    
    printf("Simulation complete.\n");
}

int main() {
    srand(time(NULL));
    simulate_traffic();
    
    return 0;
}