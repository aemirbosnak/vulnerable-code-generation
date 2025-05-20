//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct car {
    int id;
    int speed;
    int distance_to_next_car;
    struct car *next;
} car;

typedef struct lane {
    car *head;
    car *tail;
} lane;

void create_lane(lane *l) {
    l->head = NULL;
    l->tail = NULL;
}

void add_car_to_lane(lane *l, int id, int speed, int distance_to_next_car) {
    car *new_car = malloc(sizeof(car));
    new_car->id = id;
    new_car->speed = speed;
    new_car->distance_to_next_car = distance_to_next_car;
    new_car->next = NULL;
    if (l->head == NULL) {
        l->head = new_car;
        l->tail = new_car;
    } else {
        l->tail->next = new_car;
        l->tail = new_car;
    }
}

void print_lane(lane *l) {
    car *current_car = l->head;
    while (current_car != NULL) {
        printf("Car %d: speed %d, distance to next car %d\n", current_car->id, current_car->speed, current_car->distance_to_next_car);
        current_car = current_car->next;
    }
}

void update_lane(lane *l) {
    car *current_car = l->head;
    while (current_car != NULL) {
        current_car->distance_to_next_car -= current_car->speed;
        if (current_car->distance_to_next_car <= 0) {
            current_car->speed = 0;
        }
        current_car = current_car->next;
    }
}

int main() {
    srand(time(NULL));

    lane l;
    create_lane(&l);

    for (int i = 0; i < 10; i++) {
        int id = i;
        int speed = rand() % 10 + 1;
        int distance_to_next_car = rand() % 100 + 1;
        add_car_to_lane(&l, id, speed, distance_to_next_car);
    }

    print_lane(&l);

    for (int i = 0; i < 10; i++) {
        update_lane(&l);
        print_lane(&l);
    }

    return 0;
}