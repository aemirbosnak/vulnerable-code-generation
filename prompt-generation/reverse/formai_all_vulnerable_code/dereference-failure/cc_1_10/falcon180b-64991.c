//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 1000
#define MAX_WAREHOUSES 10

typedef struct {
    int id;
    char name[50];
    int quantity;
} Item;

typedef struct {
    int id;
    char name[50];
    Item items[MAX_ITEMS];
} Warehouse;

void addItem(Warehouse* w, Item* i) {
    int index = 0;
    while (index < w->items[index].id) {
        index++;
    }
    w->items[index] = *i;
}

void printWarehouse(Warehouse* w) {
    printf("Warehouse ID: %d\n", w->id);
    printf("Warehouse Name: %s\n", w->name);
    printf("Items:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (w->items[i].id!= 0) {
            printf("ID: %d\n", w->items[i].id);
            printf("Name: %s\n", w->items[i].name);
            printf("Quantity: %d\n", w->items[i].quantity);
        }
    }
}

int main() {
    Warehouse warehouses[MAX_WAREHOUSES];
    int numWarehouses = 0;
    char choice;

    do {
        printf("Warehouse Management System\n");
        printf("A. Add warehouse\n");
        printf("B. Add item to warehouse\n");
        printf("C. Print warehouse\n");
        printf("D. Exit\n");
        printf("Enter choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case 'A':
                printf("Enter warehouse ID: ");
                scanf("%d", &warehouses[numWarehouses].id);
                printf("Enter warehouse name: ");
                scanf("%s", warehouses[numWarehouses].name);
                numWarehouses++;
                break;
            case 'B':
                printf("Enter warehouse ID: ");
                scanf("%d", &warehouses[numWarehouses-1].id);
                printf("Enter item ID: ");
                scanf("%d", &warehouses[numWarehouses-1].items[0].id);
                printf("Enter item name: ");
                scanf("%s", warehouses[numWarehouses-1].items[0].name);
                printf("Enter item quantity: ");
                scanf("%d", &warehouses[numWarehouses-1].items[0].quantity);
                break;
            case 'C':
                printf("Enter warehouse ID: ");
                scanf("%d", &warehouses[numWarehouses-1].id);
                printWarehouse(&warehouses[numWarehouses-1]);
                break;
            case 'D':
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}