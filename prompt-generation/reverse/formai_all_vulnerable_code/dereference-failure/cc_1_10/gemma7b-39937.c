//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int item_id;
    char item_name[20];
    int quantity;
    struct Node* next;
};

struct Warehouse {
    struct Node* head;
    struct Node* tail;
    int total_items;
    char warehouse_name[50];
};

void insert_item(struct Warehouse* w, int item_id, char item_name[], int quantity) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->item_id = item_id;
    strcpy(newNode->item_name, item_name);
    newNode->quantity = quantity;
    newNode->next = NULL;

    if (w->head == NULL) {
        w->head = newNode;
        w->tail = newNode;
    } else {
        w->tail->next = newNode;
        w->tail = newNode;
    }

    w->total_items++;
}

void search_item(struct Warehouse* w, int item_id) {
    struct Node* current = w->head;

    while (current) {
        if (current->item_id == item_id) {
            printf("Item name: %s\n", current->item_name);
            printf("Quantity: %d\n", current->quantity);
            break;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("Item not found.\n");
    }
}

int main() {
    struct Warehouse* w = (struct Warehouse*)malloc(sizeof(struct Warehouse));
    w->head = NULL;
    w->tail = NULL;
    w->total_items = 0;
    strcpy(w->warehouse_name, "Main Warehouse");

    insert_item(w, 1, "ABC", 10);
    insert_item(w, 2, "XYZ", 20);
    insert_item(w, 3, "BCD", 15);

    search_item(w, 2);

    return 0;
}