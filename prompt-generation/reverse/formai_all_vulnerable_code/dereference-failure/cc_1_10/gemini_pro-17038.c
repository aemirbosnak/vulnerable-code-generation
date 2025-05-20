//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BAGS 1000
#define CONVEYORS 5
#define CHECK_IN 0
#define SECURITY 1
#define DEPARTURE 2

typedef struct bag {
    int id;
    int origin;
    int destination;
    int status;
} bag;

typedef struct conveyor {
    int id;
    int origin;
    int destination;
    bag *bags[BAGS];
    int count;
} conveyor;

conveyor conveyors[CONVEYORS];

void init_conveyors() {
    for (int i = 0; i < CONVEYORS; i++) {
        conveyors[i].id = i;
        conveyors[i].count = 0;
    }
    conveyors[0].origin = CHECK_IN;
    conveyors[0].destination = SECURITY;
    conveyors[1].origin = SECURITY;
    conveyors[1].destination = DEPARTURE;
    conveyors[2].origin = DEPARTURE;
    conveyors[2].destination = CHECK_IN;
}

void init_bags() {
    for (int i = 0; i < BAGS; i++) {
        bag *b = malloc(sizeof(bag));
        b->id = i;
        b->origin = CHECK_IN;
        b->destination = DEPARTURE;
        b->status = 0;
    }
}

void move_bags() {
    for (int i = 0; i < CONVEYORS; i++) {
        conveyor *c = &conveyors[i];
        for (int j = 0; j < c->count; j++) {
            bag *b = c->bags[j];
            if (b->status == 0) {
                c->bags[j] = NULL;
                c->count--;
                b->origin = c->destination;
                if (b->origin == b->destination) {
                    b->status = 1;
                } else {
                    conveyors[b->origin].bags[conveyors[b->origin].count++] = b;
                }
            }
        }
    }
}

void print_status() {
    for (int i = 0; i < CONVEYORS; i++) {
        conveyor *c = &conveyors[i];
        printf("Conveyor %d: ", c->id);
        for (int j = 0; j < c->count; j++) {
            printf("%d ", c->bags[j]->id);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    init_conveyors();
    init_bags();

    for (int i = 0; i < 100; i++) {
        move_bags();
        print_status();
    }

    return 0;
}