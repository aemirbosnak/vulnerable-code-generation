//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS 10
#define MAX_CARS 100
#define MAX_CAR_SPEED 100

struct road {
    int id;
    int length;
    int capacity;
    int cars;
};

struct car {
    int id;
    int speed;
    int position;
};

struct road* create_road(int id, int length, int capacity) {
    struct road* road = (struct road*)malloc(sizeof(struct road));
    road->id = id;
    road->length = length;
    road->capacity = capacity;
    road->cars = 0;
    return road;
}

struct car* create_car(int id, int speed, int position) {
    struct car* car = (struct car*)malloc(sizeof(struct car));
    car->id = id;
    car->speed = speed;
    car->position = position;
    return car;
}

void simulate_traffic() {
    srand(time(0));

    struct road* roads[MAX_ROADS] = {NULL};
    struct car* cars[MAX_CARS] = {NULL};

    for (int i = 0; i < MAX_ROADS; i++) {
        roads[i] = create_road(i, rand() % 100 + 1, rand() % 10 + 1);
    }

    for (int i = 0; i < MAX_CARS; i++) {
        cars[i] = create_car(i, rand() % MAX_CAR_SPEED + 1, rand() % 100 + 1);
    }

    while (1) {
        for (int i = 0; i < MAX_ROADS; i++) {
            int num_cars = rand() % roads[i]->capacity;
            for (int j = 0; j < num_cars; j++) {
                int new_speed = cars[rand() % MAX_CARS]->speed + (rand() % 5 - 2);
                int new_position = cars[rand() % MAX_CARS]->position + (rand() % roads[i]->length);
                if (new_position >= 0 && new_position < roads[i]->length && new_speed <= MAX_CAR_SPEED) {
                    cars[rand() % MAX_CARS]->speed = new_speed;
                    cars[rand() % MAX_CARS]->position = new_position;
                    roads[i]->cars++;
                    printf("Car %d on road %d is moving at speed %d and position %d.\n", cars[rand() % MAX_CARS]->id, i, cars[rand() % MAX_CARS]->speed, cars[rand() % MAX_CARS]->position);
                }
            }
        }

        printf("Traffic simulation complete.\n");
        break;
    }
}

int main() {
    simulate_traffic();
    return 0;
}