//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_BAGGAGE 50
#define BELT_CAPACITY 5

typedef struct Baggage {
    int id;
    int flightNum;
} Baggage;

typedef struct Belt {
    Baggage* bags[BELT_CAPACITY];
    int numOfBags;
} Belt;

int main() {
    srand(time(0));
    
    Belt conveyerBelt = {0};
    Baggage* checkedBags[NUM_OF_BAGGAGE];
    
    // Generate checked bags
    for (int i = 0; i < NUM_OF_BAGGAGE; i++) {
        checkedBags[i] = (Baggage*) malloc(sizeof(Baggage));
        checkedBags[i]->id = i + 1;
        checkedBags[i]->flightNum = rand() % 10 + 1;
    }
    
    int bagsProcessed = 0;
    int bagsMissed = 0;
    
    // Begin simulation
    while (bagsProcessed < NUM_OF_BAGGAGE) {
        // Generate bags from check-in counter
        int numOfNewBags = rand() % 5;
        for (int i = 0; i < numOfNewBags; i++) {
            if (bagsProcessed == NUM_OF_BAGGAGE) {
                break;
            }
            if (conveyerBelt.numOfBags == BELT_CAPACITY) {
                bagsMissed++;
                printf("A bag was missed due to belt capacity reached.\n");
                continue;
            }
            conveyerBelt.bags[conveyerBelt.numOfBags] = checkedBags[bagsProcessed];
            conveyerBelt.numOfBags++;
            bagsProcessed++;
        }
        
        // Transport bags to corresponding flights
        for (int i = conveyerBelt.numOfBags - 1; i >= 0; i--) {
            Baggage* bag = conveyerBelt.bags[i];
            if (bag->flightNum == rand() % 10 + 1) {
                printf("Bag %d has been successfully loaded onto flight %d.\n", bag->id, bag->flightNum);
                conveyerBelt.bags[i] = NULL;
                conveyerBelt.numOfBags--;
                free(bag);
            }
        }
    }
    
    printf("Simulation Complete.\n\n");
    printf("Total Bags Processed: %d\n", bagsProcessed);
    printf("Total Bags Missed: %d\n", bagsMissed);
    
    return 0;
}