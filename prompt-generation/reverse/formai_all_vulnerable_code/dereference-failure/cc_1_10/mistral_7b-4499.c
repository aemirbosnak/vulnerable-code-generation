//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int stock;
    float price;
} Medicine;

typedef struct Node {
    Medicine med;
    struct Node* next;
} Node;

Node* head = NULL;

void addMedicine(Medicine med) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->med = med;
    newNode->next = head;
    head = newNode;
}

void displayMedicines() {
    Node* temp = head;
    if (head == NULL) {
        printf("No medicines in stock.\n");
        return;
    }
    printf("\nCurrent Stock:\n");
    while (temp != NULL) {
        printf("%s\t%d\t%.2f\n", temp->med.name, temp->med.stock, temp->med.price);
        temp = temp->next;
    }
}

void addStock(char* name, int quantity) {
    Node* temp = head;
    Medicine med;
    while (temp != NULL) {
        if (strcmp(temp->med.name, name) == 0) {
            temp->med.stock += quantity;
            printf("%s stock updated successfully.\n", name);
            return;
        }
        temp = temp->next;
    }
    med.stock = quantity;
    strcpy(med.name, name);
    addMedicine(med);
    printf("%s added to stock.\n", name);
}

void sellMedicine(char* name, int quantity) {
    Node* temp = head;
    Medicine soldMedicine;
    int totalCost = 0;
    while (temp != NULL) {
        if (strcmp(temp->med.name, name) == 0) {
            if (temp->med.stock >= quantity) {
                soldMedicine = temp->med;
                temp->med.stock -= quantity;
                totalCost += soldMedicine.price * quantity;
                printf("%s sold successfully.\n", name);
            } else {
                printf("Insufficient stock for %s.\n", name);
                return;
            }
            break;
        }
        temp = temp->next;
    }
    printf("Total cost: %.2f\n", (float) totalCost);
}

int main() {
    Medicine medicine1 = {"Paracetamol", 10, 10.5};
    Medicine medicine2 = {"Ibuprofen", 5, 12.5};

    addMedicine(medicine1);
    addMedicine(medicine2);

    displayMedicines();

    addStock("Paracetamol", 15);
    addStock("Ibuprofen", 20);

    displayMedicines();

    sellMedicine("Paracetamol", 3);
    sellMedicine("Ibuprofen", 7);

    displayMedicines();

    return 0;
}