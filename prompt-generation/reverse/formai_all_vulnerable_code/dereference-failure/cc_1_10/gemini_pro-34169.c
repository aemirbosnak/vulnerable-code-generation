//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Medicine {
    char name[50];
    float price;
    int quantity;
} Medicine;

typedef struct Node {
    Medicine data;
    struct Node *next;
} Node;

Node *head = NULL;

void addMedicine(Medicine medicine) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = medicine;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void deleteMedicine(char *name) {
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL) {
        if (strcmp(temp->data.name, name) == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Medicine not found!\n");
}

void updateMedicine(char *name, Medicine medicine) {
    Node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->data.name, name) == 0) {
            temp->data = medicine;
            return;
        }
        temp = temp->next;
    }
    printf("Medicine not found!\n");
}

void searchMedicine(char *name) {
    Node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->data.name, name) == 0) {
            printf("Medicine found!\n");
            printf("Name: %s\n", temp->data.name);
            printf("Price: %.2f\n", temp->data.price);
            printf("Quantity: %d\n", temp->data.quantity);
            return;
        }
        temp = temp->next;
    }
    printf("Medicine not found!\n");
}

void displayAllMedicines() {
    Node *temp = head;
    while (temp != NULL) {
        printf("Name: %s\n", temp->data.name);
        printf("Price: %.2f\n", temp->data.price);
        printf("Quantity: %d\n\n", temp->data.quantity);
        temp = temp->next;
    }
}

int main() {
    // Add some medicines to the inventory.
    Medicine medicine1 = {"Paracetamol", 10.0, 100};
    addMedicine(medicine1);
    Medicine medicine2 = {"Ibuprofen", 15.0, 50};
    addMedicine(medicine2);
    Medicine medicine3 = {"Aspirin", 5.0, 200};
    addMedicine(medicine3);

    // Display all the medicines in the inventory.
    printf("All medicines in the inventory:\n");
    displayAllMedicines();

    // Search for a medicine by name.
    char name[] = "Paracetamol";
    searchMedicine(name);

    // Update the price of a medicine.
    Medicine medicine4 = {"Paracetamol", 12.0, 100};
    updateMedicine(name, medicine4);

    // Delete a medicine from the inventory.
    deleteMedicine(name);

    // Display all the medicines in the inventory again.
    printf("All medicines in the inventory after deletion:\n");
    displayAllMedicines();

    return 0;
}