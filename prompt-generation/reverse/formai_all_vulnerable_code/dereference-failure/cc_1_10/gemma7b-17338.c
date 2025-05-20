//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: innovative
#include <stdlib.h>
#include <time.h>

typedef struct Baggage {
    char* name;
    int weight;
    struct Baggage* next;
} Baggage;

void insertBaggage(Baggage** head, char* name, int weight) {
    Baggage* newBaggage = (Baggage*)malloc(sizeof(Baggage));
    newBaggage->name = name;
    newBaggage->weight = weight;
    newBaggage->next = NULL;

    if (*head == NULL) {
        *head = newBaggage;
    } else {
        (*head)->next = newBaggage;
    }
}

void simulateBaggageHandling(Baggage* head) {
    time_t start = time(NULL);

    while (head) {
        printf("Processing baggage: %s (%d kg)\n", head->name, head->weight);

        sleep(rand() % 3);

        printf("Baggage processed: %s (%d kg)\n", head->name, head->weight);

        head = head->next;
    }

    time_t end = time(NULL);

    printf("Total time: %ld seconds\n", end - start);
}

int main() {
    Baggage* head = NULL;

    insertBaggage(&head, "John Doe's suitcase", 25);
    insertBaggage(&head, "Jane Doe's backpack", 15);
    insertBaggage(&head, "Peter Pan's trunk", 40);

    simulateBaggageHandling(head);

    return 0;
}