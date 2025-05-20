//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct car {
    int speed;
    int position;
    struct car *next;
} car;

typedef struct road {
    int length;
    car *head;
} road;

void create_road(road *r, int length) {
    r->length = length;
    r->head = NULL;
}

void add_car(road *r, int speed) {
    car *new_car = malloc(sizeof(car));
    new_car->speed = speed;
    new_car->position = 0;
    new_car->next = r->head;
    r->head = new_car;
}

void move_cars(road *r) {
    car *curr = r->head;
    while (curr != NULL) {
        curr->position += curr->speed;
        if (curr->position >= r->length) {
            r->head = curr->next;
            free(curr);
        } else {
            curr = curr->next;
        }
    }
}

void print_road(road *r) {
    car *curr = r->head;
    while (curr != NULL) {
        for (int i = 0; i < curr->position; i++) {
            printf("=");
        }
        printf("o");
        for (int i = curr->position + 1; i < r->length; i++) {
            printf("=");
        }
        printf("\n");
        curr = curr->next;
    }
}

int main() {
    srand(time(NULL));

    road r;
    create_road(&r, 100);

    for (int i = 0; i < 10; i++) {
        add_car(&r, rand() % 10 + 1);
    }

    while (1) {
        move_cars(&r);
        print_road(&r);
        sleep(1);
    }

    return 0;
}