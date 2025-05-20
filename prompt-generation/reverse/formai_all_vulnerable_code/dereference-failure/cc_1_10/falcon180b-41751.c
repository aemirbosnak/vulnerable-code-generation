//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS 10
#define MAX_CARS 100

struct road {
    int length;
    int speed_limit;
    int num_cars;
    int *cars;
};

struct car {
    int speed;
    int position;
    int destination;
};

void create_road(struct road *road, int length, int speed_limit) {
    road->length = length;
    road->speed_limit = speed_limit;
    road->num_cars = 0;
    road->cars = malloc(MAX_CARS * sizeof(int));
}

void add_car(struct road *road, int speed, int destination) {
    if (road->num_cars >= MAX_CARS) {
        printf("Road is full.\n");
        return;
    }

    int position = 0;
    while (position < road->length && road->cars[position]!= -1) {
        position++;
    }

    road->cars[position] = speed;
    road->num_cars++;
}

void remove_car(struct road *road, int position) {
    road->cars[position] = -1;
    road->num_cars--;
}

int main() {
    srand(time(NULL));

    struct road road1;
    create_road(&road1, 100, 50);

    add_car(&road1, 30, 80);
    add_car(&road1, 50, 20);

    int i;
    for (i = 0; i < 100; i++) {
        int speed = rand() % 101;
        int destination = rand() % 101;
        add_car(&road1, speed, destination);
    }

    int j;
    for (j = 0; j < 100; j++) {
        remove_car(&road1, rand() % road1.length);
    }

    return 0;
}