//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define constants */
#define MAX_TIME 100
#define NUM_LANES 3
#define MIN_CAR_LENGTH 10
#define MAX_CAR_LENGTH 20
#define MIN_CAR_GAP 2
#define MAX_CAR_GAP 5
#define MIN_SPEED 10
#define MAX_SPEED 30

/* Define car struct */
typedef struct car_t {
    int length;
    int speed;
} car;

/* Define lane struct */
typedef struct lane_t {
    car *cars;
    int num_cars;
} lane;

/* Function prototypes */
void print_lane(lane l, int time);
void update_lane(lane *l, lane *prev, lane *next);

int main() {
    /* Seed random number generator */
    srand(time(NULL));

    /* Initialize lanes */
    lane lanes[NUM_LANES];
    for (int i = 0; i < NUM_LANES; i++) {
        lanes[i].num_cars = rand() % 10 + 1;
        lanes[i].cars = malloc(lanes[i].num_cars * sizeof(car));
        for (int j = 0; j < lanes[i].num_cars; j++) {
            lanes[i].cars[j].length = rand() % (MAX_CAR_LENGTH - MIN_CAR_LENGTH + 1) + MIN_CAR_LENGTH;
            lanes[i].cars[j].speed = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
        }
        print_lane(lanes[i], 0);
    }

    /* Simulate traffic flow */
    for (int t = 1; t <= MAX_TIME; t++) {
        /* Update each lane */
        for (int i = 0; i < NUM_LANES; i++) {
            update_lane(&lanes[i], (i > 0) ? &lanes[i-1] : NULL, (i < NUM_LANES-1) ? &lanes[i+1] : NULL);
            print_lane(lanes[i], t);
        }
    }

    /* Free memory allocated for cars */
    for (int i = 0; i < NUM_LANES; i++) {
        free(lanes[i].cars);
    }

    return 0;
}

void print_lane(lane l, int time) {
    printf("Time: %d\n", time);
    for (int i = 0; i < l.num_cars; i++) {
        for (int j = 0; j < l.cars[i].length; j++) {
            printf("=");
        }
        printf(" ");
    }
    printf("\n");
}

void update_lane(lane *l, lane *prev, lane *next) {
    /* Move each car forward based on their speed */
    for (int i = 0; i < l->num_cars; i++) {
        car *c = &l->cars[i];
        int dist_to_prev = (prev != NULL) ? prev->num_cars - i : 0;
        int dist_to_next = (next != NULL) ? i - l->num_cars : 0;
        if (c->speed <= dist_to_prev && c->speed <= dist_to_next) {
            c->length += c->speed;
        }
    }

    /* Add new cars randomly */
    if (l->num_cars == 0 || rand() % MAX_CAR_GAP + 1 <= MIN_CAR_GAP) {
        l->num_cars++;
        l->cars = realloc(l->cars, l->num_cars * sizeof(car));
        l->cars[l->num_cars-1].length = rand() % (MAX_CAR_LENGTH - MIN_CAR_LENGTH + 1) + MIN_CAR_LENGTH;
        l->cars[l->num_cars-1].speed = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
    }
}