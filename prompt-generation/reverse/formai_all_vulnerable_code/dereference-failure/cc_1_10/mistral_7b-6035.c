//MISTRAL-7B DATASET v1.0 Category: System administration ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
} Supply;

typedef struct Node {
    Supply data;
    struct Node *next;
} Node;

Node *head = NULL;

void addSupply(char *supplyName, int quantity) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    strcpy(newNode->data.name, supplyName);
    newNode->data.quantity = quantity;
    newNode->next = head;
    head = newNode;
}

void displaySupplies() {
    Node *current = head;
    while (current != NULL) {
        printf("%s: %d\n", current->data.name, current->data.quantity);
        current = current->next;
    }
}

void checkSupplies(char *supplyName, int requiredQuantity) {
    Node *current = head;
    while (current != NULL) {
        if (strcmp(current->data.name, supplyName) == 0) {
            if (current->data.quantity >= requiredQuantity) {
                printf("%s: Sufficient supply.\n", supplyName);
                return;
            } else {
                printf("%s: Insufficient supply. Send for reinforcements.\n", supplyName);
                return;
            }
        }
        current = current->next;
    }

    printf("%s: Supply not found in castle's records.\n", supplyName);
}

int main() {
    addSupply("Grain", 100);
    addSupply("Water", 50);
    addSupply("Wood", 200);

    displaySupplies();

    checkSupplies("Water", 25);
    checkSupplies("Steel", 50);

    return 0;
}