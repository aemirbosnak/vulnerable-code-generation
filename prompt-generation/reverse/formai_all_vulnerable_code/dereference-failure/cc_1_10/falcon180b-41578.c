//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BAGGAGE_SIZE 10
#define BAGGAGE_TYPES 5
#define BAGGAGE_WEIGHT_LIMIT 50

// Baggage structure
typedef struct {
    int id;
    int type;
    int weight;
} Baggage;

// Function prototypes
void generateBaggage(Baggage *baggage, int num);
void printBaggage(Baggage *baggage, int num);
int checkWeight(Baggage *baggage, int num);

int main() {
    srand(time(NULL)); // Seed the random number generator

    int numBaggage = rand() % 20 + 10; // Generate a random number of baggage between 10 and 20
    Baggage *baggage = malloc(numBaggage * sizeof(Baggage)); // Allocate memory for the baggage

    // Generate random baggage
    generateBaggage(baggage, numBaggage);

    // Print the baggage
    printf("Generated baggage:\n");
    printBaggage(baggage, numBaggage);

    // Check weight limit
    int weightLimit = BAGGAGE_WEIGHT_LIMIT * numBaggage;
    int totalWeight = 0;
    for (int i = 0; i < numBaggage; i++) {
        totalWeight += baggage[i].weight;
    }
    if (totalWeight > weightLimit) {
        printf("Baggage exceeds weight limit!\n");
    } else {
        printf("Baggage is within weight limit.\n");
    }

    free(baggage); // Free the memory allocated for the baggage
    return 0;
}

void generateBaggage(Baggage *baggage, int num) {
    for (int i = 0; i < num; i++) {
        // Generate random baggage ID, type, and weight
        baggage[i].id = rand() % 1000;
        baggage[i].type = rand() % BAGGAGE_TYPES;
        baggage[i].weight = rand() % BAGGAGE_WEIGHT_LIMIT + 1;
    }
}

void printBaggage(Baggage *baggage, int num) {
    for (int i = 0; i < num; i++) {
        printf("Baggage %d: Type %d, Weight %d\n", baggage[i].id, baggage[i].type, baggage[i].weight);
    }
}

int checkWeight(Baggage *baggage, int num) {
    int totalWeight = 0;
    for (int i = 0; i < num; i++) {
        totalWeight += baggage[i].weight;
    }
    return totalWeight;
}