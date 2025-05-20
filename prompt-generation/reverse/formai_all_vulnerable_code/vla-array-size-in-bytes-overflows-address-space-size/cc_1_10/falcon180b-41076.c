//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ROADS 10
#define MAX_CARS 100

struct road {
    int length;
    int speed_limit;
    int num_cars;
};

struct car {
    int id;
    int speed;
    int position;
    int destination;
};

void generate_cars(struct car cars[], int num_cars) {
    srand(time(NULL));
    for (int i = 0; i < num_cars; i++) {
        cars[i].id = i + 1;
        cars[i].speed = rand() % 101;
        cars[i].position = 0;
        cars[i].destination = rand() % MAX_ROADS;
    }
}

void generate_roads(struct road roads[], int num_roads) {
    for (int i = 0; i < num_roads; i++) {
        roads[i].length = rand() % 101;
        roads[i].speed_limit = rand() % 101;
        roads[i].num_cars = 0;
    }
}

void move_cars(struct car cars[], struct road roads[], int num_cars, int num_roads) {
    for (int i = 0; i < num_cars; i++) {
        int road_id = cars[i].destination;
        if (roads[road_id].num_cars < roads[road_id].length) {
            roads[road_id].num_cars++;
            cars[i].position++;
        } else {
            printf("Car %d is stuck on road %d\n", cars[i].id, road_id);
        }
    }
}

int main() {
    int num_cars, num_roads;
    printf("Enter the number of cars: ");
    scanf("%d", &num_cars);
    printf("Enter the number of roads: ");
    scanf("%d", &num_roads);

    struct car cars[num_cars];
    generate_cars(cars, num_cars);

    struct road roads[num_roads];
    generate_roads(roads, num_roads);

    while (1) {
        system("clear");
        for (int i = 0; i < num_roads; i++) {
            printf("Road %d: Length %d, Speed Limit %d, Number of Cars %d\n", i + 1, roads[i].length, roads[i].speed_limit, roads[i].num_cars);
        }
        printf("\n");
        move_cars(cars, roads, num_cars, num_roads);
        sleep(1);
    }

    return 0;
}