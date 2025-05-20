//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct car {
    int x;
    int y;
    int speed;
};

struct road {
    int x1;
    int y1;
    int x2;
    int y2;
};

void simulate_traffic_flow(int num_cars, int num_roads) {
    srand(time(NULL));

    struct car* cars = malloc(num_cars * sizeof(struct car));
    struct road* roads = malloc(num_roads * sizeof(struct road));

    for (int i = 0; i < num_cars; i++) {
        cars[i].x = rand() % 100;
        cars[i].y = rand() % 100;
        cars[i].speed = (rand() % 10) + 1;
    }

    for (int i = 0; i < num_roads; i++) {
        roads[i].x1 = rand() % 100;
        roads[i].y1 = rand() % 100;
        roads[i].x2 = rand() % 100;
        roads[i].y2 = rand() % 100;
    }

    int collisions = 0;
    for (int i = 0; i < num_cars; i++) {
        for (int j = 0; j < num_roads; j++) {
            struct car* car = &cars[i];
            struct road* road = &roads[j];

            if (car->x >= road->x1 && car->x <= road->x2 &&
                car->y >= road->y1 && car->y <= road->y2) {
                car->speed = 0;
                collisions++;
                break;
            }
        }
    }

    printf("Number of collisions: %d\n", collisions);
    free(cars);
    free(roads);
}

int main() {
    int num_cars = 10;
    int num_roads = 5;
    simulate_traffic_flow(num_cars, num_roads);
    return 0;
}