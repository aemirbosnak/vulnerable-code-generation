//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 50

typedef struct Baggage {
    int id; // Baggage identification number
    int weight; // Baggage weight in kg
    int destination; // Destination airport code
} Baggage;

typedef struct Bin {
    int capacity; // Capacity (in kg) of the bin
    int current_weight; // Current weight (in kg) of the bin
    Baggage **baggage; // Array of pointers to Baggage objects
} Bin;

int generate_random_weight();
int generate_random_destination();
Bin *create_bin(int capacity);
int add_baggage_to_bin(Baggage *baggage, Bin *bin);
void destroy_bin(Bin *bin);

int main() {
    srand(time(NULL));

    Bin *bin = create_bin(1000);

    for (int i = 0; i < MAX_BAGGAGE; i++) {
        Baggage *baggage = (Baggage *) malloc(sizeof(Baggage));
        baggage->id = i + 1;
        baggage->weight = generate_random_weight();
        baggage->destination = generate_random_destination();

        if (!add_baggage_to_bin(baggage, bin)) {
            printf("Bin is full, cannot add more baggage\n");
            break;
        }
    }

    destroy_bin(bin);

    return 0;
}

int generate_random_weight() {
    return (rand() % 25) + 1;
}

int generate_random_destination() {
    return (rand() % 3) + 1;
}

Bin *create_bin(int capacity) {
    Bin *bin = (Bin *) malloc(sizeof(Bin));
    bin->capacity = capacity;
    bin->current_weight = 0;
    bin->baggage = (Baggage **) malloc(sizeof(Baggage *) * MAX_BAGGAGE);

    return bin;
}

int add_baggage_to_bin(Baggage *baggage, Bin *bin) {
    if (bin->current_weight + baggage->weight > bin->capacity) {
        return 0;
    }

    bin->baggage[bin->current_weight] = baggage;
    bin->current_weight += baggage->weight;

    return 1;
}

void destroy_bin(Bin *bin) {
    for (int i = 0; i < MAX_BAGGAGE; i++) {
        if (bin->baggage[i] != NULL) {
            free(bin->baggage[i]);
        }
    }

    free(bin->baggage);
    free(bin);
}