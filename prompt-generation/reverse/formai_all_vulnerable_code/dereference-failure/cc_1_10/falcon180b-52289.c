//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS 10
#define MAX_CARS 50
#define MAX_WAIT_TIME 5

struct road {
    int num_cars;
    int wait_time;
};

void init_road(struct road *road) {
    road->num_cars = 0;
    road->wait_time = 0;
}

void add_car(struct road *road) {
    if (road->num_cars < MAX_CARS) {
        road->num_cars++;
        road->wait_time += rand() % MAX_WAIT_TIME + 1;
        printf("A car has been added to road %d. Current wait time: %d seconds.\n", road->num_cars, road->wait_time);
    } else {
        printf("Sorry, road %d is full.\n", road->num_cars);
    }
}

void remove_car(struct road *road) {
    if (road->num_cars > 0) {
        road->num_cars--;
        road->wait_time -= rand() % MAX_WAIT_TIME + 1;
        printf("A car has been removed from road %d. Current wait time: %d seconds.\n", road->num_cars, road->wait_time);
    } else {
        printf("Sorry, there are no cars on road %d.\n", road->num_cars);
    }
}

int main() {
    srand(time(NULL));

    struct road roads[MAX_ROADS];

    for (int i = 0; i < MAX_ROADS; i++) {
        init_road(&roads[i]);
    }

    int choice;

    while (1) {
        printf("Traffic Flow Simulation\n");
        printf("1. Add car\n");
        printf("2. Remove car\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter road number: ");
                scanf("%d", &choice);
                add_car(&roads[choice]);
                break;
            case 2:
                printf("Enter road number: ");
                scanf("%d", &choice);
                remove_car(&roads[choice]);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}