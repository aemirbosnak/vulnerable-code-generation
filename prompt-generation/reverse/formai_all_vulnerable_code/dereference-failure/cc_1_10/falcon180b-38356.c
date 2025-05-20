//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int quantity;
    float price;
} Item;

void add_item(Item *items, int *size) {
    char name[MAX_SIZE];
    printf("Enter item name: ");
    scanf("%s", name);
    strcpy(items[*size].name, name);
    printf("Enter item quantity: ");
    scanf("%d", &items[*size].quantity);
    printf("Enter item price: ");
    scanf("%f", &items[*size].price);
    (*size)++;
}

void display_items(Item *items, int size) {
    printf("\nItem List:\n");
    for (int i = 0; i < size; i++) {
        printf("Name: %s\n", items[i].name);
        printf("Quantity: %d\n", items[i].quantity);
        printf("Price: $%.2f\n\n", items[i].price);
    }
}

void calculate_total_cost(Item *items, int size, float *total_cost) {
    for (int i = 0; i < size; i++) {
        (*total_cost) += items[i].quantity * items[i].price;
    }
}

int main() {
    Item items[MAX_SIZE];
    int size = 0;
    float total_cost = 0.0;

    printf("Welcome to the Warehouse Management System!\n\n");
    printf("Enter 1 to add an item\n");
    printf("Enter 2 to display item list\n");
    printf("Enter 3 to calculate total cost\n");
    printf("Enter 4 to exit\n");

    int choice;
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(items, &size);
                break;
            case 2:
                display_items(items, size);
                break;
            case 3:
                calculate_total_cost(items, size, &total_cost);
                printf("\nTotal cost: $%.2f\n", total_cost);
                break;
            case 4:
                printf("Thank you for using the Warehouse Management System!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}