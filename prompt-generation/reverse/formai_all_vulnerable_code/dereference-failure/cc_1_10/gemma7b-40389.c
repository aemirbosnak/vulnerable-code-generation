//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 10

typedef struct baggage {
    char* name;
    int weight;
    struct baggage* next;
} baggage;

baggage* createBaggage(char* name, int weight) {
    baggage* newBaggage = malloc(sizeof(baggage));
    newBaggage->name = name;
    newBaggage->weight = weight;
    newBaggage->next = NULL;
    return newBaggage;
}

void printBaggage(baggage* baggage) {
    while (baggage) {
        printf("%s (%.2f kg)\n", baggage->name, baggage->weight);
        baggage = baggage->next;
    }
}

void simulateBaggageHandling() {
    baggage* baggageList = NULL;

    // Randomly generate 5 bags
    for (int i = 0; i < 5; i++) {
        char* name = "Baggage " + i;
        int weight = rand() % 20 + 10;
        baggage* newBaggage = createBaggage(name, weight);
        if (baggageList == NULL) {
            baggageList = newBaggage;
        } else {
            newBaggage->next = baggageList;
            baggageList = newBaggage;
        }
    }

    // Print the bags
    printBaggage(baggageList);

    // Simulate baggage weighing
    for (baggage* currentBaggage = baggageList; currentBaggage; currentBaggage = currentBaggage->next) {
        printf("%s weighs %.2f kg\n", currentBaggage->name, currentBaggage->weight);
    }

    // Randomly select 2 bags and swap their weights
    int bag1Index = rand() % 5;
    int bag2Index = rand() % 5;
    baggage* bag1 = baggageList;
    baggage* bag2 = baggageList;

    for (int i = 0; i < bag1Index; i++) {
        bag1 = bag1->next;
    }
    for (int i = 0; i < bag2Index; i++) {
        bag2 = bag2->next;
    }

    int tempWeight = bag1->weight;
    bag1->weight = bag2->weight;
    bag2->weight = tempWeight;

    // Print the bags after swapping weights
    printBaggage(baggageList);

    // Free the baggage list
    free(baggageList);
}

int main() {
    simulateBaggageHandling();
    return 0;
}