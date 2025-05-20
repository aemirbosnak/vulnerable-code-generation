//MISTRAL-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct {
    int x;
    int y;
    bool is_car;
} entity;

void create_car(entity **cars, int *num_cars, int x, int y) {
    *cars = realloc(*cars, sizeof(entity) * (*num_cars + 1));
    (*cars)[*num_cars].x = x;
    (*cars)[*num_cars].y = y;
    (*cars)[*num_cars].is_car = true;
    (*num_cars)++;
}

void print_traffic(entity *cars, int num_cars) {
    for (int i = 0; i < num_cars; i++) {
        printf("Car %d at (%d, %d)\n", i + 1, cars[i].x, cars[i].y);
    }
}

void move_car(entity *car) {
    if (car->y > 0) {
        car->y--;
    } else {
        car->is_car = false;
    }
}

void move_cars(entity *cars, int num_cars) {
    for (int i = 0; i < num_cars; i++) {
        move_car(&cars[i]);
    }
}

void generate_random_car(entity **cars, int *num_cars) {
    int x = rand() % 10 + 1;
    int y = rand() % 5 + 1;
    create_car(cars, num_cars, x, y);
}

int main() {
    srand(time(NULL));
    entity *cars = NULL;
    int num_cars = 0;

    create_car(&cars, &num_cars, 5, 5);
    generate_random_car(&cars, &num_cars);
    generate_random_car(&cars, &num_cars);

    for (int i = 0; i < 10; i++) {
        generate_random_car(&cars, &num_cars);
    }

    printf("Initial Traffic:\n");
    print_traffic(cars, num_cars);

    for (int i = 0; i < 5; i++) {
        move_cars(cars, num_cars);
        printf("---\n");
        printf("Traffic after %d steps:\n", i + 1);
        print_traffic(cars, num_cars);
    }

    free(cars);
    return 0;
}