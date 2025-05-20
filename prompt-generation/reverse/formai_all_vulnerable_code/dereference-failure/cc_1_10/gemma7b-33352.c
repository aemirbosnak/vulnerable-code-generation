//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_ROAD_LENGTH 20

typedef struct Car {
    int x, y, direction, speed;
    struct Car* next;
} Car;

void initialize_traffic_flow(Car** head) {
    *head = NULL;
    for (int i = 0; i < MAX_CARS; i++) {
        Car* new_car = malloc(sizeof(Car));
        new_car->x = rand() % MAX_ROAD_LENGTH;
        new_car->y = rand() % MAX_ROAD_LENGTH;
        new_car->direction = rand() % 2;
        new_car->speed = rand() % 5;
        new_car->next = *head;
        *head = new_car;
    }
}

void simulate_traffic_flow(Car* head) {
    time_t start_time = time(NULL);
    while (time(NULL) - start_time < 60) {
        for (Car* current_car = head; current_car; current_car = current_car->next) {
            switch (current_car->direction) {
                case 0:
                    current_car->x++;
                    break;
                case 1:
                    current_car->x--;
                    break;
            }

            current_car->y++;
            sleep(current_car->speed);
        }

        printf("Traffic flow simulation:\n");
        for (Car* current_car = head; current_car; current_car = current_car->next) {
            printf("Car location: (%d, %d)\n", current_car->x, current_car->y);
        }

        printf("\n");
    }
}

int main() {
    Car* head = NULL;
    initialize_traffic_flow(&head);
    simulate_traffic_flow(head);

    return 0;
}