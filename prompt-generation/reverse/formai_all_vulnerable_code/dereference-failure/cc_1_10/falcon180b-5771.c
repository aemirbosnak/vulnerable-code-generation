//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS 100
#define MAX_CARS 1000
#define MAX_WAIT_TIME 10

typedef struct {
    int num_cars;
    int wait_time;
} Road;

void init_road(Road *road) {
    road->num_cars = 0;
    road->wait_time = 0;
}

void add_car(Road *road) {
    if (road->num_cars >= MAX_CARS) {
        printf("Road is full. Please wait.\n");
        return;
    }
    road->num_cars++;
}

void remove_car(Road *road) {
    road->num_cars--;
}

int get_num_cars(Road *road) {
    return road->num_cars;
}

int get_wait_time(Road *road) {
    return road->wait_time;
}

void set_wait_time(Road *road, int wait_time) {
    road->wait_time = wait_time;
}

int main() {
    int num_roads;
    printf("Enter the number of roads: ");
    scanf("%d", &num_roads);

    Road roads[MAX_ROADS];
    for (int i = 0; i < num_roads; i++) {
        init_road(&roads[i]);
    }

    int choice;
    while (1) {
        printf("\nTraffic Flow Simulation\n");
        printf("1. Add car\n2. Remove car\n3. Get number of cars\n4. Get wait time\n5. Set wait time\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the road number: ");
                scanf("%d", &choice);
                add_car(&roads[choice]);
                break;
            case 2:
                printf("Enter the road number: ");
                scanf("%d", &choice);
                remove_car(&roads[choice]);
                break;
            case 3:
                printf("Enter the road number: ");
                scanf("%d", &choice);
                printf("Number of cars: %d\n", get_num_cars(&roads[choice]));
                break;
            case 4:
                printf("Enter the road number: ");
                scanf("%d", &choice);
                printf("Wait time: %d\n", get_wait_time(&roads[choice]));
                break;
            case 5:
                printf("Enter the road number: ");
                scanf("%d", &choice);
                printf("Enter the wait time: ");
                scanf("%d", &choice);
                set_wait_time(&roads[choice], choice);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}