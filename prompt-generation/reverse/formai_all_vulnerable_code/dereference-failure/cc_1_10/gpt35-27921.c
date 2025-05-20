//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BAGGAGE 50

typedef struct Baggage {
    int id;
    int weight;
} Baggage;

typedef struct ConveyorBelt {
    Baggage* bags[MAX_BAGGAGE];
    int num_bags;
    int capacity;
} ConveyorBelt;

typedef enum {
    SMALL,
    MEDIUM,
    LARGE
} BagSize;

typedef struct BaggageCheck {
    BagSize size;
    int weight;
} BaggageCheck;

typedef struct Scanner {
    bool is_scanning;
} Scanner;

// Function declarations
void initialize_conveyor_belt(ConveyorBelt* cb, int capacity);
void add_to_conveyor_belt(ConveyorBelt* cb, Baggage* bag);
void print_conveyor_belt(ConveyorBelt* cb);
void remove_from_conveyor_belt(ConveyorBelt* cb);
bool is_conveyor_belt_full(ConveyorBelt* cb);

int main() {
    srand(time(NULL));
    int num_bags = rand() % MAX_BAGGAGE + 1;
    printf("Num bags: %d\n", num_bags);

    // Initialize conveyor belt
    ConveyorBelt cb;
    initialize_conveyor_belt(&cb, 10);

    // Generate random bags
    for (int i = 0; i < num_bags; i++) {
        Baggage* bag = malloc(sizeof(Baggage));
        bag->id = i;
        bag->weight = rand() % 50 + 1; // Random weight between 1 and 50
        add_to_conveyor_belt(&cb, bag);
    }

    // Print conveyor belt
    printf("\nConveyor Belt:\n");
    print_conveyor_belt(&cb);

    // Scan bags for security check
    int num_scanned = 0;
    Scanner scanner = { .is_scanning = true };
    while (scanner.is_scanning) {
        printf("Scanner is scanning...\n");
        if (cb.num_bags > 0) {
            remove_from_conveyor_belt(&cb);
            num_scanned++;
            printf("Bag scanned!\n");
        }
        if (num_scanned == num_bags) {
            scanner.is_scanning = false;
            printf("All bags have been scanned.\n");
        }
    }

    // Free bag memory
    for (int i = 0; i < num_bags; i++) {
        free(cb.bags[i]);
    }

    return 0;
}

void initialize_conveyor_belt(ConveyorBelt* cb, int capacity) {
    cb->num_bags = 0;
    cb->capacity = capacity;
}

void add_to_conveyor_belt(ConveyorBelt* cb, Baggage* bag) {
    if (is_conveyor_belt_full(cb)) {
        printf("Conveyor belt is full! Cannot add bag.\n");
        return;
    }

    cb->bags[cb->num_bags] = bag;
    cb->num_bags++;
}

void print_conveyor_belt(ConveyorBelt* cb) {
    printf("Capacity: %d\n", cb->capacity);
    printf("Number of bags: %d\n", cb->num_bags);
    printf("Bags:\n");
    for (int i = 0; i < cb->num_bags; i++) {
        printf("Bag %d - Weight: %d\n", cb->bags[i]->id, cb->bags[i]->weight);
    }
}

void remove_from_conveyor_belt(ConveyorBelt* cb) {
    if (cb->num_bags == 0) {
        printf("Conveyor belt is empty! Nothing to remove.\n");
        return;
    }
    printf("Removing bag %d from conveyor belt.\n", cb->bags[0]->id);
    for (int i = 0; i < cb->num_bags - 1; i++) {
        cb->bags[i] = cb->bags[i + 1];
    }
    cb->num_bags--;
}

bool is_conveyor_belt_full(ConveyorBelt* cb) {
    return cb->num_bags == cb->capacity;
}