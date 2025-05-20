//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Medicine {
    char name[50];
    int stock;
    float price;
} Medicine;

typedef struct Node {
    Medicine med;
    struct Node *next;
} Node;

Node *head = NULL;

void addMedicine(char *name, int stock, float price) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->med.name, name);
    newNode->med.stock = stock;
    newNode->med.price = price;
    newNode->next = head;
    head = newNode;
}

void displayInventory() {
    Node *temp = head;
    printf("\nSTOCK INVENTORY\n-----------------\n");
    while (temp != NULL) {
        printf("%s\tStock: %d\tPrice: %.2f\n", temp->med.name, temp->med.stock, temp->med.price);
        temp = temp->next;
    }
}

void surpriseSpecialOffer() {
    int index = rand() % (head->next ? head->next->med.stock : 0);
    Node *temp = head;
    while (temp->next != NULL && temp->next->med.stock > index)
        temp = temp->next;
    printf("\nSurprise! Special offer on %s. Stock %d, Price %.2f.\n", temp->next->med.name, temp->next->med.stock, temp->next->med.price);
    temp->next->med.price *= 0.8; // 20% discount
}

int main() {
    addMedicine("Paracetamol", 100, 5.99);
    addMedicine("Ibuprofen", 50, 8.99);
    addMedicine("Aspirin", 75, 3.99);

    displayInventory();

    printf("\nYou're in luck today!\n");
    surpriseSpecialOffer();

    displayInventory();

    return 0;
}