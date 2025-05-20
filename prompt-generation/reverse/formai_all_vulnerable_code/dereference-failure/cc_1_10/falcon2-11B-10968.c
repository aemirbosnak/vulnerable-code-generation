//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int weight;
} Baggage;

void printBaggage(Baggage baggage) {
    printf("Name: %s, Weight: %d\n", baggage.name, baggage.weight);
}

void printAllBaggage(Baggage* baggage, int size) {
    for (int i = 0; i < size; i++) {
        printBaggage(baggage[i]);
    }
}

int main() {
    Baggage* baggage = malloc(sizeof(Baggage));
    strcpy(baggage[0].name, "Romeo");
    baggage[0].weight = 10;

    printAllBaggage(baggage, 1);
    printf("\n-----------------------\n");

    Baggage* julietBaggage = malloc(sizeof(Baggage));
    strcpy(julietBaggage[0].name, "Juliet");
    julietBaggage[0].weight = 15;

    printAllBaggage(julietBaggage, 1);
    printf("\n-----------------------\n");

    Baggage* romeoBaggage = malloc(sizeof(Baggage));
    strcpy(romeoBaggage[0].name, "Romeo");
    romeoBaggage[0].weight = 10;

    printAllBaggage(romeoBaggage, 1);
    printf("\n-----------------------\n");

    Baggage* julietRomeoBaggage = malloc(sizeof(Baggage));
    strcpy(julietRomeoBaggage[0].name, "Juliet");
    julietRomeoBaggage[0].weight = 15;

    printAllBaggage(julietRomeoBaggage, 1);
    printf("\n-----------------------\n");

    free(baggage);
    free(julietBaggage);
    free(romeoBaggage);
    free(julietRomeoBaggage);

    return 0;
}