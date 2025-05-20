//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: ultraprecise
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 1000
#define NUM_CARS 100
#define MAX_SPEED 10

typedef struct {
    int32_t position;
    int32_t speed;
} car_t;

typedef struct {
    car_t *cars;
    uint32_t num_cars;
} road_t;

void init_road(road_t *road) {
    road->cars = malloc(sizeof(car_t) * NUM_CARS);
    road->num_cars = NUM_CARS;

    for (uint32_t i = 0; i < NUM_CARS; i++) {
        road->cars[i].position = rand() % ROAD_LENGTH;
        road->cars[i].speed = rand() % MAX_SPEED;
    }
}

void update_road(road_t *road) {
    for (uint32_t i = 0; i < NUM_CARS; i++) {
        road->cars[i].position += road->cars[i].speed;

        if (road->cars[i].position >= ROAD_LENGTH) {
            road->cars[i].position -= ROAD_LENGTH;
        }

        for (uint32_t j = i + 1; j < NUM_CARS; j++) {
            if (road->cars[i].position == road->cars[j].position) {
                road->cars[i].speed = 0;
                road->cars[j].speed = 0;
            }
        }
    }
}

void print_road(road_t *road) {
    for (uint32_t i = 0; i < ROAD_LENGTH; i++) {
        bool car_at_position = false;

        for (uint32_t j = 0; j < NUM_CARS; j++) {
            if (road->cars[j].position == i) {
                car_at_position = true;
                break;
            }
        }

        if (car_at_position) {
            printf("#");
        } else {
            printf("-");
        }
    }

    printf("\n");
}

int main() {
    srand(time(NULL));

    road_t road;
    init_road(&road);

    for (uint32_t i = 0; i < 100; i++) {
        update_road(&road);
        print_road(&road);
    }

    return 0;
}