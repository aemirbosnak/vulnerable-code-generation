//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CARS 100

typedef struct car {
    int position;
    int speed;
    int lane;
    struct car* next;
} car_t;

car_t* create_car(int position, int speed, int lane) {
    car_t* new_car = malloc(sizeof(car_t));
    new_car->position = position;
    new_car->speed = speed;
    new_car->lane = lane;
    new_car->next = NULL;
    return new_car;
}

void add_car(car_t** head, int position, int speed, int lane) {
    car_t* new_car = create_car(position, speed, lane);
    if (*head == NULL) {
        *head = new_car;
    } else {
        car_t* current = *head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_car;
    }
}

void remove_car(car_t** head) {
    if (*head!= NULL) {
        car_t* current = *head;
        *head = current->next;
        free(current);
    }
}

void print_cars(car_t* head) {
    car_t* current = head;
    while (current!= NULL) {
        printf("Car %d is in lane %d at position %d with speed %d\n",
               current->position, current->lane, current->position, current->speed);
        current = current->next;
    }
}

void simulate_traffic() {
    car_t* head = NULL;
    int num_cars = 0;

    add_car(&head, 0, 50, 1);
    add_car(&head, 1, 50, 1);
    add_car(&head, 2, 50, 1);
    add_car(&head, 3, 50, 1);
    add_car(&head, 4, 50, 1);
    add_car(&head, 5, 50, 1);

    printf("Initial traffic:\n");
    print_cars(head);

    // Simulate traffic flow for 10 seconds
    for (int i = 0; i < 10; i++) {
        car_t* current = head;
        while (current!= NULL) {
            int next_position = current->position + current->speed;
            if (next_position >= 100) {
                next_position = 0;
                current->lane =!current->lane;
                if (current->next!= NULL) {
                    current->next->lane =!current->next->lane;
                }
            }
            current = current->next;
        }

        printf("After %d seconds:\n", i + 1);
        print_cars(head);
        num_cars = 0;
        while (head!= NULL) {
            num_cars++;
            head = head->next;
        }
        printf("There are now %d cars on the road.\n", num_cars);
    }
}

int main() {
    simulate_traffic();
    return 0;
}