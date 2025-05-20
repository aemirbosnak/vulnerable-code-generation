//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 100
#define MAX_CAPACITY 10
#define MIN_TIME 5
#define MAX_TIME 15

typedef struct {
    int baggage_id;
    int weight;
    int time_stamp;
} Baggage;

typedef struct {
    Baggage* baggage_list[MAX_CAPACITY];
    int current_capacity;
} ConveyorBelt;

typedef struct {
    int baggage_count;
} Destination;

void add_baggage_to_conveyor(ConveyorBelt* belt, Baggage* baggage) {
    if (belt->current_capacity < MAX_CAPACITY) {
        belt->baggage_list[belt->current_capacity] = baggage;
        belt->current_capacity++;
        printf("Baggage with ID %d added to conveyor belt\n", baggage->baggage_id);
    }
    else {
        printf("Conveyor belt is full. Cannot add more baggage\n");
    }
}

void remove_baggage_from_conveyor(ConveyorBelt* belt, Destination* dest) {
    int i;
    
    for (i = 0; i < belt->current_capacity; i++) {
        if (belt->baggage_list[i]->weight <= 50) {
            printf("Baggage with ID %d sent to destination %d\n", belt->baggage_list[i]->baggage_id, dest->baggage_count + 1);
            dest->baggage_count++;
            free(belt->baggage_list[i]);
            belt->baggage_list[i] = NULL;
        }
        else {
            printf("Baggage with ID %d is too heavy. Cannot send to destination\n", belt->baggage_list[i]->baggage_id);
        }
    }
    belt->current_capacity = 0;
}

int main() {
    ConveyorBelt belt = {0};
    Destination dest = {0};
    
    srand(time(NULL));
    
    int i;
    for (i = 0; i < MAX_BAGGAGE; i++) {
        Baggage* baggage = malloc(sizeof(Baggage));
        baggage->baggage_id = i + 1;
        baggage->weight = rand() % 100;
        baggage->time_stamp = rand() % (MAX_TIME - MIN_TIME + 1) + MIN_TIME;
        add_baggage_to_conveyor(&belt, baggage);
        sleep(baggage->time_stamp);
        remove_baggage_from_conveyor(&belt, &dest);
    }
    
    printf("All baggage handled successfully!\n");
    
    return 0;
}