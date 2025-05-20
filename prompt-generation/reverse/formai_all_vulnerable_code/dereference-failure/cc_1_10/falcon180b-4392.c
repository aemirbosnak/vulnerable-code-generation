//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGGAGES 1000
#define NUM_CAROUSELS 10
#define BAGGAGE_DELAY 3
#define BAGGAGE_LOST_CHANCE 0.02

typedef struct {
    int id;
    int destination;
    int arrived;
    int lost;
} Baggage;

void generateBaggage(Baggage *baggage) {
    baggage->id = rand() % NUM_BAGGAGES;
    baggage->destination = rand() % NUM_CAROUSELS;
    baggage->arrived = 0;
    baggage->lost = 0;
}

int main() {
    srand(time(NULL));

    Baggage *baggage = (Baggage *)malloc(NUM_BAGGAGES * sizeof(Baggage));

    printf("Airport Baggage Handling Simulation\n");
    printf("Number of Baggage: %d\n", NUM_BAGGAGES);
    printf("Number of Carousels: %d\n", NUM_CAROUSELS);

    for (int i = 0; i < NUM_BAGGAGES; i++) {
        generateBaggage(&baggage[i]);
    }

    int currentBaggage = 0;
    while (currentBaggage < NUM_BAGGAGES) {
        int arrivedBaggage = 0;

        for (int i = 0; i < NUM_CAROUSELS; i++) {
            if (baggage[currentBaggage].destination == i) {
                baggage[currentBaggage].arrived = 1;
                arrivedBaggage++;
            }
        }

        if (arrivedBaggage == 0) {
            if (rand() % 100 < BAGGAGE_LOST_CHANCE) {
                baggage[currentBaggage].lost = 1;
            } else {
                int newDestination = rand() % NUM_CAROUSELS;
                while (newDestination == baggage[currentBaggage].destination) {
                    newDestination = rand() % NUM_CAROUSELS;
                }
                baggage[currentBaggage].destination = newDestination;
            }
        } else {
            currentBaggage++;
        }
    }

    printf("Simulation Completed!\n");
    printf("Number of Lost Baggage: %d\n", countLostBaggage(baggage, NUM_BAGGAGES));

    free(baggage);

    return 0;
}

int countLostBaggage(Baggage *baggage, int numBaggage) {
    int count = 0;
    for (int i = 0; i < numBaggage; i++) {
        if (baggage[i].lost) {
            count++;
        }
    }
    return count;
}