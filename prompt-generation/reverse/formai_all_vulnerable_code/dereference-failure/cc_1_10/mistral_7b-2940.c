//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[50];
    int stock;
    float price;
} Medicine;

typedef struct {
    int id;
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

void displayMedicines() {
    Node *temp = head;
    printf("\n---------------MEDICINE LIST-----------------\n");
    while (temp != NULL) {
        printf("\nMedicine Name : %s", temp->med.name);
        printf("\nStock : %d", temp->med.stock);
        printf("\nPrice : %.2f", temp->med.price);
        temp = temp->next;
    }
}

void searchMedicine(char *name) {
    Node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->med.name, name) == 0) {
            printf("\nMedicine Found : ");
            printf("\nMedicine Name : %s", temp->med.name);
            printf("\nStock : %d", temp->med.stock);
            printf("\nPrice : %.2f", temp->med.price);
            return;
        }
        temp = temp->next;
    }
    printf("\nMedicine not found...");
}

int main() {
    addMedicine("Paracetamol", 50, 10.50);
    addMedicine("Ibuprofen", 30, 15.00);
    addMedicine("Aspirin", 20, 8.50);

    displayMedicines();

    char searchName[20];
    printf("\nEnter medicine name to search : ");
    scanf("%s", searchName);
    searchMedicine(searchName);

    return 0;
}