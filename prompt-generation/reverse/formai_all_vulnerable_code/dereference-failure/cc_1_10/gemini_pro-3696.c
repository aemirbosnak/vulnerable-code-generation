//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    int quantity;
    float price;
};

struct node {
    struct medicine med;
    struct node *next;
};

struct node *head = NULL;

void addMedicine(char *name, int quantity, float price) {
    struct node *newMed = (struct node *)malloc(sizeof(struct node));
    strcpy(newMed->med.name, name);
    newMed->med.quantity = quantity;
    newMed->med.price = price;
    newMed->next = head;
    head = newMed;
}

void deleteMedicine(char *name) {
    struct node *temp = head, *prev;
    if (temp != NULL && strcmp(temp->med.name, name) == 0) {
        head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && strcmp(temp->med.name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

void updateMedicine(char *name, int quantity, float price) {
    struct node *temp = head;
    while (temp != NULL && strcmp(temp->med.name, name) != 0) {
        temp = temp->next;
    }
    if (temp == NULL) return;
    temp->med.quantity = quantity;
    temp->med.price = price;
}

void displayMedicine() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("Name: %s, Quantity: %d, Price: %.2f\n", temp->med.name, temp->med.quantity, temp->med.price);
        temp = temp->next;
    }
}

int main() {
    addMedicine("Paracetamol", 100, 10.0);
    addMedicine("Ibuprofen", 50, 15.0);
    addMedicine("Aspirin", 25, 5.0);
    displayMedicine();
    deleteMedicine("Ibuprofen");
    updateMedicine("Paracetamol", 150, 12.0);
    displayMedicine();
    return 0;
}