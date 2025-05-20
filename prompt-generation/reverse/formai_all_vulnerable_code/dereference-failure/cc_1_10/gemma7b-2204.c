//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_BAGS 10

typedef struct Bag {
    char name[20];
    int weight;
    struct Bag *next;
} Bag;

void addBag(Bag **head) {
    Bag *newBag = (Bag *)malloc(sizeof(Bag));
    printf("Enter bag name: ");
    scanf("%s", newBag->name);
    printf("Enter bag weight: ");
    scanf("%d", &newBag->weight);
    newBag->next = *head;
    *head = newBag;
}

void handleBags(Bag *head) {
    printf("Bags:");
    for (Bag *bag = head; bag; bag = bag->next) {
        printf("\n- %s (%d)", bag->name, bag->weight);
    }
    printf("\n");
}

int main() {
    Bag *head = NULL;
    int choice;

    printf("Welcome to the Grand Hall of the Mighty Dragon!");
    printf("\n");

    while (1) {
        printf("Please select an option:");
        printf("\n1. Add a Bag\n2. Handle Bags\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBag(&head);
                break;
            case 2:
                handleBags(head);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid selection.\n");
                break;
        }
    }

    return 0;
}