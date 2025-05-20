//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct car {
    int x, y, direction, speed, lane;
    struct car* next;
} car;

void initialize_traffic_flow(car** head) {
    *head = NULL;
    for (int i = 0; i < MAX_CARS; i++) {
        *head = malloc(sizeof(car));
        (*head)->x = rand() % 100;
        (*head)->y = rand() % 100;
        (*head)->direction = rand() % 4;
        (*head)->speed = rand() % 5 + 1;
        (*head)->lane = rand() % 3;
        (*head)->next = NULL;
        head = &((*head)->next);
    }
}

void simulate_traffic_flow(car* head) {
    time_t start_time = time(NULL);
    while (time(NULL) - start_time < 60) {
        for (car* car_ptr = head; car_ptr; car_ptr = car_ptr->next) {
            switch (car_ptr->direction) {
                case 0:
                    car_ptr->x++;
                    break;
                case 1:
                    car_ptr->x--;
                    break;
                case 2:
                    car_ptr->y++;
                    break;
                case 3:
                    car_ptr->y--;
                    break;
            }
            car_ptr->x = (car_ptr->x + MAX_CARS) % MAX_CARS;
            car_ptr->y = (car_ptr->y + MAX_CARS) % MAX_CARS;
        }
        sleep(1);
    }
}

int main() {
    car* head = NULL;
    initialize_traffic_flow(&head);
    simulate_traffic_flow(head);
    return 0;
}