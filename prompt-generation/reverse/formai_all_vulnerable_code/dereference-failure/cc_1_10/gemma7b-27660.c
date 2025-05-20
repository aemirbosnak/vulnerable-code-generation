//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: shape shifting
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 100

typedef struct Car {
    int x, y, direction, speed;
    struct Car* next;
} Car;

void create_car(Car** head) {
    *head = malloc(sizeof(Car));
    (*head)->x = rand() % 1000;
    (*head)->y = rand() % 1000;
    (*head)->direction = rand() % 4;
    (*head)->speed = rand() % 5 + 1;
    (*head)->next = NULL;
}

void move_cars(Car* head) {
    Car* current = head;
    while (current) {
        switch (current->direction) {
            case 0:
                current->x++;
                break;
            case 1:
                current->y++;
                break;
            case 2:
                current->x--;
                break;
            case 3:
                current->y--;
                break;
        }
        current->x = (current->x + current->speed) % 1000;
        current->y = (current->y + current->speed) % 1000;
        current = current->next;
    }
}

void draw_cars(Car* head) {
    Car* current = head;
    while (current) {
        printf("(");
        printf("%d, %d)", current->x, current->y);
        printf(")\n");
        current = current->next;
    }
}

int main() {
    srand(time(NULL));

    Car* head = NULL;
    create_car(&head);
    move_cars(head);
    draw_cars(head);

    return 0;
}