//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: lively
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_LANE 3
#define MAX_CARS 10

typedef struct Car {
    int lane;
    int position;
    int speed;
    struct Car* next;
} Car;

void create_car(Car** head) {
    *head = malloc(sizeof(Car));
    (*head)->lane = rand() % NUM_LANE;
    (*head)->position = rand() % 1000;
    (*head)->speed = rand() % 5 + 1;
    (*head)->next = NULL;
}

void move_cars(Car* head) {
    Car* current = head;
    while (current) {
        current->position += current->speed;
        if (current->position >= 1000) {
            current->position = 0;
        }
        current = current->next;
    }
}

void simulate_traffic(int num_cars) {
    Car* head = NULL;
    for (int i = 0; i < num_cars; i++) {
        create_car(&head);
    }

    time_t start_time = time(NULL);
    while (time(NULL) - start_time < 30) {
        move_cars(head);
        sleep(1);
    }

    free(head);
}

int main() {
    simulate_traffic(5);
    return 0;
}