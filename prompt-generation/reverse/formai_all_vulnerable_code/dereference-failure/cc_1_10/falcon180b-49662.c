//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    char *destination;
    int weight;
} Baggage;

Baggage *create_baggage(int id, char *destination, int weight) {
    Baggage *baggage = (Baggage *) malloc(sizeof(Baggage));
    baggage->id = id;
    baggage->destination = destination;
    baggage->weight = weight;
    return baggage;
}

void print_baggage(Baggage *baggage) {
    printf("ID: %d, Destination: %s, Weight: %d\n", baggage->id, baggage->destination, baggage->weight);
}

int main() {
    srand(time(NULL));

    int num_baggage = rand() % 100 + 1;
    Baggage **baggage_list = (Baggage **) malloc(sizeof(Baggage *) * num_baggage);

    for (int i = 0; i < num_baggage; i++) {
        int id = rand() % 1000 + 1;
        char *destination = (char *) malloc(sizeof(char) * 20);
        sprintf(destination, "Destination %d", rand() % 10 + 1);
        int weight = rand() % 50 + 1;

        Baggage *baggage = create_baggage(id, destination, weight);
        baggage_list[i] = baggage;

        printf("Baggage %d created: ID: %d, Destination: %s, Weight: %d\n", i + 1, id, destination, weight);
    }

    printf("\nBaggage list:\n");
    for (int i = 0; i < num_baggage; i++) {
        print_baggage(baggage_list[i]);
    }

    for (int i = 0; i < num_baggage; i++) {
        free(baggage_list[i]->destination);
        free(baggage_list[i]);
    }
    free(baggage_list);

    return 0;
}