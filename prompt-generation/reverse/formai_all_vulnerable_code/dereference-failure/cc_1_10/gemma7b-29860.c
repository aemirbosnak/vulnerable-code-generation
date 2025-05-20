//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    char name[50];
    int quantity;
    float price;
} Item;

struct Node {
    Item item;
    struct Node* next;
};

void insertNode(struct Node** head, Item item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->item = item;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void searchItem(struct Node* head, char* name) {
    while (head) {
        if (strcmp(head->item.name, name) == 0) {
            printf("Item name: %s\n", head->item.name);
            printf("Quantity: %d\n", head->item.quantity);
            printf("Price: %.2f\n", head->item.price);
            return;
        }
        head = head->next;
    }

    printf("Item not found.\n");
}

int main() {
    struct Node* head = NULL;

    Item item1 = {"Apple", 10, 1.20};
    insertNode(&head, item1);

    Item item2 = {"Banana", 5, 1.50};
    insertNode(&head, item2);

    Item item3 = {"Orange", 7, 1.80};
    insertNode(&head, item3);

    searchItem(head, "Banana");

    return 0;
}