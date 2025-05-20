//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct warehouse {
    char *name;
    int capacity;
    int inventory;
    struct warehouse *next;
};

struct warehouse *head = NULL;

void add_warehouse(char *name, int capacity) {
    struct warehouse *new_warehouse = malloc(sizeof(struct warehouse));
    new_warehouse->name = strdup(name);
    new_warehouse->capacity = capacity;
    new_warehouse->inventory = 0;
    new_warehouse->next = head;
    head = new_warehouse;
}

void print_warehouses() {
    struct warehouse *current_warehouse = head;
    while (current_warehouse != NULL) {
        printf("%s: %d/%d\n", current_warehouse->name, current_warehouse->inventory, current_warehouse->capacity);
        current_warehouse = current_warehouse->next;
    }
}

void add_inventory(char *name, int quantity) {
    struct warehouse *current_warehouse = head;
    while (current_warehouse != NULL) {
        if (strcmp(current_warehouse->name, name) == 0) {
            if (current_warehouse->inventory + quantity <= current_warehouse->capacity) {
                current_warehouse->inventory += quantity;
            } else {
                printf("Error: Warehouse '%s' has insufficient capacity.\n", name);
            }
            return;
        }
        current_warehouse = current_warehouse->next;
    }
    printf("Error: Warehouse '%s' not found.\n", name);
}

void remove_inventory(char *name, int quantity) {
    struct warehouse *current_warehouse = head;
    while (current_warehouse != NULL) {
        if (strcmp(current_warehouse->name, name) == 0) {
            if (current_warehouse->inventory - quantity >= 0) {
                current_warehouse->inventory -= quantity;
            } else {
                printf("Error: Warehouse '%s' has insufficient inventory.\n", name);
            }
            return;
        }
        current_warehouse = current_warehouse->next;
    }
    printf("Error: Warehouse '%s' not found.\n", name);
}

int main() {
    add_warehouse("Warehouse A", 100);
    add_warehouse("Warehouse B", 200);
    add_warehouse("Warehouse C", 300);

    print_warehouses();

    add_inventory("Warehouse A", 50);
    add_inventory("Warehouse B", 75);
    add_inventory("Warehouse C", 100);

    print_warehouses();

    remove_inventory("Warehouse A", 25);
    remove_inventory("Warehouse B", 50);
    remove_inventory("Warehouse C", 75);

    print_warehouses();

    return 0;
}