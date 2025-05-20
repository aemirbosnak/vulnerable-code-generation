//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 50
#define ROAD_LENGTH 1000

typedef struct Car {
    int x, y, direction, speed;
    struct Car* next;
} Car;

void initialize_cars(Car** head) {
    *head = NULL;
    for (int i = 0; i < MAX_CARS; i++) {
        Car* new_car = (Car*)malloc(sizeof(Car));
        new_car->x = rand() % ROAD_LENGTH;
        new_car->y = rand() % ROAD_LENGTH;
        new_car->direction = rand() % 4;
        new_car->speed = rand() % 5 + 1;
        new_car->next = *head;
        *head = new_car;
    }
}

void simulate_traffic(Car* head) {
    time_t start_time = time(NULL);
    while (time(NULL) - start_time < 60) {
        for (Car* car = head; car; car = car->next) {
            switch (car->direction) {
                case 0:
                    car->x++;
                    break;
                case 1:
                    car->x--;
                    break;
                case 2:
                    car->y++;
                    break;
                case 3:
                    car->y--;
                    break;
            }

            car->x = (car->x + ROAD_LENGTH) % ROAD_LENGTH;
            car->y = (car->y + ROAD_LENGTH) % ROAD_LENGTH;
        }

        sleep(1);
    }
}

int main() {
    Car* head = NULL;
    initialize_cars(&head);
    simulate_traffic(head);

    return 0;
}