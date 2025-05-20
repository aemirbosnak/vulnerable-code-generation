//MISTRAL-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char *name;
    int weight;
} Bag;

typedef struct Node {
    Bag data;
    struct Node *next;
} Node;

Node *head = NULL;

void addBag(int id, char *name, int weight) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data.id = id;
    newNode->data.name = strdup(name);
    newNode->data.weight = weight;
    newNode->next = head;
    head = newNode;
}

void displayBags() {
    Node *temp = head;
    printf("Bags in the system:\n");
    while (temp != NULL) {
        printf("ID: %d, Name: %s, Weight: %d\n", temp->data.id, temp->data.name, temp->data.weight);
        temp = temp->next;
    }
}

void sortBags() {
    Node *current, *index, *min;
    int tempId;
    char *tempName;

    for (current = head; current != NULL; current = current->next) {
        min = current;
        for (index = current; index != NULL; index = index->next) {
            if (index->data.weight < min->data.weight) {
                min = index;
            }
        }

        if (min != current) {
            tempId = current->data.id;
            tempName = current->data.name;
            current->data = min->data;
            min->data = (Bag){ .id = tempId, .name = tempName, .weight = current->data.weight };
        }
    }
}

void unloadBaggageCarousel(int carouselNumber) {
    Node *current = head;
    int numBagsUnloaded = 0;

    while (current != NULL && numBagsUnloaded < carouselNumber) {
        if (current->data.weight <= 50) { // Only bags under 50lbs can be unloaded
            printf("Unloading Bag ID: %d, Name: %s, Weight: %d\n", current->data.id, current->data.name, current->data.weight);
            Node *temp = current;
            current = current->next;
            free(temp->data.name);
            free(temp);
            numBagsUnloaded++;
        } else {
            current = current->next;
        }
    }
}

int main() {
    addBag(1, "John Doe", 30);
    addBag(2, "Jane Doe", 45);
    addBag(3, "Bob Smith", 25);
    addBag(4, "Susan Johnson", 55);

    displayBags();
    printf("\nSorting Bags...\n");
    sortBags();
    displayBags();
    printf("\nUnloading 3 bags from Carousel 1:\n");
    unloadBaggageCarousel(3);
    displayBags();

    return 0;
}