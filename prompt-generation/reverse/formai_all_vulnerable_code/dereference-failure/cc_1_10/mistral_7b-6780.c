//MISTRAL-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int weight;
    struct Baggage* next;
} Baggage;

void enqueue(Baggage** front, Baggage* baggage) {
    if (*front == NULL) {
        *front = baggage;
    } else {
        Baggage* current = *front;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = baggage;
    }
}

Baggage* dequeue(Baggage** front) {
    if (*front == NULL) {
        return NULL;
    }
    Baggage* temp = *front;
    *front = (*front)->next;
    return temp;
}

Baggage* createBaggage(const char* name, int weight) {
    Baggage* newBaggage = (Baggage*) malloc(sizeof(Baggage));
    strcpy(newBaggage->name, name);
    newBaggage->weight = weight;
    newBaggage->next = NULL;
    return newBaggage;
}

int main() {
    Baggage* arrivalsQueue = NULL;
    Baggage* departuresQueue = NULL;

    // Add baggage to arrivals queue
    enqueue(&arrivalsQueue, createBaggage("John Doe", 15));
    enqueue(&arrivalsQueue, createBaggage("Jane Smith", 20));
    enqueue(&arrivalsQueue, createBaggage("Bob Johnson", 10));

    // Process baggage in arrivals queue and add to departures queue
    while (arrivalsQueue != NULL) {
        Baggage* current = dequeue(&arrivalsQueue);
        int checkWeight = 15; // Assume a maximum weight limit of 15 kg

        if (current->weight <= checkWeight) {
            enqueue(&departuresQueue, current);
            printf("%s's baggage weighs %d kg and has been added to the departures queue.\n", current->name, current->weight);
        } else {
            printf("%s's baggage weighs %d kg and has been rejected.\n", current->name, current->weight);
            free(current);
        }
    }

    // Print departures queue
    printf("\nThe following baggage has been cleared for departure:\n");
    while (departuresQueue != NULL) {
        Baggage* current = dequeue(&departuresQueue);
        printf("%s\n", current->name);
        free(current);
    }

    return 0;
}