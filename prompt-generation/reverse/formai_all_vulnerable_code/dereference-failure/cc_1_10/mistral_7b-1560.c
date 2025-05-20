//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float price;
} Item;

void add_item(Item** menu, char* name, float price) {
    Item* new_item = (Item*) malloc(sizeof(Item));
    strcpy(new_item->name, name);
    new_item->price = price;
    *menu = (Item*) realloc(*menu, sizeof(Item) * (sizeof(*menu) / sizeof(Item) + 1));
    (*menu)[sizeof(*menu) / sizeof(Item) - 1] = *new_item;
}

void print_menu(Item* menu, int num_items) {
    printf("\n-------- MENU --------\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - %.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("\n--------- ORDER ---------\n");
}

void order_item(Item* menu, int num_items, float* total, int* num_items_ordered) {
    char name[50];
    int choice;
    float price;

    printf("Enter the number of the item you'd like to order: ");
    scanf("%d", &choice);

    if (choice > num_items || choice < 0) {
        printf("Invalid choice. Please try again.\n");
        return;
    }

    strcpy(name, menu[choice - 1].name);
    price = menu[choice - 1].price;

    (*total) += price;
    (*num_items_ordered)++;

    printf("%s (%.2f) added to your order.\n", name, price);
}

int main() {
    Item* menu = NULL;

    add_item(&menu, "Espresso", 2.50);
    add_item(&menu, "Cappuccino", 3.00);
    add_item(&menu, "Latte", 3.50);
    add_item(&menu, "Mocha", 3.75);
    add_item(&menu, "Americano", 3.25);

    int num_items = sizeof(menu) / sizeof(Item);
    float total = 0.0;
    int num_items_ordered = 0;

    while (num_items_ordered < 3) {
        print_menu(menu, num_items);
        order_item(menu, num_items, &total, &num_items_ordered);
    }

    printf("\n-------- YOUR ORDER ---------\n");
    printf("Total: %.2f\n", total);

    printf("\n--------------- THANK YOU ---------------\n");
    printf("For choosing our cafe. We're grateful for your business!\n");

    free(menu);

    return 0;
}