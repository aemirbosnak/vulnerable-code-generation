//MISTRAL-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    int id;
    char destination[50];
} Bag;

typedef struct Node {
    Bag data;
    struct Node* next;
} Node;

Node* createNode(int id, char* destination) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data.id = id;
    strcpy(newNode->data.destination, destination);
    newNode->next = NULL;
    return newNode;
}

void addToList(Node** head, int id, char* destination) {
    Node* newNode = createNode(id, destination);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(Node* head) {
    Node* current = head;
    printf("Baggage List:\n");
    while (current != NULL) {
        printf("ID: %d, Destination: %s\n", current->data.id, current->data.destination);
        current = current->next;
    }
}

int main() {
    srand(time(NULL));
    int numBags = 50;
    Node* baggageList = NULL;

    printf("Welcome to C Airport Baggage Handling Simulation!\n");

    for (int i = 0; i < numBags; i++) {
        int id = rand() % 100;
        char destination[50];
        printf("Processing Bag #%d...\n", i + 1);
        scanf("%s", destination);
        addToList(&baggageList, id, destination);
    }

    printf("\nBaggage Arrived!\n");
    printList(baggageList);

    // Baggage Claim
    int claimID;
    printf("\nEnter your baggage claim ID: ");
    scanf("%d", &claimID);

    Node* current = baggageList;
    while (current != NULL && current->data.id != claimID) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Sorry, your baggage was not found.\n");
    } else {
        printf("Congratulations! Your baggage (ID: %d, Destination: %s) has been claimed successfully.\n", current->data.id, current->data.destination);
    }

    return 0;
}