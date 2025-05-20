//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: satisfied
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car {
    int lane;
    int position;
    int direction;
    struct Car* next;
} Car;

void create_car(Car** head) {
    *head = malloc(sizeof(Car));
    (*head)->lane = rand() % MAX_LANE;
    (*head)->position = rand() % 100;
    (*head)->direction = rand() % 2;
    (*head)->next = NULL;
}

void move_cars(Car* head) {
    Car* current = head;
    while (current) {
        switch (current->direction) {
            case 0:
                current->position++;
                break;
            case 1:
                current->position--;
                break;
        }

        if (current->position >= 100) {
            current->direction = 1;
            current->position = 0;
        }

        if (current->position <= 0) {
            current->direction = 0;
            current->position = 100;
        }

        current = current->next;
    }
}

int main() {
    srand(time(NULL));

    Car* head = NULL;
    create_car(&head);
    create_car(&head);
    create_car(&head);

    move_cars(head);

    return 0;
}