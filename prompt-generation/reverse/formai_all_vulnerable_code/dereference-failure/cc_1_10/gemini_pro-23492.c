//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

typedef struct {
    char name[50];
    float price;
} Menu;

#define MAX_ITEMS 100
#define MAX_MENU_ITEMS 100

Item items[MAX_ITEMS];
Menu menu_items[MAX_MENU_ITEMS];
int num_items = 0;
int num_menu_items = 0;

void load_menu() {
    FILE *fp = fopen("menu.txt", "r");
    if (fp == NULL) {
        perror("Error opening menu file");
        exit(1);
    }

    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        char *name = strtok(line, ",");
        char *price = strtok(NULL, ",");
        float fprice = atof(price);

        strcpy(menu_items[num_menu_items].name, name);
        menu_items[num_menu_items].price = fprice;

        num_menu_items++;
    }

    fclose(fp);
}

void add_item(char *name, int quantity, float price) {
    strcpy(items[num_items].name, name);
    items[num_items].quantity = quantity;
    items[num_items].price = price;

    num_items++;
}

void print_items() {
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s %d %f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void print_menu() {
    printf("Menu:\n");
    for (int i = 0; i < num_menu_items; i++) {
        printf("%s %f\n", menu_items[i].name, menu_items[i].price);
    }
}

void take_order() {
    char name[50];
    int quantity;
    float price;

    printf("Enter item name: ");
    scanf("%s", name);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    printf("Enter price: ");
    scanf("%f", &price);

    add_item(name, quantity, price);
}

void calculate_bill() {
    float total = 0.0;

    for (int i = 0; i < num_items; i++) {
        total += items[i].quantity * items[i].price;
    }

    printf("Total: %f\n", total);
}

int main() {
    load_menu();

    int choice;

    do {
        printf("1. Add item\n");
        printf("2. Print items\n");
        printf("3. Print menu\n");
        printf("4. Calculate bill\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                take_order();
                break;
            case 2:
                print_items();
                break;
            case 3:
                print_menu();
                break;
            case 4:
                calculate_bill();
                break;
            case 5:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}