//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char type[10];
    char property[10];
    int quantity;
} Item;

typedef struct Node {
    Item data;
    struct Node* next;
} Node;

Node* head = NULL;

void addItem(Item newItem) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = newItem;
    newNode->next = head;
    head = newNode;
}

void displayInventory() {
    Node* currentNode = head;
    printf("\n------------------------------------\n");
    printf("|   Name             | Type      | Property | Quantity |\n");
    printf("------------------------------------|\n");
    while (currentNode != NULL) {
        printf("| %-15s | %-8s | %-10s | %d |\n", currentNode->data.name, currentNode->data.type, currentNode->data.property, currentNode->data.quantity);
        currentNode = currentNode->next;
    }
    printf("------------------------------------|\n");
}

void useItem(char* name) {
    Node* currentNode = head;
    while (currentNode != NULL) {
        if (strcmp(currentNode->data.name, name) == 0) {
            if (currentNode->data.quantity > 0) {
                currentNode->data.quantity--;
                printf("\nYou used the %s.\n", name);
            } else {
                printf("\nThe %s is not available.\n", name);
            }
            return;
        }
        currentNode = currentNode->next;
    }
    printf("\nThe %s was not found in the inventory.\n", name);
}

int main() {
    Item newItem1 = {"Fire Sword", "Weapon", "Fire", 3};
    Item newItem2 = {"Ice Shield", "Armor", "Ice", 5};
    Item newItem3 = {"Phoenix Tonic", "Potion", "Fire", 2};

    addItem(newItem1);
    addItem(newItem2);
    addItem(newItem3);

    displayInventory();

    char name[20];
    printf("\nEnter the name of the item you want to use: ");
    scanf("%s", name);
    useItem(name);

    displayInventory();

    return 0;
}