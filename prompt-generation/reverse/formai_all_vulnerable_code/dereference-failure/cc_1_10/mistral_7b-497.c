//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Medicine {
    char name[50];
    float price;
    int quantity;
} Medicine;

typedef struct Node {
    Medicine med;
    struct Node *next;
} Node;

Node *head = NULL;
Node *current = NULL;
Node *newNode = NULL;

void addMedicine(char name[], float price, int quantity) {
    newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->med.name, name);
    newNode->med.price = price;
    newNode->med.quantity = quantity;
    newNode->next = head;
    head = newNode;
}

void displayMedicines() {
    current = head;
    printf("\n========= Current Stock =========\n");
    while (current != NULL) {
        printf("\nName: %s", current->med.name);
        printf("\nPrice: %.2f", current->med.price);
        printf("\nQuantity: %d", current->med.quantity);
        current = current->next;
    }
}

void searchMedicine(char name[]) {
    current = head;
    bool found = false;
    while (current != NULL && !found) {
        if (strcmp(current->med.name, name) == 0) {
            printf("\nName: %s", current->med.name);
            printf("\nPrice: %.2f", current->med.price);
            printf("\nQuantity: %d", current->med.quantity);
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        printf("\nMedicine not found.");
    }
}

int main() {
    addMedicine("Paracetamol", 10.5, 20);
    addMedicine("Ibuprofen", 12.3, 15);
    addMedicine("Aspirin", 8.6, 18);
    addMedicine("Acetaminophen", 9.7, 25);

    displayMedicines();

    searchMedicine("Ibuprofen");

    return 0;
}