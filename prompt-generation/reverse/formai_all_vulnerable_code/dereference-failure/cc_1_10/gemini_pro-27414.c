//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item {
    int id;
    char name[50];
    int quantity;
    double price;
} item;

typedef struct node {
    item item;
    struct node *next;
} node;

typedef struct warehouse {
    node *head;
} warehouse;

warehouse *create_warehouse() {
    warehouse *w = malloc(sizeof(warehouse));
    w->head = NULL;
    return w;
}

void add_item(warehouse *w, item item) {
    node *new_node = malloc(sizeof(node));
    new_node->item = item;
    new_node->next = NULL;

    if (w->head == NULL) {
        w->head = new_node;
        return;
    }

    node *current = w->head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}

void remove_item(warehouse *w, int id) {
    if (w->head == NULL) {
        return;
    }

    if (w->head->item.id == id) {
        w->head = w->head->next;
        return;
    }

    node *current = w->head;
    while (current->next != NULL) {
        if (current->next->item.id == id) {
            current->next = current->next->next;
            return;
        }

        current = current->next;
    }
}

item *find_item(warehouse *w, int id) {
    if (w->head == NULL) {
        return NULL;
    }

    node *current = w->head;
    while (current != NULL) {
        if (current->item.id == id) {
            return &current->item;
        }

        current = current->next;
    }

    return NULL;
}

void print_warehouse(warehouse *w) {
    node *current = w->head;
    while (current != NULL) {
        printf("ID: %d\n", current->item.id);
        printf("Name: %s\n", current->item.name);
        printf("Quantity: %d\n", current->item.quantity);
        printf("Price: %.2f\n", current->item.price);
        printf("\n");

        current = current->next;
    }
}

int main() {
    warehouse *w = create_warehouse();

    item item1 = {1, "Apple", 10, 1.0};
    item item2 = {2, "Banana", 20, 1.5};
    item item3 = {3, "Orange", 30, 2.0};

    add_item(w, item1);
    add_item(w, item2);
    add_item(w, item3);

    print_warehouse(w);

    remove_item(w, 2);

    item *item4 = find_item(w, 3);
    if (item4 != NULL) {
        printf("Found item:\n");
        printf("ID: %d\n", item4->id);
        printf("Name: %s\n", item4->name);
        printf("Quantity: %d\n", item4->quantity);
        printf("Price: %.2f\n", item4->price);
        printf("\n");
    } else {
        printf("Item not found.\n");
    }

    return 0;
}