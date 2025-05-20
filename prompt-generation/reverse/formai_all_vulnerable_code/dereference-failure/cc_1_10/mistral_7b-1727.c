//MISTRAL-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int id;
    char destination[50];
    int weight;
} Baggage;

typedef struct {
    int capacity;
    int num_baggage;
    Baggage* bags;
} ConveyorBelt;

void create_conveyor_belt(ConveyorBelt* cb, int capacity) {
    cb->capacity = capacity;
    cb->num_baggage = 0;
    cb->bags = (Baggage*) calloc(capacity, sizeof(Baggage));
}

void add_baggage(ConveyorBelt* cb, int id, const char* destination, int weight) {
    if (cb->num_baggage >= cb->capacity) {
        printf("Error: Conveyor belt is full.\n");
        return;
    }

    Baggage new_baggage = { id, destination, weight };
    cb->bags[cb->num_baggage] = new_baggage;
    cb->num_baggage++;
}

void handle_baggage(ConveyorBelt* cb) {
    int i;
    for (i = 0; i < cb->num_baggage; i++) {
        printf("Baggage %d (%s, %d kg) handled.\n", cb->bags[i].id, cb->bags[i].destination, cb->bags[i].weight);
    }

    free(cb->bags);
    cb->bags = NULL;
    cb->num_baggage = 0;
}

int main() {
    srand(time(NULL));

    ConveyorBelt cb;
    create_conveyor_belt(&cb, 10);

    int num_baggage = 15;
    for (int i = 0; i < num_baggage; i++) {
        int id = rand() % 100;
        char destination[50];
        sprintf(destination, "Destination %d", rand() % 10 + 1);
        int weight = rand() % 51 + 5;

        add_baggage(&cb, id, destination, weight);
    }

    printf("Handling baggage...\n");
    handle_baggage(&cb);

    return 0;
}