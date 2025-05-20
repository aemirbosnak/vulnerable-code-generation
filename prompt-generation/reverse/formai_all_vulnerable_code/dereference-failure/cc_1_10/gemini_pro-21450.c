//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Car {
    int id;
    int speed;
    int position;
};

struct Road {
    int length;
    struct Car *cars;
};

void create_road(struct Road *road, int length) {
    road->length = length;
    road->cars = malloc(sizeof(struct Car) * length);
    for (int i = 0; i < length; i++) {
        road->cars[i].id = i;
        road->cars[i].speed = rand() % 10 + 1;
        road->cars[i].position = i;
    }
}

void move_cars(struct Road *road) {
    for (int i = 0; i < road->length; i++) {
        if (road->cars[i].speed > 0) {
            road->cars[i].position += road->cars[i].speed;
            if (road->cars[i].position >= road->length) {
                road->cars[i].position -= road->length;
            }
        }
    }
}

void print_road(struct Road *road) {
    for (int i = 0; i < road->length; i++) {
        printf("%d", road->cars[i].id);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    struct Road road;
    create_road(&road, 10);

    for (int i = 0; i < 100; i++) {
        move_cars(&road);
        print_road(&road);
    }

    return 0;
}