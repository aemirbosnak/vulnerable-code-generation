//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct menu_item {
    char name[50];
    int price;
    struct menu_item *next;
};

struct ordered_item {
    char name[50];
    int quantity;
    int price;
    struct ordered_item *next;
};

struct menu_item *head_menu = NULL;
struct ordered_item *head_ordered = NULL;

void add_menu_item(char name[], int price) {
    struct menu_item *new_item = (struct menu_item*)malloc(sizeof(struct menu_item));
    strcpy(new_item->name, name);
    new_item->price = price;
    new_item->next = NULL;

    if (head_menu == NULL) {
        head_menu = new_item;
    } else {
        struct menu_item *temp_menu = head_menu;
        while (temp_menu->next != NULL) {
            temp_menu = temp_menu->next;
        }
        temp_menu->next = new_item;
    }
}

void display_menu() {
    printf("\n*****************************************\n");
    printf("                 MENU\n");
    printf("*****************************************\n");
    struct menu_item *temp_menu = head_menu;
    while (temp_menu != NULL) {
        printf(" %s\t\t%d\n", temp_menu->name, temp_menu->price);
        temp_menu = temp_menu->next;
    }
}

void add_to_order(char name[], int quantity) {
    struct menu_item *temp_menu = head_menu;
    while (temp_menu != NULL) {
        if (strcmp(temp_menu->name, name) == 0) {
            struct ordered_item *new_order = (struct ordered_item*)malloc(sizeof(struct ordered_item));
            strcpy(new_order->name, name);
            new_order->quantity = quantity;
            new_order->price = temp_menu->price * quantity;
            new_order->next = NULL;

            if (head_ordered == NULL) {
                head_ordered = new_order;
            } else {
                struct ordered_item *temp_ordered = head_ordered;
                while (temp_ordered->next != NULL) {
                    temp_ordered = temp_ordered->next;
                }
                temp_ordered->next = new_order;
            }
            printf("\n%s added to the order.\n", name);
            return;
        }
        temp_menu = temp_menu->next;
    }
    printf("\n%s not found in the menu.\n", name);
}

void remove_from_order(char name[], int quantity) {
    struct ordered_item *temp_ordered = head_ordered;
    struct ordered_item *prev_ordered = NULL;
    while (temp_ordered != NULL) {
        if (strcmp(temp_ordered->name, name) == 0) {
            if (quantity >= temp_ordered->quantity) {
                // remove the entire item from the order
                if (prev_ordered == NULL) {
                    head_ordered = head_ordered->next;
                } else {
                    prev_ordered->next = temp_ordered->next;
                }
                free(temp_ordered);
                printf("\n%s removed from the order.\n", name);
                return;
            } else {
                // remove only the specified quantity from the item in the order
                temp_ordered->quantity -= quantity;
                temp_ordered->price -= quantity * temp_ordered->price / (temp_ordered->quantity + quantity);
                printf("\n%d %s removed from the order.\n", quantity, name);
                return;
            }
        }
        prev_ordered = temp_ordered;
        temp_ordered = temp_ordered->next;
    }
    printf("\n%s not found in the order.\n", name);
}

void display_order() {
    printf("\n*****************************************\n");
    printf("                 ORDER\n");
    printf("*****************************************\n");
    struct ordered_item *temp_ordered = head_ordered;
    while (temp_ordered != NULL) {
        printf(" %s\t\t%d x %d = %d\n", temp_ordered->name, temp_ordered->quantity, temp_ordered->price / temp_ordered->quantity, temp_ordered->price);
        temp_ordered = temp_ordered->next;
    }
}

int calculate_total() {
    int total = 0;
    struct ordered_item *temp_ordered = head_ordered;
    while (temp_ordered != NULL) {
        total += temp_ordered->price;
        temp_ordered = temp_ordered->next;
    }
    return total;
}

int main() {
    add_menu_item("Coffee", 50);
    add_menu_item("Tea", 30);
    add_menu_item("Cake", 100);
    add_menu_item("Sandwich", 70);

    int option, quantity;
    char name[50];

    printf("Welcome to Shape Shifting Cafe!\n");

    do {
        printf("\nOptions:\n");
        printf(" 1. Display Menu\n");
        printf(" 2. Add Item to Order\n");
        printf(" 3. Remove Item from Order\n");
        printf(" 4. Display Order\n");
        printf(" 5. Calculate Total\n");
        printf(" 6. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                display_menu();
                break;
            case 2:
                printf("\nEnter the name of the item you want to add to the order: ");
                scanf("%s", name);
                printf("Enter the quantity of %s you want to add to the order: ", name);
                scanf("%d", &quantity);
                add_to_order(name, quantity);
                break;
            case 3:
                printf("\nEnter the name of the item you want to remove from the order: ");
                scanf("%s", name);
                printf("Enter the quantity of %s you want to remove from the order: ", name);
                scanf("%d", &quantity);
                remove_from_order(name, quantity);
                break;
            case 4:
                display_order();
                break;
            case 5:
                printf("\nThe total is: %d\n", calculate_total());
                break;
            case 6:
                printf("\nThank you for visiting Shape Shifting Cafe!\n");
                break;
            default:
                printf("\nInvalid option!\n");
        }
    } while (option != 6);

    return 0;
}