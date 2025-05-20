//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants
#define MAX_NUM_CARS 1000
#define MIN_SPEED_LIMIT 30
#define MAX_SPEED_LIMIT 60
#define TIME_INCREMENT 1
#define NUM_STREETS 5

typedef struct {
    int street_id;
    int position;
    int speed;
} Car;

void move_cars(Car *cars, int num_cars, int time);
void print_street(int street_id, Car *cars, int num_cars);

int main() {
    // initialize random seed
    srand(time(NULL));

    int num_cars = rand() % (MAX_NUM_CARS + 1);
    Car *cars = malloc(num_cars * sizeof(Car));

    // initialize cars
    for (int i = 0; i < num_cars; i++) {
        Car car = { rand() % NUM_STREETS, rand() % 100, rand() % (MAX_SPEED_LIMIT - MIN_SPEED_LIMIT + 1) + MIN_SPEED_LIMIT };
        cars[i] = car;
    }

    // simulate traffic flow
    for (int time = 0; time < 60; time += TIME_INCREMENT) {
        move_cars(cars, num_cars, time);
        printf("Time: %d\n", time);
        for (int i = 0; i < NUM_STREETS; i++) {
            printf("Street #%d\n", i);
            print_street(i, cars, num_cars);
        }
        printf("\n");
    }

    free(cars);
    return 0;
}

void move_cars(Car *cars, int num_cars, int time) {
    for (int i = 0; i < num_cars; i++) {
        if (cars[i].position <= 0) {
            cars[i].position = 0;
            continue;
        }

        if (cars[i].street_id == 0) {
            cars[i].speed = rand() % (MAX_SPEED_LIMIT - MIN_SPEED_LIMIT + 1) + MIN_SPEED_LIMIT;
        } else {
            Car front_car = { -1, -1, MAX_SPEED_LIMIT };
            for (int j = 0; j < num_cars; j++) {
                if (i != j && cars[j].street_id == cars[i].street_id && cars[j].position > cars[i].position && front_car.position > cars[j].position) {
                    front_car = cars[j];
                }
            }

            if (front_car.position != -1) {
                int distance = front_car.position - cars[i].position;
                int max_speed = (distance / TIME_INCREMENT) - 1;
                cars[i].speed = (max_speed < cars[i].speed) ? max_speed : cars[i].speed;
            }
        }

        cars[i].position += cars[i].speed * TIME_INCREMENT;
    }
}

void print_street(int street_id, Car *cars, int num_cars) {
    for (int i = 0; i < num_cars; i++) {
        if (cars[i].street_id == street_id) {
            printf("[");
            for (int j = 0; j < cars[i].position; j++) {
                printf(" ");
            }
            printf("X]\n");
        }
    }
}