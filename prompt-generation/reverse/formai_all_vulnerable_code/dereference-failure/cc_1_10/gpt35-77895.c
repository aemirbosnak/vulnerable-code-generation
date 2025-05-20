//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct menu {
    char item[50];
    int price;
};

struct order {
    char item[50];
    int quantity;
    struct order *next;
};

typedef struct menu Menu;
typedef struct order Order;

Menu cafe_menu[10] = {{"Espresso", 100}, {"Cappuccino", 120}, {"Latte", 150}, {"Americano", 110}, {"Mocha", 170}, {"Iced Coffee", 160}, {"Hot Chocolate", 140}, {"Croissant", 80}, {"Muffin", 60}, {"Sandwich", 120}};
Order *head = NULL;

void display_menu() {
    printf("\nMenu\n");
    printf("-----------------------------------------------------\n");
    printf("|   Item                          |   Price (in Rs)   |\n");
    printf("-----------------------------------------------------\n");
    for(int i=0; i<10; i++) {
        printf("|   %-30s   |   %-15d |\n", cafe_menu[i].item, cafe_menu[i].price);
    }
    printf("-----------------------------------------------------\n");
}

void add_order(char item[], int quantity) {
    Order *new_order = (Order*)malloc(sizeof(Order));
    strcpy(new_order->item, item);
    new_order->quantity = quantity;
    new_order->next = NULL;
    if(head == NULL) {
        head = new_order;
    } else {
        Order *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_order;
    }
}

void display_orders() {
    printf("\nOrders\n");
    printf("--------------------------------------------------\n");
    printf("|   Item                      |   Quantity        |\n");
    printf("--------------------------------------------------\n");
    Order *temp = head;
    while(temp != NULL) {
        printf("|   %-26s |   %-15d  |\n", temp->item, temp->quantity);
        temp = temp->next;
    }
    printf("--------------------------------------------------\n");
}

int calculate_total() {
    int total = 0;
    Order *temp = head;
    while(temp != NULL) {
        for(int i=0; i<10; i++) {
            if(strcmp(temp->item, cafe_menu[i].item) == 0) {
                total += (cafe_menu[i].price * temp->quantity);
                break;
            }
        }
        temp = temp->next;
    }
    return total;
}

void generate_bill() {
    printf("\nBill\n");
    printf("--------------------------------------------------\n");
    printf("|   Item                      |   Quantity        |\n");
    printf("--------------------------------------------------\n");
    Order *temp = head;
    while(temp != NULL) {
        printf("|   %-26s |   %-15d  |\n", temp->item, temp->quantity);
        temp = temp->next;
    }
    printf("--------------------------------------------------\n");
    printf("|   Total                     |   %-15d  |\n", calculate_total());
    printf("--------------------------------------------------\n");
}

int main() {
    int choice, quantity;
    char item[50];
    do {
        printf("\n1. Display Menu\n2. Add Order\n3. Display Orders\n4. Generate Bill\n5. Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: display_menu();
                    break;
            case 2: printf("\nEnter item: ");
                    scanf(" %[^\n]s", item);
                    printf("Enter quantity: ");
                    scanf("%d", &quantity);
                    add_order(item, quantity);
                    printf("\nOrder added successfully!\n");
                    break;
            case 3: display_orders();
                    break;
            case 4: generate_bill();
                    break;
            case 5: break;
            default: printf("\nInvalid choice!\n");
        }
    } while(choice != 5);
    return 0;
}