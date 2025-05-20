//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
} Item;

typedef struct Node {
    Item data;
    struct Node* next;
} Node;

typedef Node* List;

void createList(List* list) {
    *list = NULL;
}

void addItem(List* list, Item newItem) {
    List current = *list;
    List newNode;

    newNode = (List) malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory error.\n");
        return;
    }

    newNode->data = newItem;
    newNode->next = NULL;

    if (*list == NULL) {
        *list = newNode;
        return;
    }

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

void printList(List list) {
    List current = list;

    while (current != NULL) {
        printf("%s: %d\n", current->data.name, current->data.quantity);
        current = current->next;
    }
}

int main() {
    List inventory;
    createList(&inventory);

    Item potionOfHealing = {"Potion of Healing", 10};
    Item shieldOfThunder = {"Shield of Thunder", 5};
    Item swordOfFire = {"Sword of Fire", 3};

    addItem(&inventory, potionOfHealing);
    addItem(&inventory, shieldOfThunder);
    addItem(&inventory, swordOfFire);

    printf("Welcome, noble knight, to the magical inventory!\n");
    printList(inventory);

    return 0;
}