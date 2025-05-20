//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    int quantity;
    float price;
};

struct node {
    struct medicine* med;
    struct node* next;
};

struct node* head = NULL;

void addMedicine(char* name, int quantity, float price) {
    struct medicine* med = (struct medicine*)malloc(sizeof(struct medicine));

    strcpy(med->name, name);
    med->quantity = quantity;
    med->price = price;

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->med = med;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("\nMedicine added successfully!\n");
}

void updateMedicine(char* name, int quantity) {
    struct node* temp = head;

    while (temp != NULL) {
        if (strcmp(temp->med->name, name) == 0) {
            temp->med->quantity += quantity;
            printf("\nMedicine updated successfully!\n");
            return;
        }
        temp = temp->next;
    }

    printf("\nMedicine not found!\n");
}

void sellMedicine(char* name, int quantity) {
    struct node* temp = head;

    while (temp != NULL) {
        if (strcmp(temp->med->name, name) == 0) {
            if (temp->med->quantity < quantity) {
                printf("\nNot enough stock available!\n");
                return;
            }
            temp->med->quantity -= quantity;
            printf("\nMedicine sold successfully!\n");
            return;
        }
        temp = temp->next;
    }

    printf("\nMedicine not found!\n");
}

void displayMedicines() {
    printf("\nList of Medicines:\n");

    struct node* temp = head;

    while (temp != NULL) {
        printf("Name: %s\nQuantity: %d\nPrice: %f\n\n", temp->med->name, temp->med->quantity, temp->med->price);
        temp = temp->next;
    }
}

int main() {
    int choice, quantity;
    float price;
    char name[50];

    while (1) {
        printf("\n1. Add medicine\n2. Update medicine\n3. Sell medicine\n4. Display medicines\n5. Exit\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nEnter medicine name: ");
            scanf(" %[^\n]", name);
            printf("Enter medicine quantity: ");
            scanf("%d", &quantity);
            printf("Enter medicine price: ");
            scanf("%f", &price);
            addMedicine(name, quantity, price);
            break;
        case 2:
            printf("\nEnter medicine name: ");
            scanf(" %[^\n]", name);
            printf("Enter medicine quantity to add: ");
            scanf("%d", &quantity);
            updateMedicine(name, quantity);
            break;
        case 3:
            printf("\nEnter medicine name: ");
            scanf(" %[^\n]", name);
            printf("Enter medicine quantity to sell: ");
            scanf("%d", &quantity);
            sellMedicine(name, quantity);
            break;
        case 4:
            displayMedicines();
            break;
        case 5:
            printf("\nThank you for using this program!\n");
            exit(0);
        default:
            printf("\nInvalid choice!\n");
            break;
        }
    }

    return 0;
}