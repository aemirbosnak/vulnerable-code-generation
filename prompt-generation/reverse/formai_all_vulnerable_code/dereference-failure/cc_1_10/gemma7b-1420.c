//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: beginner-friendly
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10

typedef struct car {
    int x, y, direction, speed;
    struct car* next;
} car;

car* create_car() {
    car* new_car = malloc(sizeof(car));
    new_car->x = 0;
    new_car->y = 0;
    new_car->direction = 1;
    new_car->speed = 1;
    new_car->next = NULL;
    return new_car;
}

void move_car(car* car) {
    switch (car->direction) {
        case 1:
            car->x++;
            break;
        case 2:
            car->y++;
            break;
        case 3:
            car->x--;
            break;
        case 4:
            car->y--;
            break;
    }
}

void simulate_traffic(int num_cars) {
    car* head = NULL;
    for (int i = 0; i < num_cars; i++) {
        car* new_car = create_car();
        head = new_car;
        if (head->next) {
            head = head->next;
        }
    }

    srand(time(NULL));

    for (int t = 0; t < 10; t++) {
        for (car* car = head; car; car = car->next) {
            move_car(car);
            printf("%d %d\n", car->x, car->y);
        }
        printf("\n");
    }
}

int main() {
    simulate_traffic(5);
    return 0;
}